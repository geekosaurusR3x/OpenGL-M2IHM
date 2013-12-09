#ifndef BUGDROID_H
#define BUGDROID_H

#include "object.h" // Base class: Object
#include "fonctions.h"
#include "jpeg_exception.h"
#include "Couleur.h"

class BugDroid : public Object
{
public:
	BugDroid();
	BugDroid(double X,double Y,double Z,double Size);
	~BugDroid();
	
	void Load();
	void Draw();
	
private :
	float *positions;
	float *texels;	
	float *normals;
	short *faces;
	int nb_position;
	int nb_textels;
	int nb_normals;
	int nb_faces;
	int nb_verticles;
	std::string name;
};

#endif // BUGDROID_H
