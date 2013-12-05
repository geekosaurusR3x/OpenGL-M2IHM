#include "terran.h"

using namespace std;
Terran::Terran()
{
	
}

Terran::~Terran()
{
}

void Terran::Load()
{
	unsigned char *image = 0;
	string Dir = "";
	Dir+="Pictures/";
	if (debug){cout<<"Chargement du fichier map"<<endl;}
	try
	{
		struct jpeg_decompress_struct cinfo;
		image = loadJpegImage(Dir+"map.jpg",&cinfo);
		for (int z = 0; z < MAP_Z; z++)
		{
			for (int x = 0; x < MAP_X; x++)
			{
				terrain[x][z][0] = (float(x)*MAP_SCALE)-512.0;
				terrain[x][z][1] = (float)image[(z*MAP_Z+x)*3];
				terrain[x][z][2] = -(float(z)*MAP_SCALE)+512;
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
		loadJpegTexture(Dir+"grass.jpg",texture_terrain[0]); //left
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
    for (int z = 0; z < MAP_Z-1; z++)
    {
        glBegin(GL_TRIANGLE_STRIP);
        for (int x = 0; x < MAP_X-1; x++)
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