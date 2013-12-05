#ifndef TERRAN_H
#define TERRAN_H

#define SIZE_MAP   32                     // size of map along x-axis

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

	double GetMapScale() const {
		return Map_Scale;
	}
	void SetSizeWordl(double Size_Wordl);
	double GetHauteurPos(double X,double Z);
private:
	bool debug;
	double terrain[SIZE_MAP][SIZE_MAP][3];
	double Size_Demi_Wordl;
	double Map_Scale;
	GLuint texture_terrain[1];
	std::string Data_Dir;
};

#endif // TERRAN_H
