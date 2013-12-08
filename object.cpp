#include "object.h"

Object::Object()
{
}
Object::Object(double X, double Y, double Z,double Size)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
	this->debug = false;
	this->Data_Dir	 = "";
	this->size = Size;
}
Object::~Object()
{
}

void Object::Draw()
{
}

void Object::Load()
{
}
