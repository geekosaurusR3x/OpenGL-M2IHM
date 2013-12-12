#include "camera.h"

Camera::Camera()
{
}

Camera::Camera(double x, double y, double z)
{
	this->position = Vector3D(x,y,z);
}

Camera::~Camera()
{
}

void Camera::LookAt()
{
	gluLookAt(this->position.X,this->position.Y,this->position.Z,this->target.X,this->target.Y,this->target.Z, 0,1,0);
}

void Camera::CalculPosFleche()
{
	int d = 2;
	double dsurPC = d/sqrt(pow(this->position.X-this->target.X,2)+pow(this->position.Y-this->target.Y,2)+pow(this->position.Z-this->target.Z,2));
	double lamba1 = 1 - dsurPC;
	
	this->position_fleche.X = (lamba1*this->position.X)+((1-lamba1)*this->target.X);
	this->position_fleche.Y = (lamba1*this->position.Y)+((1-lamba1)*this->target.Y);
	this->position_fleche.Z = (lamba1*this->position.Z)+((1-lamba1)*this->target.Z);
}

void Camera::Update()
{
	UpdateChild();
	this->CalculPosFleche();
}

void Camera::UpdateChild()
{
}
