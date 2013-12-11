#ifndef OBJECT_H
#define OBJECT_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "fonctions.h"
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


	void SetX(double x) {
		this->x = x;
	}
	void SetY(double y) {
		this->y = y;
	}
	void SetZ(double z) {
		this->z = z;
	}
	virtual void SetDebug(bool debug) {
		this->debug = debug;
	}

	virtual void SetDataDir(const std::string& Data_Dir) {
		this->Data_Dir = Data_Dir;
	}


	double GetSize() const {
		return size;
	}
protected :
	bool debug;
	bool display_list;
	double x;
	double y;
	double z;
	double size;
	int nbtexture;
	std::string Data_Dir;
	GLuint *id_texture;
	GLuint id_display_list;
	
};

#endif // OBJECT_H
