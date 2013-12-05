#include "terran.h"

using namespace std;
Terran::Terran()
{
		this->Data_Dir = "";
}

Terran::~Terran()
{
}

void Terran::Load()
{
	unsigned char *image = 0;
	
	if (debug){cout<<"Chargement du fichier map"<<endl;}
	try
	{
		struct jpeg_decompress_struct cinfo;
		image = loadJpegImage(this->Data_Dir+"/Maps/map.jpg",&cinfo);
		for (int z = 0; z < SIZE_MAP; z++)
		{
			for (int x = 0; x < SIZE_MAP; x++)
			{
				terrain[x][z][0] = (double(x)*Map_Scale)-Size_Demi_Wordl;
				terrain[x][z][1] = (double)image[(z*SIZE_MAP+x)*3];
				terrain[x][z][2] = -(double(z)*Map_Scale)+Size_Demi_Wordl;
				if (debug){cout<<"terrain "<<terrain[x][z][0]<<" "<<terrain[x][z][1]<<" "<<terrain[x][z][1]<<endl;}
			}
		}
		free(image);

	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}
	
	//loading texture :
	glGenTextures(1, texture_terrain);
	if (debug){cout<<"Chargement Texture terrain"<<endl;}
	try
	{
		loadJpegTexture(this->Data_Dir+"/Textures/grass.jpg",texture_terrain[0]); //left
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}
}

void Terran::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glBindTexture(GL_TEXTURE_2D, texture_terrain[0]); 
	glPushMatrix();
    for (int z = 0; z < SIZE_MAP-1; z++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (int x = 0; x < SIZE_MAP-1; x++)
        {
            glTexCoord2f(0.0f, 0.0f);
            glColor3f(terrain[x][z][1]/255.0f, terrain[x][z][1]/255.0f, terrain[x][z][1]/255.0f);
            glVertex3f(terrain[x][z][0], terrain[x][z][1], terrain[x][z][2]);

            // draw vertex 1
            glTexCoord2f(1.0f, 0.0f);
            glColor3f(terrain[x+1][z][1]/255.0f,terrain[x+1][z][1]/255.0f, terrain[x+1][z][1]/255.0f);
            glVertex3f(terrain[x+1][z][0],terrain[x+1][z][1],terrain[x+1][z][2]);

            // draw vertex 2
            glTexCoord2f(0.0f, 1.0f);
            glColor3f(terrain[x][z+1][1]/255.0f, terrain[x][z+1][1]/255.0f, terrain[x][z+1][1]/255.0f);
            glVertex3f(terrain[x][z+1][0],terrain[x][z+1][1],terrain[x][z+1][2]);

            // draw vertex 3
			glTexCoord2f(1.0f, 1.0f);
            glColor3f(terrain[x+1][z+1][1]/255.0f,terrain[x+1][z+1][1]/255.0f,terrain[x+1][z+1][1]/255.0f);
            glVertex3f(terrain[x+1][z+1][0],terrain[x+1][z+1][1],terrain[x+1][z+1][2]);
        }
        glEnd();
    }
	glPopMatrix();
	glDisable(GL_TEXTURE_2D); 
}

double Terran::GetHauteurPos(double X, double Z)
{
	X+=Size_Demi_Wordl;
	Z+=Size_Demi_Wordl;
	int x = X / Map_Scale;
	int z = Z /Map_Scale;
	
	double hauteur_moyene = (terrain[x][z][1]+terrain[x+1][z][1]+terrain[x][z+1][1]+terrain[x+1][z+1][1])/4;
	if (debug){cout<<"Hauteur en X : "<<x<<" Z : "<<z<<" = "<<hauteur_moyene<<endl;}
	return hauteur_moyene;
}

void Terran::SetSizeWordl(double Size_Wordl)
{
	this->Size_Demi_Wordl = Size_Wordl/2;
	this->Map_Scale = Size_Wordl/SIZE_MAP;
}
