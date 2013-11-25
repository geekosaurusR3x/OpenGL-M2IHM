#include "world.h"

using namespace std;

World::World(int nbeolien,double wind)
{
	Wind = wind;
	SpaceEolien = 2.0;
	nbEoliene = nbeolien;
	
	//ajout des eolienes
	for(int i=0;i<nbeolien;++i)
	{
		ListeEolien.push_back(Eolien(i+SpaceEolien,0,0));
	}
}

World::~World()
{
}

void World::Draw(GLUquadric* params)
{
	//Boucle affichages objects
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].Draw(Wind,params);
	}
}

void World::RemoveEoliene()
{
	if(nbEoliene >0)
	{
		ListeEolien.pop_back();
		nbEoliene--;
	}
}

void World::AddEoliene()
{
	nbEoliene++;
	ListeEolien.push_back(Eolien(nbEoliene+SpaceEolien,0,0));
}
