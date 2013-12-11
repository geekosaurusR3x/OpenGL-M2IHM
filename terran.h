#ifndef TERRAN_H
#define TERRAN_H

#define SIZE_MAP 512
#define TEXTURE_MAP_1 1
#define TEXTURE_MAP_2 2
#define TEXTURE_MAP_NAME_1 "map_texture1"
#define TEXTURE_MAP_NAME_2 "map_texture2"
                   
#include "object.h"
#include <math.h>

class Terran : public Object
{
public:
	Terran();
	Terran(double X,double Y, double Z, double Size);
	~Terran();
	void LoadChild();
	void DrawChild();


	double GetMapScale() const {
		return Map_Scale;
	}
	void SetSizeWordl(double Size_Wordl);
	double GetHauteurPos(double X,double Z);
	void LoadTexture(int num);
	
private:
	double terrain[SIZE_MAP][SIZE_MAP][3];
	double Size_Demi_Wordl;
	double Map_Scale;

	void LoadModelMap();
	int GetColorPixel(unsigned char * img, int x, int y,int pos);
	
};

#endif // TERRAN_H
