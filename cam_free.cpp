#include "cam_free.h"

CamFree::CamFree()
{
	CamFree(0,0,0);
}

CamFree::CamFree(double x, double y, double z):Camera(x,y,z)
{
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

	UpdateChild();
}


void CamFree::OnMouseMotion(int x, int y)
{
    angle_vertical -= x*mouse_sensibilite;
    angle_horizontal += y*mouse_sensibilite;
    VectorsFromAngles();
}

void CamFree::Avancer()
{
	position += forward*keyboard_sensibilite;
	UpdateChild();
}

void CamFree::Reculer()
{
	position -= forward*keyboard_sensibilite;
	UpdateChild();
}


void CamFree::Droite()
{
	position -=left*keyboard_sensibilite;
	UpdateChild();
}

void CamFree::Gauche()
{
	position +=left*keyboard_sensibilite;
	UpdateChild();
}

void CamFree::UpdateChild()
{
	target = position + forward;
	CalculPosFleche();
}
