#include "sky_box.h"

using namespace std;


SkyBox::SkyBox():Object()
{
}

SkyBox::SkyBox(double X,double Y,double Z,double Size):Object(X,Y,Z,Size)
{
}

SkyBox::~SkyBox()
{
}

void SkyBox::Load()
{
	glGenTextures(6, texture_skybox);	
	LoadTexture(TEXTURE_SKYBOX_1);
}
void SkyBox::LoadTexture(int num)
{
	string name;
	if (num == TEXTURE_SKYBOX_1)
	{
		name = TEXTURE_SKYBOX_NAME_1;
	}
	else
	{
		name = TEXTURE_SKYBOX_NAME_2;
	}

	if (debug){cout<<"Chargement Texture Skybox : "<<name<<" Numero :"<<num <<endl;}
	try
	{
	
		loadJpegTexture(Data_Dir+"/Textures/"+name+"_left.jpg",texture_skybox[0]); //left
		loadJpegTexture(Data_Dir+"/Textures/"+name+"_front.jpg",texture_skybox[1]); //front
		loadJpegTexture(Data_Dir+"/Textures/"+name+"_right.jpg",texture_skybox[2]); //right
		loadJpegTexture(Data_Dir+"/Textures/"+name+"_back.jpg",texture_skybox[3]); //back
		loadJpegTexture(Data_Dir+"/Textures/"+name+"_top.jpg",texture_skybox[4]); //top
		loadJpegTexture(Data_Dir+"/Textures/"+name+"_bottom.jpg",texture_skybox[5]); //bottom
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cout<<e.what()<<endl;}
	}
	

}

void SkyBox::Draw()
{
	glEnable(GL_TEXTURE_2D); 
	glDisable(GL_LIGHTING);
	glDepthMask(GL_FALSE);

   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
   glColor3f(0,0,0);
	// Rendu de la skybox
	glBindTexture(GL_TEXTURE_2D, texture_skybox[0]); 
	glBegin(GL_QUADS); //left
		glTexCoord2f(0.0, 1.0); glVertex3f(this->x, this->y, this->z); 	
		glTexCoord2f(1.0,1.0); glVertex3f(x,y,z-this->size);
		glTexCoord2f(1.0,0.0); glVertex3f(x,y+this->size,z-this->size);
		glTexCoord2f(0.0,0.0); glVertex3f(x,y+this->size,z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[1]); 
	glBegin(GL_QUADS);			// front
		glTexCoord2f(0.0, 1.0); glVertex3f(x,y,z-this->size);
		glTexCoord2f(1.0, 1.0); glVertex3f(x+this->size,y,z-this->size);	
		glTexCoord2f(1.0, 0.0); glVertex3f(x+this->size,y+this->size,z-this->size); 
		glTexCoord2f(0.0, 0.0); glVertex3f(x,y+this->size,z-this->size); 
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[2]); 
	glBegin(GL_QUADS);			// right
		glTexCoord2f(1.0, 1.0); glVertex3f(x+this->size,y,z);
		glTexCoord2f(1.0, 0.0); glVertex3f(x+this->size,y+this->size,z);
		glTexCoord2f(0.0, 0.0); glVertex3f(x+this->size,y+this->size,z-this->size);  
		glTexCoord2f(0.0, 1.0); glVertex3f(x+this->size,y,z-this->size);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[3]); 
	glBegin(GL_QUADS);			// back
		glTexCoord2f(1.0, 1.0); glVertex3f(this->x, this->y, this->z);
		glTexCoord2f(1.0, 0.0); glVertex3f(x,y+this->size,z);
		glTexCoord2f(0.0, 0.0); glVertex3f(x+this->size,y+this->size,z);
		glTexCoord2f(0.0, 1.0); glVertex3f(x+this->size,y,z);
 

		
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[4]); 
	glBegin(GL_QUADS);			// top		
		glTexCoord2f(0.0, 0.0); glVertex3f(x,y+this->size,z);
		glTexCoord2f(0.0, 1.0); glVertex3f(x,y+this->size,z-this->size); 	
		glTexCoord2f(1.0, 1.0); glVertex3f(x+this->size,y+this->size,z-this->size);
		glTexCoord2f(1.0, 0.0); glVertex3f(x+this->size,y+this->size,z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[5]);  
	glBegin(GL_QUADS);			// bottom	
		glTexCoord2f(0.0, 0.0); glVertex3f(x,y,z); 
		glTexCoord2f(1.0, 1.0); glVertex3f(x+this->size,y,z);
		glTexCoord2f(1.0, 0.0); glVertex3f(x+this->size,y,z-this->size);
		glTexCoord2f(0.0, 0.0); glVertex3f(x,y,z-this->size);	
	glEnd();
	
	glDepthMask(GL_TRUE);
	glDisable(GL_TEXTURE_2D); 
	glEnable(GL_LIGHTING);

}

