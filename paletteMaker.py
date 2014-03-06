import math

def rgb2HTMLColor(red, green, blue):
    return "{0:02x}{1:02x}{2:02x}".format(int(red), int(green), int(blue))

def rgb2CColor(red, green, blue):
    color = int(blue)<<10 | int(green)<<5 | int(red)
    return "{0:02x}".format(color)

def makeGradient(freq1, freq2, freq3,
                 phase1, phase2, phase3,
                 center=128, width=127, length=50, outformat='html'):
    """
    adapted from http://krazydad.com/tutorials/makecolors.php
    """
    with open('pal.{}'.format(outformat), 'w') as f:
        f.write('')

    with open('pal.{}'.format(outformat), 'a') as f:
        for i in xrange(length):
            red = math.sin(freq1*i + phase1) * width + center
            green = math.sin(freq2*i + phase2) * width + center
            blue = math.sin(freq3*i + phase3) * width + center

            if outformat is 'html':
                f.write('<font color="#{}">&#9608;</font>'.format(rgb2HTMLColor(red, green, blue)))
            elif outformat is 'c':
                f.write('0x{},'.format(rgb2CColor(red, green, blue)))

#makeGradient(.05,.05,.05,0,0,0, center=128, width=127, length=255)
makeGradient(.05,.05,.05,0,0,0, center=16, width=15, length=255, outformat='c')
