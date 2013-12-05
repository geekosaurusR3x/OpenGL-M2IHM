#ifndef FONCTIONS_H
#define FONCTIONS_H

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

unsigned char * loadJpegImage(std::string fichie, jpeg_decompress_struct *cinfo);

void loadJpegTexture(std::string fichie, int numtex);

void loadJpegMap(std::string, float terran[32][32][3]);
#endif // FONCTIONS_H
