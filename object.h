#ifndef OBJECT_H
#define OBJECT_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <string>

class Object
{
public:
	Object();
	Object(double X,double Y,double Z,double Size);
	virtual ~Object()=0;
	virtual void Load();
	virtual void Draw();
	virtual void Update();


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
	double x;
	double y;
	double z;
	double size;
	std::string Data_Dir;
};

#endif // OBJECT_H
