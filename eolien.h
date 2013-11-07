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
	Eolien();
	~Eolien();
	void Draw(double Wind,GLUquadric* params);

private:
	int pas;
};

#endif // EOLIEN_H
