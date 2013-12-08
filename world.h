#ifndef WORLD_H
#define WORLD_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "eolien.h"
#include "sky_box.h"
#include "Couleur.h"
#include "Fleche.h"
#include "terran.h"
#include "fonctions.h"

#include <string>
#include <vector>
#include <math.h>

class World
{
public:
	World();
	World(double size);
	~World();
	void SetWind(double Wind);
	double GetWind() const;
	void SetDebug(bool debug);
	bool IsDebug() const;
	double GetSize() const ;
	void LoadWorld();
	void RemoveEoliene();
	void AddEoliene();

	void Draw(double camX,double camY,double camZ);

	void SetOrientationWind(int Orientation_Wind);
	int GetOrientationWind() const;

	void FogOn();
	void FogOff();
	void ChangeSkybox (int num);
	void ChangeTextureMap(int num);

	void SetDataDir(const std::string& Data_Dir) {
		this->Data_Dir = Data_Dir;
	}
	const std::string& GetDataDir() const {
		return Data_Dir;
	}

private:
	bool debug;
	double Wind;
	int nbEoliene;
	double Size;
	int Orientation_Wind;
	bool fog;
	std::string Data_Dir;

	std::vector<Eolien> ListeEolien;

	Fleche Arrow;
	SkyBox Sky;
	Terran Sol;
	void InitFog();
	void DrawObject(double camX,double camY,double camZ);
};

#endif // WORLD_H
