#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <iostream>
#include "jpeg_exception.h"

#include <jpeglib.h>
#include <jerror.h>


void loadJpegImage(std::string fichie, int numtex);
