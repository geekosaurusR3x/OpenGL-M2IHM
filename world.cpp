#include "world.h"
using namespace std;

World::World()
{
	World(512);
}
World::World(double size)
{
	this->Wind = 0;
	this->nbEoliene = 0;
	this->nbBug = 0;
	this->Size = size;
	this->Orientation_Wind = 0;
	this->fog = true;
}

World::~World()
{
}

void World::SetWind(double Wind) {
	if(debug){cout<<"Force du  vent : "<< Wind<<endl;}
	this->Wind = Wind;
	//Boucle mise a jour des eoliennes
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].SetWind(this->Wind);
	}
	
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

double World::GetSize() const {
	return this->Size;
}
	
void  World::SetOrientationWind(int Orientation_Wind)
{
	this->Orientation_Wind = (this->Orientation_Wind+Orientation_Wind)%360;
	if (debug){cout<<"Orientation du vent :"<<this->Orientation_Wind<<endl;}
	//Boucle mise a jour des eoliennes
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].SetOrientationVent(this->Orientation_Wind);
	}
}

int World::GetOrientationWind() const
{
	return Orientation_Wind;
}

void World::LoadWorld()
{
	//Ajout de la skybox
	double Demi_Size = this->Size/2;
	Sky = SkyBox(-Demi_Size,-Demi_Size,Demi_Size,this->Size);
	Sky.SetDebug(this->debug);
	Sky.SetDataDir(this->Data_Dir);
	Sky.Load();
	//Ajout du sol
	Sol = Terran(-Demi_Size,-Demi_Size,Demi_Size,1);
	Sol.SetDebug(debug);
	Sol.SetSizeWordl(this->Size);
	Sol.SetDataDir(this->Data_Dir);
	Sol.Load();
	//ajout de differant object;
	Add(EOLIENNE);
	Add(BUGDROID);
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

void World::DrawObject(double camX,double camY,double camZ)
{
	//Affichange de la skybox
	Sky.Draw();
	//Affichange du sol
	Sol.Draw();
	//affichage de la fleche
	Arrow.Draw(camX,camY,camZ,this->Orientation_Wind);
	//Boucle affichages objects
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].Draw();
	}
	for(size_t i=0;i<ListeBug.size();++i)
	{
		ListeBug[i].Draw();
	}
	//affichage du model
	Droid.Draw();
}

void World::ChangeTextureMap(int num)
{
	Sol.TextureNice();
	if(num == 0){Sol.TexureCrapy();}
}

void World::Add(int choice)
{
	double rayon = RandFloat(0.0,this->Size/2);
	double angle = RandFloat(0.0,360.0);
	double X = 0 + rayon*cos(angle);
	double Z = 0 + rayon*sin(angle);
	switch(choice)
	{
		case EOLIENNE:
			nbEoliene++;
			if(debug){
				cout<<"Ajout d'une eolienne en X: "<<X<<" Z: "<<Z<<endl;
			}
			ListeEolien.push_back(Eolien(X,Sol.GetHauteurPos(X,Z),Z,Sol.GetMapScale()));
			break;
		case BUGDROID:
			nbBug++;
			if(debug){
				cout<<"Ajout d'un BugDroid en X: "<<X<<" Z: "<<Z<<endl;
			}
			ListeBug.push_back(BugDroid(X,Sol.GetHauteurPos(X,Z),Z,Sol.GetMapScale()+10));
			ListeBug.back().SetDebug(debug);
			ListeBug.back().SetDataDir(this->Data_Dir);
			ListeBug.back().Load();
			break;
	}
}

void World::Remove(int choice)
{
	switch(choice)
	{
		case EOLIENNE:
			if(nbEoliene >0)
			{
				ListeEolien.pop_back();
				nbEoliene--;
				if(debug){cout<<"Suppression de la derniere eolienne"<<endl;}
			}
			break;
		case BUGDROID:
			if(nbBug >0)
			{
				ListeBug.pop_back();
				nbBug--;
				if(debug){cout<<"Suppression du dernier BugDroid"<<endl;}
			}
			break;
	}
}
