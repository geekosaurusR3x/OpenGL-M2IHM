#include "object.h"

Object::Object()
{
}
Object::Object(double X, double Y, double Z)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
	this->debug = false;
	this->Data_Dir	 = "";
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
