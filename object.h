#ifndef OBJECT_H
#define OBJECT_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "fonctions.h"
#include "Couleur.h"
#include "loger.h"
#include <string>

class Object
{
public:
	Object();
	Object(double X,double Y,double Z,double Size);
	virtual ~Object()=0;
	virtual void Load();
	virtual void LoadChild();
	virtual void Draw();
	virtual void DrawChild();
	virtual void Update();
	void LoadTextureObject(std::string name, int num);
	void LoadInfoObject(std::string name);
	void LoadDataObject(std::string name);
	void DrawObject();
	void SetX(double x) {
		this->x = x;
	}
	void SetY(double y) {
		this->y = y;
	}
	void SetZ(double z) {
		this->z = z;
	}

	virtual void SetDataDir(const std::string& Data_Dir) {
		this->Data_Dir = Data_Dir;
	}


	double GetSize() const {
		return size;
	}
protected :
	//partie standar
	bool display_list;
	bool texture;
	bool model3D;
	double x;
	double y;
	double z;
	double size;
	double* color;
	Loger *mylog;
	std::string Data_Dir;
	//partie texture
	int nbtexture;
	GLuint *id_texture;
	//partie display list
	GLuint id_display_list;
	//partie model3D
	float *positions_vertex;
	float *texels;	
	float *normals;
	short *faces;
	int nb_position;
	int nb_textels;
	int nb_normals;
	int nb_faces;
	int nb_verticles;
	
};

#endif // OBJECT_H
