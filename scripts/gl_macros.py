#!/usr/bin/env python

from operator import itemgetter
from urllib2 import urlopen

glcorearb = 'http://www.opengl.org/registry/api/GL/glcorearb.h'

header = urlopen(glcorearb)
data = header.read()
data = data.replace("const GLubyte", "constGLubyte")

lines = [l.split() for l in data.split('\n') if l.startswith("GLAPI")]
lines.sort(key = itemgetter(3))

for tokens in lines:
  return_type = tokens[1]
  if return_type == "constGLubyte":
    return_type = "const GLubyte *"

  method = tokens[3][2:]

  output_template = "GXY_{type}_GL({M}, {m},{ethod}" + (", {return_type})" if return_type != "void" else ")")
  print output_template.format(
    type = "VOID" if return_type == "void" else "AUTO",
    M = method[0],
    m = method[0].lower(),
    ethod = method[1:],
    return_type = return_type)
