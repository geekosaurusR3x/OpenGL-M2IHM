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
	this->display_list = false;
	this->texture = false;
	this->model3D = false;
	this->Data_Dir	 = "";
	this->size = Size;
	this->color = noir;
	mylog = Loger::getInstance();
}
Object::~Object()
{
	if(display_list)
	{
		glDeleteLists(id_display_list,1);
	}
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
		this->mylog->Append(e.what());
	}
}

void Object::LoadInfoObject(std::string name)
{
	this->mylog->Append("Recuperation des infos du model 3D...");
	try
	{
		GetModel3DInfo(this->Data_Dir+"/Models/"+name+".obj",this->nb_position,this->nb_textels,this->nb_normals,this->nb_faces,this->nb_verticles);
	}
	catch (const jpeg_load_exception &e)
	{
		this->mylog->Append(e.what());
	}
	this->mylog->Append("Recuperation des infos du model 3D FINIT");
	this->mylog->Append("Model Info");
	this->mylog->Append("Positions: ");
	this->mylog->Append("Texels: "+to_string(this->nb_textels));
	this->mylog->Append("Normals: "+to_string(this->nb_normals));
	this->mylog->Append("Faces: "+to_string(this->nb_faces));
	this->mylog->Append("Vertices: "+to_string(this->nb_verticles));
}

void Object::LoadDataObject(std::string name)
{
	//alocation des differantes tableaux necessaires
	positions_vertex = new float [this->nb_position*3];

	texels = new float [this->nb_textels*2];

	normals = new float [this->nb_normals*3];

	faces = new short [nb_verticles];

	//fin de l'alocation des tableaux
	this->mylog->Append("Chargement du model 3D...");
	try
	{
		LoadModel3D(this->Data_Dir+"/Models/"+name+".obj",this->positions_vertex,this->texels,this->normals,this->faces);
	}
	catch (const jpeg_load_exception &e)
	{
		this->mylog->Append(e.what());
	}
	this->mylog->Append("Chargement du model 3D FINIT");
	this->mylog->Append("Model Data :");
	for(int i=0; i<nb_position; i++)
	{
		//this->mylog->Append("P"+to_string(i+1)+": "+to_string(positions_vertex[i])+"x "+to_string(positions_vertex[i+1])+"y "+to_string(positions_vertex[i+2])+"z");
	}
	for(int i=0; i<nb_textels; i++)
	{
		//this->mylog->Append("T"+to_string(i+1)+": "+to_string(texels[i])+"u "+to_string(texels[i+1])+"v ");
	}
	for(int i=0; i<nb_normals; i++)
	{
		//this->mylog->Append("N"+to_string(i+1)+": "+to_string(normals[i])+"x "+to_string(normals[i+1])+"y "+to_string(normals[i+2])+"z ");
	}
	for(int i=0; i<nb_faces; i++)
	{
		//this->mylog->Append("F"+to_string(i+1)+": "+to_string(faces[i])+"P1 "+to_string(faces[i+1])+"P2 "+to_string(faces[i+2])+"P3");
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
