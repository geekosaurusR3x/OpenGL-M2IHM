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
	this->nbEoliene_Bench = 0;
	this->nbBug = 0;
	this->Size = size;
	this->Orientation_Wind = 0;
	this->fog = false;
	this->mylog = Loger::getInstance();
	this->bench = false;
}

World::~World()
{
}

void World::SetWind(double Wind) {
	this->Wind = Wind;
	this->mylog->Append("Force du  vent : "+to_string(this->Wind));
}
double World::GetWind() const {
	return Wind;
}
double World::GetSize() const {
	return this->Size;
}
	
void  World::SetOrientationWind(int Orientation_Wind)
{
	this->Orientation_Wind = (this->Orientation_Wind+Orientation_Wind)%360;
	this->mylog->Append("Orientation du vent :"+to_string(this->Orientation_Wind));
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
	Sky.SetDataDir(this->Data_Dir);
	Sky.Load();
	//Ajout du sol
	Sol = Terran(-Demi_Size,-Demi_Size,Demi_Size,1);
	Sol.SetSizeWordl(this->Size);
	Sol.SetDataDir(this->Data_Dir);
	Sol.Load();
	//Ajout de l'eau
	Sea = Water(-Demi_Size,60,Demi_Size,this->Sol.GetSize()/4);
	Sea.SetDataDir(this->Data_Dir);
	Sea.SetSizeWordl(this->Size);
	Sea.Load();
	//ajout de differant object;
	Add(EOLIENNE);
	Add(BUGDROID);
	//Ajout de la fleche
	Arrow = Fleche(200,200,0,1);
	InitFog();
	
}

void World::InitFog()
{
	glFogi (GL_FOG_MODE, GL_LINEAR) ;
	glFogfv(GL_FOG_COLOR,brouyardGris) ;
	glFogf(GL_FOG_DENSITY, 0.05) ;
	glFogf(GL_FOG_START, 512.0) ;
	glFogf(GL_FOG_END, 1024.0) ;
}

void World::FogOn()
{
	fog = true;
	this->mylog->Append("Changement etat brouillard : "+to_string(this->fog));
}

void World::FogOff()
{
	fog = false;
	this->mylog->Append("Changement etat brouillard : "+to_string(this->fog));
}

void World::ChangeSkybox(int num)
{
	Sky.LoadTexture(num);
}
void World::Draw()
{
	if (fog){glEnable(GL_FOG);}else{glDisable(GL_FOG);}
	this->DrawObject();

}

void World::DrawObject()
{
	//Affichange de la skybox
	Sky.Draw();
	//Affichange du sol
	Sol.Draw();
	//Affichage de l'eau
	Sea.Draw();
	//affichage de la fleche

	Arrow.Draw();
		
	//Boucle affichages objects
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].Draw();
	}
	for(size_t i=0;i<ListeBug.size();++i)
	{
		ListeBug[i].Draw();
	}
	
	//Boucle Affichage eoliennes bench
	for(size_t i=0;i<ListeEolienBench.size();++i)
	{
		ListeEolienBench[i].Draw();
	}	
	
}

void World::ChangeTextureMap(int num)
{
	Sol.LoadTexture(num);
}

void World::Add(int choice)
{
	double rayon = RandFloat(0.0,(this->Size/2)-200);
	double angle = RandFloat(0.0,360.0);
	double X = 0 + rayon*cos(angle);
	double Z = 0 + rayon*sin(angle);
	switch(choice)
	{
		case EOLIENNE:
			nbEoliene++;
			this->mylog->Append("Ajout d'une eolienne en X: "+to_string(X)+" Z: "+to_string(Z));
			ListeEolien.push_back(Eolien(X,Sol.GetHauteurPos(X,Z),Z,Sol.GetMapScale()));
			break;
			
		case EOLIENNE_BENCH:
			nbEoliene_Bench++;
			this->mylog->Append("Ajout d'une eolienne de bench en X: "+to_string(X)+" Z: "+to_string(Z));
			ListeEolienBench.push_back(Eolien(X,Sol.GetHauteurPos(X,Z),Z,Sol.GetMapScale()));
			break;
			
		case BUGDROID:
			nbBug++;
			this->mylog->Append("Ajout d'un BugDroid en X: "+to_string(X)+" Z: "+to_string(Z));
			ListeBug.push_back(BugDroid(X,Sol.GetHauteurPos(X,Z)+30,Z,Sol.GetMapScale()+5));
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
				this->mylog->Append("Suppression de la derniere eolienne");
			}
			break;
		case BUGDROID:
			if(nbBug >0)
			{
				ListeBug.pop_back();
				nbBug--;
				this->mylog->Append("Suppression du dernier BugDroid");
			}
			break;
	}
}

void World::Update(double camX,double camY,double camZ)
{
	//this->mylog->Append("Arrox pos "+to_string(camX)+" "+to_string(camY)+" "+to_string(camZ));
	Arrow.SetX(camX);
	Arrow.SetY(camY);
	Arrow.SetZ(camZ);
	Arrow.SetForceVent(this->Wind);
	Arrow.SetOrientationVent(this->Orientation_Wind);
	
	Arrow.Update();
	Sea.Update();
	//Boucle mise a jour des eoliennes
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].SetOrientationVent(this->Orientation_Wind);
		ListeEolien[i].SetWind(this->Wind);
	}
	//Boucle de mise a jour des eoliennes de bench
	for(size_t i=0;i<ListeEolienBench.size();++i)
	{
		ListeEolienBench[i].SetColor(EOLIEN_COULEUR_3);
		ListeEolienBench[i].SetOrientationVent(this->Orientation_Wind);
		ListeEolienBench[i].SetWind(this->Wind);
	}
	if(this->IsBench())
	{
		this->Add(EOLIENNE_BENCH);
	}
	
}

void World::ChangerColorEolienne(int num)
{
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].SetColor(num);
	}
}

double World::GetHauteur(double X, double Y)
{
	return Sol.GetHauteurPos(X,Y);
}

void World::Interprate(std::string cmd)
{
	stringstream stream(cmd);
	string val;
	getline(stream, val, ' ');
	if(val == "fog")
	{
		getline(stream, val, ' ');
		if(val == "1")
		{
			FogOn();
		}
		else if (val == "0")
		{
			FogOff();
		}
		else
		{
			this->mylog->Append("Wordl -> fog : "+val+" unknow value");
		}
	}
	else
	{
		this->mylog->Append("World : "+val+" unknow commande");
	}
}

void World::StartBench()
{
	this->mylog->Append("Demarage d'EolBench... Risque de lourdement ralentire la machine");
	this->bench = true;
}
	
void World::StopBench()
{
	this->bench = false;
	this->ListeEolienBench.clear();
	this->mylog->Append("Fin d'EolBench... nombre D'eoliennes : "+to_string(nbEoliene_Bench));
	this->nbEoliene_Bench = 0;
}
