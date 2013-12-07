#include "terran.h"

using namespace std;
Terran::Terran()
{
		this->Data_Dir = "";
		this->nice = false;
}

Terran::~Terran()
{
}

void Terran::Load()
{
		LoadModelMap();
		LoadTextureMap();
}
void Terran::Draw()
{
	glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE); 
	glBindTexture(GL_TEXTURE_2D, texture_terrain[nice]);
		if(nice)
		{
			DrawNice();
		}
		else
		{
			DrawCrapy();
		}
	glDisable(GL_TEXTURE_2D); 
}

void Terran::DrawNice()
{
	glBegin(GL_TRIANGLE_STRIP);
    for (int z = 0; z < SIZE_MAP-1; z++)
    {
        for (int x = 0; x < SIZE_MAP-1; x++)
        {
			glTexCoord2f(((float) x)/SIZE_MAP, ((float) z)/SIZE_MAP);
            glVertex3f(terrain[x][z][0], terrain[x][z][1], terrain[x][z][2]);

            // draw vertex 1
            glTexCoord2f(((float) x+1)/SIZE_MAP, ((float) z)/SIZE_MAP);
            glVertex3f(terrain[x+1][z][0],terrain[x+1][z][1],terrain[x+1][z][2]);

            // draw vertex 2
            glTexCoord2f(((float) x)/SIZE_MAP, ((float) z+1)/SIZE_MAP);
            glVertex3f(terrain[x][z+1][0],terrain[x][z+1][1],terrain[x][z+1][2]);

            // draw vertex 3
			glTexCoord2f(((float) x+1)/SIZE_MAP, ((float) z+1)/SIZE_MAP);
            glVertex3f(terrain[x+1][z+1][0],terrain[x+1][z+1][1],terrain[x+1][z+1][2]);

        }
    }
	glEnd();
}

