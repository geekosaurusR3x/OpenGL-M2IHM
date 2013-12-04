#ifndef CAMERA_H
#define CAMERA_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <math.h>


class MyCamera
{
public:
	MyCamera();
	~MyCamera();
	void TogleRotate();
	void PositonCamera(double xCentre, double zCentre);

	bool IsRotateCam() const {
		return Rotate_Cam;
	}


	double GetFlecheX() const {
		return flecheX;
	}
	double GetFlecheY() const {
		return flecheY;
	}
	double GetFlecheZ() const {
		return flecheZ;
	}
private:
	bool Rotate_Cam;
	double angle_cam;
	double rayon_rotation;
	double camX;
	double camY;
	double camZ;
	double flecheX;
	double flecheY;
	double flecheZ;

};

#endif // CAMERA_H
