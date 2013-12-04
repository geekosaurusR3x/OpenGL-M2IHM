#include "camera.h"

MyCamera::MyCamera()
{
	this->Rotate_Cam=false;
	this->angle_cam = 0.0;
	this->rayon_rotation = 30.0;
	this->camY = 10.0;
	this->flecheY = 10.0;
}

MyCamera::~MyCamera()
{
}

void MyCamera::PositonCamera(double xCentre, double zCentre)
{
	if (this->Rotate_Cam)
	{
		this->angle_cam += 0.01;
		this->angle_cam = fmod(this->angle_cam,360.0);
	}
	
	this->camX = xCentre + this->rayon_rotation*cos(this->angle_cam);
	this->camZ = zCentre + this->rayon_rotation*sin(this->angle_cam);
	
	this->flecheX = xCentre + (this->rayon_rotation-1.5)*cos(this->angle_cam);
	this->flecheZ = zCentre + (this->rayon_rotation-1.5)*sin(this->angle_cam);
	
	gluLookAt (this->camX,this->camY,this->camZ, xCentre,5.0,zCentre,0.0,1.0,0.0);
}

void MyCamera::TogleRotate()
{
	this->Rotate_Cam=!this->Rotate_Cam;
}
