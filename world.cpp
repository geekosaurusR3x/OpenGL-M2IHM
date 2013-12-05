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
	this->fog = true;
}

World::~World()
{
}

void World::SetWind(double Wind) {
	if(debug){cout<<"Force du  vent : "<< Wind<<endl;}
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
	//Ajout de la skybox
	Sky = SkyBox(Largeur,Hauteur,Profondeur);
	Sky.SetDebug(this->debug);
	Sky.LoadSkybox();
	AddEoliene();
	//Ajout de la fleche
	Arrow = Fleche();

	InitFog();
}

void World::InitFog()
{
	GLfloat fogColor[4]= {0.5f, 0.5f, 0.5f, 1.0f}; 
	glFogi (GL_FOG_MODE, GL_LINEAR) ;
	glFogfv(GL_FOG_COLOR,fogColor) ;
	glFogf(GL_FOG_DENSITY, 0.35) ;
	glFogf(GL_FOG_START, 512.0) ;
	glFogf(GL_FOG_END, 1024.0) ;
}

void World::FogOn()
{
	fog = true;
	if (debug){cout<<"Changement etat brouillard : "<<fog <<endl;}
}

void World::FogOff()
{
	fog = false;
	if (debug){cout<<"Changement etat brouillard : "<<fog <<endl;}
}

void World::ChangeSkybox(int num)
{
	Sky.LoadTexture(num);
}
void World::Draw(double camX,double camY,double camZ)
{
	if (fog){glEnable(GL_FOG);}else{glDisable(GL_FOG);}
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
	//Affichange de la skybox
	Sky.Draw();
	//affichage de la fleche
	Arrow.Draw(camX,camY,camZ,this->Orientation_Wind);
	//Boucle affichages objects
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].Draw(this->Wind,this->Orientation_Wind);
	}
}
