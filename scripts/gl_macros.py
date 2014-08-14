#!/usr/bin/env python

import urllib2

glcorearb = 'http://www.opengl.org/registry/api/GL/glcorearb.h'

header = urllib2.urlopen(glcorearb)
data = header.read()

for line in data.split('\n'):
  if line.startswith("GLAPI"):
    tokens = line.split(' ')

    return_type = tokens[1]
    method = tokens[4] if return_type == "const" else tokens[3]
    method = method[2:]

    output = "GXY_"
    output += "VOID" if return_type == "void" else "AUTO"
    output += "_GL(" + method[0] + ", " + method[0].lower() + "," + method[1:] + ")"

    print output
