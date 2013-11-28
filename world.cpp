#include "world.h"
using namespace std;

World::World(int nbeolien,double wind)
{
	Wind = wind;
	SpaceEolien = 2.0;
	nbEoliene = nbeolien;
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

void World::LoadWorld()
{
	//chargement de textures de la skybox
	try
	{
		loadJpegImage("Pictures/top_sky_box.jpg",texture_skybox[0]);
		loadJpegImage("Pictures/bottom_sky_box.jpg",texture_skybox[1]);
		loadJpegImage("Pictures/left_sky_box.jpg",texture_skybox[2]);
		loadJpegImage("Pictures/midle1_sky_box.jpg",texture_skybox[3]);
		loadJpegImage("Pictures/midle2_sky_box.jpg",texture_skybox[4]);
		loadJpegImage("Pictures/right_sky_box.jpg",texture_skybox[5]);
	}
	catch (const jpeg_load_exception &e)
	{
		if (debug){cerr<<e.what()<<endl;}
	}
	//ajout des eolienes
	for(int i=0;i<nbEoliene;++i)
	{
		ListeEolien.push_back(Eolien(i+SpaceEolien,0,0));
	}
	
}

void World::Draw(GLUquadric* params)
{
	this->DrawSky(params);
	this->DrawObject(params);

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

void World::DrawObject(GLUquadric* params)
{
	//Boucle affichages objects
	for(size_t i=0;i<ListeEolien.size();++i)
	{
		ListeEolien[i].Draw(Wind,params);
	}
}

void World::DrawSky(GLUquadric* params)
{
}
