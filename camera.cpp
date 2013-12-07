#include "camera.h"

MyCamera::MyCamera()
{
  this->Rotate_Cam=false;
  this->angle_cam = 180.0;
  this->rayon_rotation = 450.0;
  this->camY = 200.0;
  this->flecheY = this->camY;
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
  
  this->camX = 0 + this->rayon_rotation*cos(this->angle_cam);
  this->camZ = 0 + this->rayon_rotation*sin(this->angle_cam);
  
  this->flecheX = 0 + (this->rayon_rotation-1.5)*cos(this->angle_cam);
  this->flecheZ = 0 + (this->rayon_rotation-1.5)*sin(this->angle_cam);
  
  gluLookAt (this->camX,this->camY,this->camZ, 0,90.0,0,0.0,1.0,0.0);
}

void MyCamera::TogleRotate()
{
  this->Rotate_Cam=!this->Rotate_Cam;
}