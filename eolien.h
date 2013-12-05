#ifndef EOLIEN_H
#define EOLIEN_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Couleur.h"
class Eolien
{
public:
	Eolien(double x, double y, double z);
	~Eolien();
	void Draw(double Wind,double OrientationVent);

	void SetZoom(double Zoom) {
		this->Zoom = Zoom;
	}
private:
	int pas;
	double posx;
	double posy;
	double posz;
	double Zoom;
};

#endif // EOLIEN_H
