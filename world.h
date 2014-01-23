#ifndef WORLD_H
#define WORLD_H
#define EOLIENNE 1
#define EOLIENNE_BENCH 3
#define BUGDROID 2
#define INTERPRATE_NAME_WORLD "World"

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
#include "water.h"
#include "fonctions.h"
#include "bug_droid.h"

#include <string>
#include <vector>
#include <math.h>
#include "loger.h"

class World
{
public:
	World();
	World(double size);
	~World();
	void SetWind(double Wind);
	double GetWind() const;
	double GetSize() const ;
	void LoadWorld();
	void Add(int choice);
	void Remove(int choice);
	void Draw();
	void Interprate(std::string cmd);

	void SetOrientationWind(int Orientation_Wind);
	int GetOrientationWind() const;

	void FogOn();
	void FogOff();
	void ChangeSkybox (int num);
	void ChangeTextureMap(int num);
	void ChangerColorEolienne(int num);
	void Update(double camX,double camY,double camZ);
	double GetHauteur(double X,double Y);

	void SetDataDir(const std::string& Data_Dir) {
		this->Data_Dir = Data_Dir;
	}
	const std::string& GetDataDir() const {
		return Data_Dir;
	}

	void StartBench();

	bool IsBench() const {
		return bench;
	}

	void StopBench();

	int GetNbEolieneBench() const {
		return nbEoliene_Bench;
	}
private:
	double Wind;
	int nbEoliene;
	int nbEoliene_Bench;
	int nbBug;
	double Size;
	int Orientation_Wind;
	bool fog;
	bool bench;
	std::string Data_Dir;

	std::vector<Eolien> ListeEolien;
	std::vector<Eolien> ListeEolienBench;
	std::vector<BugDroid> ListeBug;

	Fleche Arrow;
	SkyBox Sky;
	Terran Sol;
	Water Sea;
	Loger *mylog;
	void InitFog();
	void DrawObject();
};

#endif // WORLD_H
