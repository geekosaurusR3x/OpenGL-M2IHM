#include "sky_box.h"

using namespace std;


SkyBox::SkyBox()
{
}

SkyBox::SkyBox(double larg,double haut,double pro)
{
	this->Largeur = larg;
	this->Hauteur = haut;
	this->Profondeur = pro;
}

SkyBox::~SkyBox()
{
}

void SkyBox::LoadSkybox()
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
		string Dir = "";
		Dir+="Pictures/";
		loadJpegTexture(Dir+name+"_left.jpg",texture_skybox[0]); //left
		loadJpegTexture(Dir+name+"_front.jpg",texture_skybox[1]); //front
		loadJpegTexture(Dir+name+"_right.jpg",texture_skybox[2]); //right
		loadJpegTexture(Dir+name+"_back.jpg",texture_skybox[3]); //back
		loadJpegTexture(Dir+name+"_top.jpg",texture_skybox[4]); //top
		loadJpegTexture(Dir+name+"_bottom.jpg",texture_skybox[5]); //bottom
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
   double x = Largeur/2;
   double y = Hauteur/2;
   double z = Profondeur/2;
	// Rendu de la skybox
	glBindTexture(GL_TEXTURE_2D, texture_skybox[0]); 
	glBegin(GL_QUADS); //left
		glTexCoord2f(0.0, 1.0); glVertex3f(-x, -y, z); 	
		glTexCoord2f(1.0,1.0); glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0,0.0); glVertex3f(-x,y,-z);
		glTexCoord2f(0.0,0.0); glVertex3f(-x,y,z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[1]); 
	glBegin(GL_QUADS);			// front
		glTexCoord2f(0.0, 1.0); glVertex3f(-x,-y,-z);
		glTexCoord2f(1.0, 1.0); glVertex3f(x,-y,-z);	
		glTexCoord2f(1.0, 0.0); glVertex3f(x,y,-z); 
		glTexCoord2f(0.0, 0.0); glVertex3f(-x,y,-z); 
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[2]); 
	glBegin(GL_QUADS);			// right 	
		glTexCoord2f(1.0, 1.0); glVertex3f(x,-y,z);
		glTexCoord2f(1.0, 0.0); glVertex3f(x,y,z); 
		glTexCoord2f(0.0, 0.0); glVertex3f(x,y,-z); 
		glTexCoord2f(0.0, 1.0); glVertex3f(x,-y,-z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[3]); 
	glBegin(GL_QUADS);			// back
		glTexCoord2f(1.0, 1.0); glVertex3f(-x,-y,z); 
		glTexCoord2f(1.0, 0.0); glVertex3f(-x,y,z);
		glTexCoord2f(0.0, 0.0); glVertex3f(x,y,z);
		glTexCoord2f(0.0, 1.0); glVertex3f(x,-y,z);
		
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[4]); 
	glBegin(GL_QUADS);			// top		
		glTexCoord2f(0.0, 0.0); glVertex3f(-x,y,z);
		glTexCoord2f(0.0, 1.0); glVertex3f(-x,y,-z); 	
		glTexCoord2f(1.0, 1.0); glVertex3f(x,y,-z); 
		glTexCoord2f(1.0, 0.0); glVertex3f(x,y,z);
	glEnd();
	
	glBindTexture(GL_TEXTURE_2D, texture_skybox[5]);  
	glBegin(GL_QUADS);			// bottom	
		glTexCoord2f(0.0, 0.0); glVertex3f(-x, -y, z); 
		glTexCoord2f(0.0, 1.0); glVertex3f(x,-y,z); 
		glTexCoord2f(1.0, 1.0); glVertex3f(x,-y,-z);
		glTexCoord2f(1.0, 0.0); glVertex3f(-x,-y,-z);	
	glEnd();
	
	glDepthMask(GL_TRUE);
	glDisable(GL_TEXTURE_2D); 
	glEnable(GL_LIGHTING);

}

