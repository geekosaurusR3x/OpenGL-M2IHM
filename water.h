#ifndef WATER_H
#define WATER_H

#include "object.h" // Base class: Object
#include <math.h> 

class Water : public Object
{
public:
	Water();
	Water(double X,double Y,double Z,double Size);
	~Water();
	void DrawChild();
	void LoadChild();
	void GenerateWater();
	void SetSizeWordl(double Size_World);
	void Update();
	
private:
	double ***water;
	double Map_Scale;
	double Size_Demi_Wordl;
};

#endif // WATER_H
