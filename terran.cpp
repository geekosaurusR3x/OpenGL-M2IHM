#include "terran.h"

using namespace std;
Terran::Terran()
{
		Terran(0,0,0,1);
}

Terran::Terran(double X,double Y,double Z,double Size):Object(X,Y,Z,SIZE_MAP)
{
}
Terran::~Terran()
{
}

void Terran::Load()
{
		glGenTextures(1, texture_terrain);
		LoadModelMap();
		LoadTextureMap(TEXTURE_MAP_1);
		GenDisplayList();
}
void Terran::Draw()
{
	glCallList(display_list);
}

void Terran::GenDisplayList()
{
	display_list = glGenLists(1);
	glNewList(display_list, GL_COMPILE);
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
		glBindTexture(GL_TEXTURE_2D, texture_terrain[0]);
		glBegin(GL_TRIANGLE_STRIP);
		for (int z = 0; z < this->size-1; z++)
		{
			for (int x = 0; x < this->size-1; x++)
			{
				glTexCoord2f(0.0f, 0.0f);
				glVertex3f(terrain[x][z][0], terrain[x][z][1], terrain[x][z][2]);

				// draw vertex 1
				glTexCoord2f(1.0f, 0.0f);
				glVertex3f(terrain[x+1][z][0],terrain[x+1][z][1],terrain[x+1][z][2]);

				// draw vertex 2
				glTexCoord2f(0.0f, 1.0f);
				glVertex3f(terrain[x][z+1][0],terrain[x][z+1][1],terrain[x][z+1][2]);

				// draw vertex 3
				glTexCoord2f(1.0f, 1.0f);
				glVertex3f(terrain[x+1][z+1][0],terrain[x+1][z+1][1],terrain[x+1][z+1][2]);

			}
		}
		glEnd(); 
		glDisable(GL_TEXTURE_2D);
	glEndList();
}

double Terran::GetHauteurPos(double X, double Z)
{
	int x = (X-this->x)/Map_Scale;
	int z = (-Z-this->z)/Map_Scale;
	return terrain[x][z][1];
}

void Terran::SetSizeWordl(double Size_Wordl)
{
	this->Size_Demi_Wordl = Size_Wordl/2;
	this->Map_Scale = Size_Wordl/this->size;
	if (debug){cout<<"Demi Wordl : "<<Size_Demi_Wordl<<" Map Scale : "<<Map_Scale<<endl;}
}

void Terran::LoadModelMap()
{
	unsigned char *map = 0;
	if (debug){cout<<"Generation du model map..."<<endl;}
	try
	{
		struct jpeg_decompress_struct cinfo;
		map = loadJpegImage(this->Data_Dir+"/Maps/map.jpg",&cinfo);
		for (int z = 0; z < this->size; z++)
		{
			for (int x = 0; x < this->size; x++)
			{
				terrain[x][z][0] = (double(x)*Map_Scale)+this->x;
				terrain[x][z][1] = (double)GetColorPixel(map,x,z,0);
				terrain[x][z][2] = -(double(z)*Map_Scale)+this->z;
			}

		}
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}
	free(map);
	if (debug){cout<<"Generation du model map FINIT"<<endl;}
}

void Terran::LoadTextureMap(int num)
{
	string name;
	if (num == TEXTURE_MAP_1)
	{
		name = TEXTURE_MAP_NAME_1;
	}
	else
	{
		name = TEXTURE_MAP_NAME_2;
	}
	
	if (debug){cout<<"Chargement de la texture de la map..."<<endl;}
	try
	{
		loadJpegTexture(this->Data_Dir+"/Textures/"+name+".jpg",texture_terrain[0]);
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}
	if (debug){cout<<"Chargement de la texture de la map FINIT"<<endl;}
}

int Terran::GetColorPixel(unsigned char * img, int x, int y,int pos)
{
        return img[((x*(int)this->size+y)*3+pos)];
}