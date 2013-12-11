#ifndef EOLIEN_H
#define EOLIEN_H

#define EOLIEN_COULEUR_1 1
#define EOLIEN_COULEUR_2 2
#define EOLIEN_COULEUR_3 3
#define EOLIEN_COULEUR_4 4

#include "object.h"
class Eolien : public Object
{
public:
	Eolien();
	Eolien(double X, double Y, double Z, double Zoom);
	~Eolien();
	void DrawChild();
	void SetOrientationVent(double OrientationVent) {
		this->OrientationVent = OrientationVent;
	}
	void SetWind(double Wind) {
		this->Wind = Wind;
	}
	
	void SetColor(int color);
	
private:
	int pas;
	double Wind;
	double OrientationVent;

};

#endif // EOLIEN_H
