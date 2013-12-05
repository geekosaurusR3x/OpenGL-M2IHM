#ifndef SKYBOX_H
#define SKYBOX_H

#define TEXTURE_SKYBOX_1 1
#define TEXTURE_SKYBOX_2 2
#define TEXTURE_SKYBOX_NAME_1 "city"
#define TEXTURE_SKYBOX_NAME_2 "iceflow"

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string>

#include "fonctions.h"

class SkyBox
{
public:
	SkyBox();
	SkyBox(double larg,double haut,double pro);
	~SkyBox();
	void LoadSkybox();
	void LoadTexture(int num);
	void Draw();
	void SetDebug(bool debug) {
		this->debug = debug;
	}

	void SetDataDir(const std::string& Data_Dir) {
		this->Data_Dir = Data_Dir;
	}
private:
	GLuint texture_skybox[6];
	bool debug;
	double Largeur;
	double Hauteur;
	double Profondeur;
	std::string Data_Dir;
};

#endif // SKYBOX_H
