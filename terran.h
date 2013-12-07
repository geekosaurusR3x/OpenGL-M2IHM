#ifndef TERRAN_H
#define TERRAN_H

#define SIZE_MAP   128
#define MAX_TEXTURE_1   60
#define MIX_TEXTURE_1_2   130 
#define MAX_TEXTURE_2   180
#define MIX_TEXTURE_2_3   220  
                   

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "fonctions.h"
#include "jpeg_exception.h"
#include <math.h>

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
	void TexureCrapy();
	void TextureNice();

void SetNice(bool nice) {this->nice = nice;}
private:
	bool debug;
	bool nice;
	double terrain[SIZE_MAP][SIZE_MAP][3];
	double Size_Demi_Wordl;
	double Map_Scale;
	GLuint texture_terrain[2];
	std::string Data_Dir;
	void LoadModelMap();
	void LoadTextureMap();
	
	int GetColorPixel(unsigned char * img, int x, int y,int pos);
	void GetPercent(float *value, double hauteur);
	void DrawCrapy();
	void DrawNice();
};

#endif // TERRAN_H
