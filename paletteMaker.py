import math

def rgb2Color(red, green, blue):
    return "{0:02x}{1:02x}{2:02x}".format(int(red), int(green), int(blue))

def makeGradient(freq1, freq2, freq3,
                 phase1, phase2, phase3,
                 center=128, width=127, length=50):
    """
    adapted from http://krazydad.com/tutorials/makecolors.php
    """
    with open('out.html', 'w') as f:
        f.write('')

    with open('out.html', 'a') as f:
        for i in xrange(length):
            red = math.sin(freq1*i + phase1) * width + center
            green = math.sin(freq2*i + phase2) * width + center
            blue = math.sin(freq3*i + phase3) * width + center

            f.write('<font color="#{}">&#9608;</font>'.format(rgb2Color(red, green, blue)))

makeGradient(.04,.04,.04,0,2,4,128,127,150)
