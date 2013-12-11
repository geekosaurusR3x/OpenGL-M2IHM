#ifndef WATER_H
#define WATER_H

#include "object.h" // Base class: Object
#include "Couleur.h"
#include "fonctions.h"
#include <iostream>
#include <math.h> 

class Water : public Object
{
public:
	Water();
	Water(double X,double Y,double Z,double Size);
	~Water();
	void Draw();
	void Load();
	void GenerateWater();
	void LoadTexture();
	void SetSizeWordl(double Size_World);
	void Update();
	
private:
	double ***water;
	double Map_Scale;
	double Size_Demi_Wordl;
	GLuint texture_water[1];
};

#endif // WATER_H
