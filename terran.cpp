#include "terran.h"

using namespace std;
Terran::Terran()
{
		Terran(0,0,0,1);
}

Terran::Terran(double X,double Y,double Z,double Size):Object(X,Y,Z,SIZE_MAP)
{
	nbtexture = 1;
	display_list = true;
	texture = true;
}
Terran::~Terran()
{
}

void Terran::LoadChild()
{
		LoadModelMap();
		LoadTexture(TEXTURE_MAP_1);
}

void Terran::DrawChild()
{
		glEnable(GL_TEXTURE_2D);
		glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
		glBindTexture(GL_TEXTURE_2D, id_texture[0]);
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
	this->mylog->Append("Demi Wordl : "+to_string(Size_Demi_Wordl)+" Map Scale : "+to_string(Map_Scale));
}

void Terran::LoadModelMap()
{
	unsigned char *map = 0;
	this->mylog->Append("Generation du model map...");
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
		this->mylog->Append(e.what());
	}
	free(map);
	this->mylog->Append("Generation du model map FINIT");
}

void Terran::LoadTexture(int num)
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
	
	this->mylog->Append("Chargement Texture Map : "+name+" Numero :"+to_string(num));
	this->mylog->Append("Chargement de la texture de la map...");
	LoadTextureObject(name,0);
	this->mylog->Append("Chargement de la texture de la map FINIT");
}

int Terran::GetColorPixel(unsigned char * img, int x, int y,int pos)
{
        return img[((x*(int)this->size+y)*3+pos)];
}