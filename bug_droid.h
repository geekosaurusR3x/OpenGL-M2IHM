#ifndef BUGDROID_H
#define BUGDROID_H

#include "object.h" // Base class: Object

class BugDroid : public Object
{
public:
	BugDroid();
	BugDroid(double X,double Y,double Z,double Size);
	~BugDroid();
	
	void LoadChild();
	
private :
	std::string name;
};

#endif // BUGDROID_H
