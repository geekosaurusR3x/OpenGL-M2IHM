#ifndef TERRAN_H
#define TERRAN_H

#define MAP_X   32                     // size of map along x-axis
#define MAP_Z   32                      // size of map along z-axis
#define MAP_SCALE  32.0f

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "fonctions.h"
#include "jpeg_exception.h"

class Terran
{
public:
	Terran();
	~Terran();
	void Load();
	void Draw();

	void SetDebug(bool debug) {
		this->debug = debug;
	}

	void SetDataDir(const std::string& Data_Dir) {
		this->Data_Dir = Data_Dir;
	}
private:
	bool debug;
	float terrain[MAP_X][MAP_Z][3];
	GLuint texture_terrain[1];
	std::string Data_Dir;
};

#endif // TERRAN_H
