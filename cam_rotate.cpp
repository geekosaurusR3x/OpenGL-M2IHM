#include "cam_rotate.h"

CamRotate::CamRotate()
{
	CamRotate(0,0,0);
}
CamRotate::CamRotate(double x, double y, double z):Camera(x,y,z)
{
	this->Rotate_Cam=false;
	this->angle_cam = 180.0;
	this->rayon_rotation = 200.0;
	this->target.X = 0;
	this->target.Y = 90;
	this->target.Z = 0;
}

CamRotate::~CamRotate()
{
}

void CamRotate::TogleRotate()
{
  this->Rotate_Cam=!this->Rotate_Cam;
}

void CamRotate::UpdateChild()
{
   if (this->Rotate_Cam)
  {
    this->angle_cam += 0.01;
    this->angle_cam = fmod(this->angle_cam,360.0);
  }
  this->position.X = 0 + this->rayon_rotation*cos(this->angle_cam);
  this->position.Z = 0 + this->rayon_rotation*sin(this->angle_cam);
}
