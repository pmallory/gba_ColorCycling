import math

def rgb2Color(red, green, blue):
    color = int(blue)<<10 | int(green)<<5 | int(red)
    return "{0:02x}".format(color)

def makeGradient(freq1, freq2, freq3,
                 phase1, phase2, phase3,
                 center=128, width=127, length=50):
    """
    adapted from http://krazydad.com/tutorials/makecolors.php
    """
    with open('pal.c', 'w') as f:
        f.write('')

    with open('pal.c', 'a') as f:
        for i in xrange(length):
            red = math.sin(freq1*i + phase1) * width + center
            green = math.sin(freq2*i + phase2) * width + center
            blue = math.sin(freq3*i + phase3) * width + center

            f.write('0x{},'.format(rgb2Color(red, green, blue)))

makeGradient(.04,.04,.04,0,2,4,16,15,150)
