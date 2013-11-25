#ifndef EOLIEN_H
#define EOLIEN_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Eolien
{
public:
	Eolien(double x, double y, double z);
	~Eolien();
	void Draw(double Wind,GLUquadric* params);

private:
	int pas;
	double posx;
	double posy;
	double posz;
};

#endif // EOLIEN_H
