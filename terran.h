#ifndef TERRAN_H
#define TERRAN_H

#define SIZE_MAP 512
#define TEXTURE_MAP_1 1
#define TEXTURE_MAP_2 2
#define TEXTURE_MAP_NAME_1 "map_texture1"
#define TEXTURE_MAP_NAME_2 "map_texture2"
                   
#include "object.h"
#include "fonctions.h"
#include "jpeg_exception.h"
#include <math.h>

class Terran : public Object
{
public:
	Terran();
	Terran(double X,double Y, double Z, double Size);
	~Terran();
	void Load();
	void Draw();


	double GetMapScale() const {
		return Map_Scale;
	}
	void SetSizeWordl(double Size_Wordl);
	double GetHauteurPos(double X,double Z);
	void LoadTextureMap(int num);
	
private:
	GLuint texture_terrain[2];
	GLuint display_list;
	double terrain[SIZE_MAP][SIZE_MAP][3];
	double Size_Demi_Wordl;
	double Map_Scale;

	void LoadModelMap();
	int GetColorPixel(unsigned char * img, int x, int y,int pos);
	
	void GenDisplayList();
};

#endif // TERRAN_H
