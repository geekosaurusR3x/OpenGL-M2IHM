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
}


void BugDroid::Load()
{
	if (debug){cout<<"Recuperation des infos du model 3D..."<<endl;}
	try
	{
		GetModel3DInfo(this->Data_Dir+"/Models/"+this->name+".obj",this->nb_position,this->nb_textels,this->nb_normals,this->nb_faces,this->nb_verticles);
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}
	if (debug)
	{
		cout<<"Recuperation des infos du model 3D FINIT"<<endl;
		cout << "Model Info" << endl;
		cout << "Positions: " << this->nb_position << endl;
		cout << "Texels: " << this->nb_textels << endl;
		cout << "Normals: " << this->nb_normals << endl;
		cout << "Faces: " << this->nb_faces << endl;
		cout << "Vertices: " << this->nb_verticles << endl;
	}

	//alocation des differantes tableaux necessaires
	positions = new float [this->nb_position*3];

	texels = new float [this->nb_textels*2];

	normals = new float [this->nb_normals*3];

	faces = new short [nb_verticles];

	//fin de l'alocation des tableaux
	if (debug){cout<<"Chargement du model 3D..."<<endl;}
	try
	{
		LoadModel3D(this->Data_Dir+"/Models/"+this->name+".obj",this->positions,this->texels,this->normals,this->faces);
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}
	if (debug)
	{
		cout<<"Chargement du model 3D FINIT"<<endl;
		cout << "Model Data" << endl;
		for(int i=0; i<nb_position; i++)
		{
			cout << "P"<<i+1<<": " << positions[i] << "x " << positions[i+1] << "y " << positions[i+2] << "z" << endl;
		}
		for(int i=0; i<nb_textels; i++)
		{
			cout << "T"<<i+1<<": " << texels[i] << "u " << texels[i+1] << "v " << endl;
		}
		for(int i=0; i<nb_normals; i++)
		{
			cout << "N"<<i+1<<": " << normals[i] << "x " << normals[i+1] << "y "<<normals[i+2]<<"z "<< endl;
		}
		for(int i=0; i<nb_faces; i++)
		{
			cout << "F"<<i+1<<": " << faces[i] << "P1 " << faces[i+1] << "P2 " << faces[i+2] << "P3" << endl;
		}
	}

}

void BugDroid::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, positions);
	glColor4dv(vert);
	glPushMatrix();
		glTranslated(this->x,this->y,this->z);
		glScalef(this->size/4, this->size/4, this->size/4);
		glTranslated(0,3,0);
		glDrawElements(GL_TRIANGLES, ((this->nb_faces) * 3), GL_UNSIGNED_SHORT, faces);
	glPopMatrix();
	glDisableClientState(GL_VERTEX_ARRAY);
}
