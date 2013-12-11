#ifndef SKYBOX_H
#define SKYBOX_H
#define TEXTURE_SKYBOX_1 1
#define TEXTURE_SKYBOX_2 2
#define TEXTURE_SKYBOX_NAME_1 "clouds"
#define TEXTURE_SKYBOX_NAME_2 "stars"

#include "object.h"

class SkyBox : public Object
{
public:
	SkyBox();
	SkyBox(double X,double Y,double Z,double Size);
	~SkyBox();
	void LoadChild();
	void LoadTexture(int num);
	void DrawChild();
private:

};

#endif // SKYBOX_H
