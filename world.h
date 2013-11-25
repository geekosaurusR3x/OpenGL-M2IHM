#ifndef WORLD_H
#define WORLD_H

#include "eolien.h"
#include <vector>

class World
{
public:
	World(int nbeolien,double wind);
	~World();
	void SetWind(double Wind) {
		this->Wind = Wind;
	}
	double GetWind() const {
		return Wind;
	}
	void RemoveEoliene();
	void AddEoliene();
	void Draw(GLUquadric* params);

private:
	double Wind;
	int SpaceEolien;
	int nbEoliene;

	std::vector<Eolien> ListeEolien;
};

#endif // WORLD_H
