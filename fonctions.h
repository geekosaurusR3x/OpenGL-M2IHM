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
#include <fstream>

#include "jpeg_exception.h"

#include <jpeglib.h>
#include <jerror.h>

unsigned char * loadJpegImage(std::string fichie, jpeg_decompress_struct *cinfo);

void loadJpegTexture(std::string fichie, int numtext);
void setTexture(unsigned char *image,int width,int height,int numtext);

float RandFloat(float start, float end);
void extractOBJdata(std::string file, float positions[][3], float texels[][2], float normals[][3], int faces[][9]);
#endif // FONCTIONS_H
