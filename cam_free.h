#ifndef CAMFREE_H
#define CAMFREE_H
#include "camera.h"

class CamFree: public Camera
{
public:
	CamFree();
	CamFree(double x, double y, double z);
	~CamFree();
	void OnMouseMotion(int x, int y);
	void Avancer();
	void Reculer();
	void Droite();
	void Gauche();
	void UpdateChild();

private :
	Vector3D forward;
	Vector3D left;
	double angle_vertical;
	double angle_horizontal;
	double mouse_sensibilite;
	double keyboard_sensibilite;
	void VectorsFromAngles();
};

#endif // CAMFREE_H
