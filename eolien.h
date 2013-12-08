#ifndef EOLIEN_H
#define EOLIEN_H

#include "object.h"
#include "Couleur.h"
class Eolien : public Object
{
public:
	Eolien();
	Eolien(double X, double Y, double Z, double Zoom);
	~Eolien();
	void Draw();
	void SetOrientationVent(double OrientationVent) {
		this->OrientationVent = OrientationVent;
	}
	void SetWind(double Wind) {
		this->Wind = Wind;
	}
private:
	int pas;
	double Wind;
	double OrientationVent;

};

#endif // EOLIEN_H
