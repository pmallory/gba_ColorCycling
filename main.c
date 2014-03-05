#include <stdlib.h>
#include "myLib.h"
#include "mandelbrot.h"

void shiftPalette();

typedef enum which { fractalOne, fractalTwo, paletteOne, paletteTwo } which_t;

int main()
{
	REG_DISPCTL = MODE4 | BG2_ENABLE;

    loadPalette(mandelbrotPal1);
	drawBackgroundImage4(mandelbrotBitmap1);

	which_t currentlyDrawing = fractalOne;
	which_t currentPalette = paletteOne;

	int buttons = BUTTONS;
	int oldButtons;

	while(1) {
		oldButtons = buttons;
		buttons = BUTTONS;

		if (BUTTON_PRESSED(BUTTON_START)) {
			if (currentlyDrawing == fractalOne) {
				currentlyDrawing = fractalTwo;
				drawBackgroundImage4(mandelbrotBitmap2);
			} else {
				currentlyDrawing = fractalOne;
				drawBackgroundImage4(mandelbrotBitmap1);
			}
		}

		if (BUTTON_PRESSED(BUTTON_SELECT)) {
			if (currentPalette == paletteOne) {
				currentPalette = paletteTwo;
				loadPalette(mandelbrotPal2);
			} else {
				currentPalette = paletteOne;
				loadPalette(mandelbrotPal1);
			}
		}

		shiftPalette();
		
		waitForVblank();
	}

	return 0;
}


void shiftPalette() {
	unsigned short color1 = PALETTE[1];

	int i;
	for (i=1; i<150; i++) {
		PALETTE[i] = PALETTE[i+1];
	}
	PALETTE[150] = color1;

}