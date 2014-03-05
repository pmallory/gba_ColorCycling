
//{{BLOCK(mandelbrot)

//======================================================================
//
//	mandelbrot, 240x160@8, 
//	+ palette 256 entries, not compressed
//	+ bitmap not compressed
//	Total size: 512 + 38400 = 38912
//
//	Time-stamp: 2014-03-04, 23:03:50
//	Exported by Cearn's GBA Image Transmogrifier, v0.8.3
//	( http://www.coranac.com/projects/#grit )
//
//======================================================================

#ifndef GRIT_MANDELBROT_H
#define GRIT_MANDELBROT_H

#define mandelbrotBitmap1Len 38400
extern const unsigned short mandelbrotBitmap1[19200];

#define mandelbrotBitmap2Len 38400
extern const unsigned short mandelbrotBitmap2[19200];

#define mandelbrotPalLen1 512
extern const unsigned short mandelbrotPal1[256];

#define mandelbrotPalLen2 512
extern const unsigned short mandelbrotPal2[256];

#endif // GRIT_MANDELBROT_H

//}}BLOCK(mandelbrot)
