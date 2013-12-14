#include "bug_droid.h"

using namespace std;

BugDroid::BugDroid()
{
	BugDroid(0,0,0,1);
}

BugDroid::~BugDroid()
{
}

BugDroid::BugDroid(double X, double Y, double Z, double Size):Object(X,Y,Z,Size)
{
	this->nb_position=0;
	this->nb_textels=0;
	this->nb_normals=0;
	this->nb_faces=0;
	this->nb_verticles=0;
	this->name = "bugdroid";
	this->color = vert;
	this->model3D = true;
}


void BugDroid::LoadChild()
{
	this->mylog->Append("Chargement du model 3D : "+this->name);
	LoadInfoObject(this->name);
	LoadDataObject(this->name);

}
