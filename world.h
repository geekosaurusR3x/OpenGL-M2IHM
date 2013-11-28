#ifndef WORLD_H
#define WORLD_H

#include "eolien.h"
#include "fonctions.h"
#include <vector>

class World
{
public:
	World(int nbeolien,double wind);
	~World();
	void SetWind(double Wind);
	double GetWind() const;
	void SetDebug(bool debug);
	bool IsDebug() const;
	void LoadWorld();
	void RemoveEoliene();
	void AddEoliene();
	void Draw(GLUquadric* params);

private:
	bool debug;
	double Wind;
	int SpaceEolien;
	int nbEoliene;
	GLuint texture_skybox[6];
	std::vector<Eolien> ListeEolien;

	void DrawObject(GLUquadric* params);
	void DrawSky(GLUquadric* params);
};

#endif // WORLD_H
