#include "object.h"

using namespace std;

Object::Object()
{
}
Object::Object(double X, double Y, double Z,double Size)
{
	this->x = X;
	this->y = Y;
	this->z = Z;
	this->debug = false;
	this->display_list = false;
	this->texture = false;
	this->model3D = false;
	this->Data_Dir	 = "";
	this->size = Size;
	this->color = noir;
}
Object::~Object()
{
}

void Object::Draw()
{
	if(display_list)
	{
		glCallList(id_display_list);
	}
	else if(model3D)
	{
		DrawObject();
	}
	else
	{
		DrawChild();
	}
}

void Object::Load()
{
	if(texture)
	{
		id_texture = new GLuint[nbtexture];
		glGenTextures(nbtexture, id_texture);
	}
	LoadChild();
	if(display_list)
	{
		id_display_list = glGenLists(1);
		if (debug){cout<<id_display_list<<endl;}
		glNewList(id_display_list, GL_COMPILE);
			DrawChild();
		glEndList();
	}
}

void Object::Update()
{
}

void Object::LoadChild()
{
}

void Object::DrawChild()
{
}

void Object::LoadTextureObject(std::string name, int num)
{
	try
	{
		loadJpegTexture(Data_Dir+"/Textures/"+name+".jpg",id_texture[num]); //left
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}
}

void Object::LoadInfoObject(std::string name)
{
	if (debug){cout<<"Recuperation des infos du model 3D..."<<endl;}
	try
	{
		GetModel3DInfo(this->Data_Dir+"/Models/"+name+".obj",this->nb_position,this->nb_textels,this->nb_normals,this->nb_faces,this->nb_verticles);
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
}

void Object::LoadDataObject(std::string name)
{
	//alocation des differantes tableaux necessaires
	positions_vertex = new float [this->nb_position*3];

	texels = new float [this->nb_textels*2];

	normals = new float [this->nb_normals*3];

	faces = new short [nb_verticles];

	//fin de l'alocation des tableaux
	if (debug){cout<<"Chargement du model 3D..."<<endl;}
	try
	{
		LoadModel3D(this->Data_Dir+"/Models/"+name+".obj",this->positions_vertex,this->texels,this->normals,this->faces);
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
			cout << "P"<<i+1<<": " << positions_vertex[i] << "x " << positions_vertex[i+1] << "y " << positions_vertex[i+2] << "z" << endl;
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

void Object::DrawObject()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(3, GL_FLOAT, 0, positions_vertex);
	glPushMatrix();
		glColor4dv(this->color);
		glTranslated(this->x,this->y,this->z);
		glScalef(this->size, this->size, this->size);
		glDrawElements(GL_TRIANGLES, ((this->nb_faces) * 3), GL_UNSIGNED_SHORT, faces);
	glPopMatrix();
	glDisableClientState(GL_VERTEX_ARRAY);
}
