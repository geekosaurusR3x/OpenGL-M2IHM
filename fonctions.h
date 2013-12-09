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
void setTextureAlpha(unsigned char *image,int width,int height,int numtext);

float RandFloat(float start, float end);

void GetModel3DInfo(std::string file,int &positions, int &texels, int &normals, int &faces, int &vertices);
void LoadModel3D(std::string file, float *positions, float *texels, float *normals, short *faces);
#endif // FONCTIONS_H
