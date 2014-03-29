[Watch a video demo](http://youtu.be/8YNk2UNqWzo)

Color cycling is a nifty technique from the days of yore for creating animations.
The key idea of color cycling is to modify the color palette an image uses rather than the image itself.
Since each pixel on the screen is refers to some color in the palette, it's possible to change many pixels at once by modifying the palette.
This takes much less time than redrawing the screen because the palette is significantly smaller than the video buffer itself.

In this demo the palette is rotated every screen refresh:

    palette[1] <- palette[2] ... <- palette[255]
        \_______________________________^
