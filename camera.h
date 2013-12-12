#ifndef CAMERA_H
#define CAMERA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "vector3d.h"
#include <math.h>

class Camera
{
public:
	Camera();
	Camera(double x, double y, double z);
	virtual ~Camera()=0;
	void LookAt();
	void Update();
	virtual void UpdateChild();
	
	double GetFlecheX() const {
		return position_fleche.X;
	}
	double GetFlecheY() const {
		return position_fleche.Y;
	}
	double GetFlecheZ() const {
		return position_fleche.Z;
	}
	
	double GetX() const {
		return position.X;
	}
	double GetY() const {
		return position.Y;
	}
	void SetY(double y) {
		position.Y = y;
	}
	double GetZ() const {
		return position.Z;
	}

protected:
	Vector3D position;
	Vector3D target;
	Vector3D position_fleche;
	
	void CalculPosFleche();
};

#endif // CAMERA_H
