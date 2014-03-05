#include "myLib.h"
unsigned short *videoBuffer = (u16 *)0x6000000;

unsigned short *frontBuffer = (u16 *)0x6000000;
unsigned short *backBuffer =  (u16 *)0x600A000;

DMA *dma = (DMA *)0x40000B0;

void drawImage3(const unsigned short* image, int row, int col, int height, int width)
{
    int i;
    for(i = 0; i < height; i++)
    {
        DMANow(3,
            (unsigned short*)&image[OFFSET(i,0, width)],
            &videoBuffer[OFFSET(row+i, col, SCREENWIDTH)],
            (width));
    }
}

void setPixel4(int row, int col, unsigned char colorIndex)
{
	unsigned short pixels = videoBuffer[OFFSET(row, col/2, SCREENWIDTH/2)];

	if(col % 2 == 0) // even
	{
		pixels &= 0xFF << 8;
		videoBuffer[OFFSET(row, col/2, SCREENWIDTH/2)] = pixels | colorIndex;
	}
	else // odd
	{
		pixels &= 0xFF;
		videoBuffer[OFFSET(row, col/2, SCREENWIDTH/2)] = pixels | colorIndex << 8;
	}
}

void fillScreen4(unsigned char colorIndex)
{
	volatile unsigned short pixels = colorIndex << 8 | colorIndex;
	DMANow(3, &pixels, videoBuffer, ((240 * 160)/2) | DMA_SOURCE_FIXED);
}

void drawBackgroundImage3(const unsigned short* image) {
	DMANow(3, (unsigned short*)image, videoBuffer, ((240 * 160)));
}

void drawBackgroundImage4(const unsigned short* image)
{
	// TODO COMPLETE THIS FUNCTION !!!!
	// This function will be very similar to the fillScreen4 function
	// This funciton will fill the entire screen with the image
	// the image has to be 240x160px
	// Instead of using a color you will use data from an image

    // HINT: When you get to the count/control argument of DMANow,
    //       remeber that your copying 16 bits (ie two pixels) at a
    //       time. How does this affect how many copies you need to make?
    DMANow(3, (unsigned short*)image, videoBuffer, ((240 * 160)/2));
}

void drawImage4(const unsigned short* image, int row, int col, int height, int width)
{
	// TODO COMPLETE THIS FUNCTION !!!! (you must use DMA, not setPixel4)

	// This function is tricky because of 8-bit color vs 16 bit writabilty
	// There is an easy way to get over this issue:
	// Make it so no matter what we'll start drawing the image on an even col
	// also your images will have to have an even number of width i.e. 10 pixels wide
    if(col%2)
        col++;

    int r;
    for(r = 0; r < height; r++) {
        DMANow(3,
               (unsigned short*)&image[OFFSET(r,0,width/2)],
               &videoBuffer[OFFSET(row + r, col/2, SCREENWIDTH/2)],
               width/2);
    }
}

void loadPalette(const unsigned short* palette)
{
	// TODO COMPLETE THIS FUNCTION !!!!
	// This function will load copy a palette to GBA's palette memory
    // HINT: there's a #define near the top of myLIb.h that has the pallette's address
    DMANow(3, (unsigned short*)palette, PALETTE, 256);
}


void DMANow(int channel, volatile void* source, volatile void* destination, unsigned int control)
{
	dma[channel].src = source;
	dma[channel].dst = destination;
	dma[channel].cnt = DMA_ON | control;
}

void waitForVblank()
{
	while(SCANLINECOUNTER > 160);
	while(SCANLINECOUNTER < 160);
}



void flipPage()
{
    if(REG_DISPCTL & BUFFER2)
    {
        REG_DISPCTL &= ~BUFFER2;
        videoBuffer = backBuffer;
    }
    else
    {
        REG_DISPCTL |= BUFFER2;
        videoBuffer = frontBuffer;
    }
}

