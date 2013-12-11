#include "cam_free.h"

CamFree::CamFree(double x, double y, double z)
{
	position = Vector3D(x,y,z);
    angle_vertical = 0;
    angle_horizontal = 0;
	mouse_sensibilite = 0.003;
	keyboard_sensibilite = 1.5;
    VectorsFromAngles();
}

CamFree::~CamFree()
{
}

void CamFree::VectorsFromAngles()
{
    static const Vector3D up(0,1,0);
	if (angle_horizontal > 30)
        angle_horizontal = 30;
    else if (angle_horizontal < -30)
        angle_horizontal = -30;
    double r_temp = cos(angle_vertical*M_PI/180);
    forward.Z = sin(angle_vertical*M_PI/180);
    forward.X = r_temp*cos(angle_horizontal*M_PI/180);
    forward.Y = r_temp*sin(angle_horizontal*M_PI/180);
    left = up.crossProduct(forward);
    left.normalize();

    target = position + forward;
}


void CamFree::OnMouseMotion(int x, int y)
{
    angle_vertical += x*mouse_sensibilite;
    angle_horizontal += y*mouse_sensibilite;
    VectorsFromAngles();
}
void CamFree::Draw()
{
    gluLookAt(position.X,position.Y,position.Z,target.X,target.Y,target.Z, 0,1,0);
}

void CamFree::Avancer()
{
	position += forward*keyboard_sensibilite;
	target = position + forward;
}

void CamFree::Reculer()
{
	position -= forward*keyboard_sensibilite;
	target = position + forward;
}


void CamFree::Droite()
{
	position -=left*keyboard_sensibilite;
	target = position + forward;
}

void CamFree::Gauche()
{
	position +=left*keyboard_sensibilite;
	target = position + forward;
}

void CamFree::SetY(double Y)
{
	position.Y=Y+4;
	target = position + forward;
}

double CamFree::GetX()
{
	return position.X;
}

double CamFree::GetZ()
{
	return position.Z;
}

double CamFree::GetY()
{
	return position.Y;
}
