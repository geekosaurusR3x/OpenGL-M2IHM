#ifndef CAMFREE_H
#define CAMFREE_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>
#include "vector3d.h"
class CamFree
{
public:
	CamFree(double x, double y, double z);
	~CamFree();
	void Draw();
	void OnMouseMotion(int x, int y);
	void Avancer();
	void Reculer();
	void Droite();
	void Gauche();
	void SetY(double Y);
	double GetX();
	double GetZ();
	double GetY();

private :
	Vector3D position;
	Vector3D target;
	Vector3D forward;
	Vector3D left;
	double angle_vertical;
	double angle_horizontal;
	double mouse_sensibilite;
	double keyboard_sensibilite;
	void VectorsFromAngles();
};

#endif // CAMFREE_H
