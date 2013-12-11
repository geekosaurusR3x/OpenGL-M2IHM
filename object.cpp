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
	this->Data_Dir	 = "";
	this->size = Size;
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
	else
	{
		DrawChild();
	}
}

void Object::Load()
{
	id_texture = new GLuint[nbtexture];
	glGenTextures(nbtexture, id_texture);
	LoadChild();
	if(display_list)
	{
		id_display_list = glGenLists(1);
		glNewList(display_list, GL_COMPILE);
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
