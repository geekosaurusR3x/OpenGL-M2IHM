#include "world.h"
using namespace std;

World::World(double largeur,double hauteur,double profondeur)
{
	this->Wind = 0;
	this->SpaceEolien =5;
	this->nbEoliene = 0;
	this->Hauteur = hauteur;
	this->Largeur = largeur;
	this->Profondeur = profondeur;
	this->Orientation_Wind = 0;
}

World::~World()
{
}

void World::SetWind(double Wind) {
	if(debug){cout<<"Set Wind: "<< Wind<<endl;}
	this->Wind = Wind;
}
double World::GetWind() const {
	return Wind;
}
void World::SetDebug(bool debug) {
	this->debug = debug;
}
bool World::IsDebug() const {
	return debug;
}

double World::GetHauteur() const {
	return Hauteur;
}
double World::GetProfondeur() const {
	return Profondeur;
}
double World::GetLargeur() const {
	return Largeur;
}
	
void  World::SetOrientationWind(int Orientation_Wind)
{
	this->Orientation_Wind = (this->Orientation_Wind+Orientation_Wind)%360;
	if (debug){cout<<"Orientation du vent :"<<this->Orientation_Wind<<endl;}
}

int World::GetOrientationWind() const
{
	return Orientation_Wind;
}

void World::LoadWorld()
{
	glGenTextures(6, texture_skybox);
	Load_Texture_Skybox();
	AddEoliene();

	//Ajout de la fleche
	Arrow = Fleche();

}

void World::Load_Texture_Skybox()
{	//chargement de textures de la skybox
	try
	{
/*		loadJpegImage("Pictures/left_sky_box.jpg",texture_skybox[0]); //left
		loadJpegImage("Pictures/front_sky_box.jpg",texture_skybox[1]); //front
		loadJpegImage("Pictures/right_sky_box.jpg",texture_skybox[2]); //right
		loadJpegImage("Pictures/back_sky_box.jpg",texture_skybox[3]); //back
		loadJpegImage("Pictures/top_sky_box.jpg",texture_skybox[4]); //top
		loadJpegImage("Pictures/bottom_sky_box.jpg",texture_skybox[5]); //bottom*/
	
		loadJpegImage("Pictures/city_left.jpg",texture_skybox[0]); //left
		loadJpegImage("Pictures/city_front.jpg",texture_skybox[1]); //front
		loadJpegImage("Pictures/city_right.jpg",texture_skybox[2]); //right
		loadJpegImage("Pictures/city_back.jpg",texture_skybox[3]); //back
		loadJpegImage("Pictures/city_top.jpg",texture_skybox[4]); //top
		loadJpegImage("Pictures/bottom_sky_box.jpg",texture_skybox[5]); //bottom
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cerr<<e.what()<<endl;}
	}
	

}
void World::Draw(double camX,double camY,double camZ)
{
	this->DrawSky();
	this->DrawObject(camX,camY,camZ);

}

void World::RemoveEoliene()
{
	if(nbEoliene >0)
	{
		ListeEolien.pop_back();
		nbEoliene--;
		if(debug){cout<<"Suppression de la derniere eolienne"<<endl;}
	}
}

void World::AddEoliene()
{
	double X = 0+SpaceEolien*nbEoliene;
	double Z = 0;
	nbEoliene++;
	ListeEolien.push_back(Eolien(X,0,Z));
	
	if(debug){cout<<"Ajout d'une eolienne en X: "<<X<<" Z: "<<Z<<endl;}
}

void World::DrawObject(double camX,double camY,double camZ)
{
	//affichage de la fleche
	Arrow.Draw(camX,camY,camZ,this->Orientation_Wind);
	//Boucle affichages objects
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].Draw(this->Wind,this->Orientation_Wind);
	}
}

void World::DrawSky()
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
