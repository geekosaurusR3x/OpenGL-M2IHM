#ifndef SKYBOX_H
#define SKYBOX_H
#define TEXTURE_SKYBOX_1 1
#define TEXTURE_SKYBOX_2 2
#define TEXTURE_SKYBOX_NAME_1 "clouds"
#define TEXTURE_SKYBOX_NAME_2 "stars"

#include "object.h"
#include "fonctions.h"

class SkyBox : public Object
{
public:
	SkyBox();
	SkyBox(double X,double Y,double Z,double Size);
	~SkyBox();
	void Load();
	void LoadTexture(int num);
	void Draw();
	void GenDisplayList();
private:
	GLuint texture_skybox[6];
	GLuint display_list;
};

#endif // SKYBOX_H
