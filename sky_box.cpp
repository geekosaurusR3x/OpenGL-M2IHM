#include "sky_box.h"

using namespace std;


SkyBox::SkyBox():Object()
{
}

SkyBox::SkyBox(double X,double Y,double Z,double Size):Object(X,Y,Z,Size)
{
	nbtexture = 6;
	display_list = true;
	texture = true;
}

SkyBox::~SkyBox()
{
}

void SkyBox::LoadChild()
{
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

	this->mylog->Append("Chargement Texture Skybox : "+name+" Numero :"+to_string(num));
	this->mylog->Append("Chargement de la texture de la skymap...");
	LoadTextureObject(name+"_left",0); //left
	LoadTextureObject(name+"_front",1); //front
	LoadTextureObject(name+"_right",2); //right
	LoadTextureObject(name+"_back",3); //back
	LoadTextureObject(name+"_top",4); //top
	LoadTextureObject(name+"_bottom",5); //bottom
	this->mylog->Append("Chargement de la texture de la skymap FINIT");
}

void SkyBox::DrawChild()
{
		glEnable(GL_TEXTURE_2D); 
		glDisable(GL_LIGHTING);
		glDepthMask(GL_FALSE);
	   glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	   glColor3f(0,0,0);
		// Rendu de la skybox
		glBindTexture(GL_TEXTURE_2D, id_texture[0]); 
		glBegin(GL_QUADS); //left
			glTexCoord2f(0.0, 1.0); glVertex3f(this->x, this->y, this->z); 	
			glTexCoord2f(1.0,1.0); glVertex3f(x,y,z-this->size);
			glTexCoord2f(1.0,0.0); glVertex3f(x,y+this->size,z-this->size);
			glTexCoord2f(0.0,0.0); glVertex3f(x,y+this->size,z);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, id_texture[1]); 
		glBegin(GL_QUADS);			// front
			glTexCoord2f(0.0, 1.0); glVertex3f(x,y,z-this->size);
			glTexCoord2f(1.0, 1.0); glVertex3f(x+this->size,y,z-this->size);	
			glTexCoord2f(1.0, 0.0); glVertex3f(x+this->size,y+this->size,z-this->size); 
			glTexCoord2f(0.0, 0.0); glVertex3f(x,y+this->size,z-this->size); 
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, id_texture[2]); 
		glBegin(GL_QUADS);			// right
			glTexCoord2f(1.0, 1.0); glVertex3f(x+this->size,y,z);
			glTexCoord2f(1.0, 0.0); glVertex3f(x+this->size,y+this->size,z);
			glTexCoord2f(0.0, 0.0); glVertex3f(x+this->size,y+this->size,z-this->size);  
			glTexCoord2f(0.0, 1.0); glVertex3f(x+this->size,y,z-this->size);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, id_texture[3]); 
		glBegin(GL_QUADS);			// back
			glTexCoord2f(1.0, 1.0); glVertex3f(this->x, this->y, this->z);
			glTexCoord2f(1.0, 0.0); glVertex3f(x,y+this->size,z);
			glTexCoord2f(0.0, 0.0); glVertex3f(x+this->size,y+this->size,z);
			glTexCoord2f(0.0, 1.0); glVertex3f(x+this->size,y,z);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, id_texture[4]); 
		glBegin(GL_QUADS);			// top		
			glTexCoord2f(0.0, 0.0); glVertex3f(x,y+this->size,z);
			glTexCoord2f(0.0, 1.0); glVertex3f(x,y+this->size,z-this->size); 	
			glTexCoord2f(1.0, 1.0); glVertex3f(x+this->size,y+this->size,z-this->size);
			glTexCoord2f(1.0, 0.0); glVertex3f(x+this->size,y+this->size,z);
		glEnd();
		
		glBindTexture(GL_TEXTURE_2D, id_texture[5]);  
		glBegin(GL_QUADS);			// bottom	
			glTexCoord2f(1.0, 0.0); glVertex3f(x,y,z); 
			glTexCoord2f(0.0, 0.0); glVertex3f(x+this->size,y,z);
			glTexCoord2f(0.0, 1.0); glVertex3f(x+this->size,y,z-this->size);
			glTexCoord2f(1.0, 1.0); glVertex3f(x,y,z-this->size);	
		glEnd();
		
		glDepthMask(GL_TRUE);
		glDisable(GL_TEXTURE_2D); 
		glEnable(GL_LIGHTING);
}