void Terran::DrawCrapy()
{
	glBegin(GL_TRIANGLE_STRIP);
    for (int z = 0; z < SIZE_MAP-1; z++)
    {
        for (int x = 0; x < SIZE_MAP-1; x++)
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
}

double Terran::GetHauteurPos(double X, double Z)
{
	int x = (X+Size_Demi_Wordl)/Map_Scale;
	int z = (-Z+Size_Demi_Wordl)/Map_Scale;
	double hauteur_moyene = 0;
	if(debug){cout<<"Hauteur en X : "<<x<<" Y : "<<z<<" Hauteur : "<<terrain[x][z][1]<<endl;}
	hauteur_moyene = (terrain[x][z][1]+terrain[x+1][z][1]+terrain[x][z+1][1]+terrain[x+1][z+1][1])/4;
	if(debug){cout<<"Hauteur en X : "<<x<<" Y : "<<z<<" Hauteur : "<<hauteur_moyene<<endl;}
	return hauteur_moyene;
}

void Terran::SetSizeWordl(double Size_Wordl)
{
	this->Size_Demi_Wordl = Size_Wordl/2;
	this->Map_Scale = Size_Wordl/SIZE_MAP;
	if (debug){cout<<"Demi Wordl : "<<Size_Demi_Wordl<<" Map Scale : "<<Map_Scale<<endl;}
}

int Terran::GetColorPixel(unsigned char * img, int x, int y,int pos)
{
	return img[((x*SIZE_MAP+y)*3+pos)];
}

void Terran::LoadModelMap()
{
	unsigned char *map = 0;
	if (debug){cout<<"Generation du model map..."<<endl;}
	try
	{
		struct jpeg_decompress_struct cinfo;
		map = loadJpegImage(this->Data_Dir+"/Maps/map.jpg",&cinfo);
		for (int z = 0; z < SIZE_MAP; z++)
		{
			for (int x = 0; x < SIZE_MAP; x++)
			{
				terrain[x][z][0] = (double(x)*Map_Scale)-Size_Demi_Wordl;
				terrain[x][z][1] = (double)GetColorPixel(map,x,z,0);
				terrain[x][z][2] = -(double(z)*Map_Scale)+Size_Demi_Wordl;
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

void Terran::LoadTextureMap()
{
	//loading texture :
	unsigned char *Texture1 = 0;
	unsigned char *Texture2 = 0;
	unsigned char *Texture3 = 0;
	unsigned char *TextureGen = 0;
	float percent[3];
	double r,g,b;
	glGenTextures(1, texture_terrain);
	
	if (debug){cout<<"Generation de la texture de la map..."<<endl;}
	try
	{
		struct jpeg_decompress_struct cinfo;
		Texture1 = loadJpegImage(this->Data_Dir+"/Textures/map_texture1.jpg",&cinfo);
		Texture2 = loadJpegImage(this->Data_Dir+"/Textures/map_texture2.jpg",&cinfo);
		Texture3 = loadJpegImage(this->Data_Dir+"/Textures/map_texture3.jpg",&cinfo);
		TextureGen = loadJpegImage(this->Data_Dir+"/Maps/map.jpg",&cinfo); //allocation de la texturemap.. je sais c'est moche ><
		for (int z = 0; z < SIZE_MAP; z++)
		{
			for (int x = 0; x < SIZE_MAP; x++)
			{
				GetPercent(percent,terrain[x][z][1]);
				//texture 1
				r = percent[0]*GetColorPixel(Texture1,x,z,0);
				g = percent[0]*GetColorPixel(Texture1,x,z,1);
				b = percent[0]*GetColorPixel(Texture1,x,z,2);
				//texture 2
				r += percent[1]*GetColorPixel(Texture2,x,z,0);
				g += percent[1]*GetColorPixel(Texture2,x,z,1);
				b += percent[1]*GetColorPixel(Texture2,x,z,2);
				
								//texture 2
				r += percent[2]*GetColorPixel(Texture3,x,z,0);
				g += percent[2]*GetColorPixel(Texture3,x,z,1);
				b += percent[2]*GetColorPixel(Texture3,x,z,2);
				
				TextureGen[((x*SIZE_MAP+z)*3)] = (unsigned char)r;
				TextureGen[((x*SIZE_MAP+z+1)*3)] = (unsigned char)g;
				TextureGen[((x*SIZE_MAP+z+2)*3)] = (unsigned char)b;
			}
		}

	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}

	//bon application de la texture 1 car je n'arrive pas a debuger ma generation de texture
	setTexture(Texture1,SIZE_MAP,SIZE_MAP,texture_terrain[0]);
	setTexture(TextureGen,SIZE_MAP,SIZE_MAP,texture_terrain[1]);


	free(Texture1);
	free(Texture2);
	free(Texture3);
	free(TextureGen);
	if (debug){cout<<"Generation de la texture de la map FINIT"<<endl;}
}

void Terran::GetPercent(float* value, double hauteur)
{
        if(hauteur<MAX_TEXTURE_1)
                {
                value[0] = 1.0f;
                value[1] = 0.0f;
                value[2] = 0.0f;
                }
        else if(hauteur<MIX_TEXTURE_1_2)
                {
                value[0] = 1.0f - (hauteur-60.0f)/70.0f;
                value[1] = (hauteur-60.0f)/70.0f;
                value[2] = 0.0f;
                }
        else if(hauteur<MAX_TEXTURE_2)
                {
                value[0] = 0.0f;
                value[1] = 1.0f;
                value[2] = 0.0f;
                }
        else if(hauteur<MIX_TEXTURE_2_3)
                {
                value[0] = 0.0f;
                value[1] = 1.0f - (hauteur-180.0f)/40.0f;
                value[2] = (hauteur-180.0f)/40.0f;
                }
        else
                {
                value[0] = 0.0f;
                value[1] = 0.0f;
                value[2] = 1.0f;
                }
}

void Terran::TextureNice()
{
	nice = true;
}

void Terran::TexureCrapy()
{
	nice = false;
}
