#include "water.h"

using namespace std;
Water::Water()
{
	Water(0,0,0,1);
}

Water::Water(double X,double Y,double Z,double Size):Object(X,Y,Z,Size)
{
}

Water::~Water()
{
}
void Water::Draw()
{
	glDisable(GL_LIGHTING);
	//glEnable(GL_TEXTURE_2D);
	glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glColor4ub(100,100,255,128);
	glBindTexture(GL_TEXTURE_2D, texture_water[0]);
	glBegin(GL_TRIANGLE_STRIP);
	for (int j = 0; j < this->size-1; j++) {
		for (int i = 0; i < this->size-1; i++) {
			glTexCoord2f(0.0f, 0.0f);
			glVertex3f(water[i][j][0], water[i][j][1], water[i][j][2]);

			glTexCoord2f(1.0f, 0.0f);
			glVertex3f(water[i][j+1][0],water[i][j+1][1],water[i][j+1][2]);

			glTexCoord2f(0.0f, 1.0f);
			glVertex3f(water[i+1][j][0],water[i+1][j][1],water[i+1][j][2]);

			glTexCoord2f(1.0f, 1.0f);
			glVertex3f(water[i+1][j+1][0],water[i+1][j+1][1],water[i+1][j+1][2]);

		}
	}
	glEnd();
	glDisable(GL_BLEND);
	glDisable(GL_TEXTURE_2D);
	glEnable(GL_LIGHTING);
}

void Water::Load()
{
	GenerateWater();
	LoadTexture();
}

void Water::SetSizeWordl(double Size_Wordl)
{
	this->Size_Demi_Wordl = Size_Wordl/2;
	this->Map_Scale = Size_Wordl/this->size;

	if(debug) {
		cout<<"Demi Wordl : "<<Size_Demi_Wordl<<" Map Scale : "<<Map_Scale<<endl;
	}
}
void Water::Update()
{
	//genere les pseudos vagues
	for (int j = 0; j < this->size-1; j++) {
		for (int i = 0; i < this->size-1; i++) {
			water[i][j][1] = this->y+(5*sin(glutGet(GLUT_ELAPSED_TIME)/300));
		}
	}
	
}

void Water::GenerateWater()
{
	if(debug) {
		cout<<"Generation de la mer....."<<endl;
	}
	water = new double**[(int)this->size];
	for(int i = 0; i < (int)this->size; i++) {
		water[i] = new double *[(int)this->size];
		for(int j = 0; j < (int)this->size; j++) {
			water[i][j] = new double[3];
		}
	}

	for(int i = 0; i < (int)this->size; i++) {
		for(int j = 0; j < (int)this->size; j++) {
			water[j][i][0] = (double(j)*Map_Scale)+this->x;
			water[j][i][1] = this->y;
			water[j][i][2] = -(double(i)*Map_Scale)+this->z;
			if(debug) {
				cout<<water[j][i][0]<<" "<<water[j][i][1]<<" "<<water[j][i][2]<<endl;
			}
		}
	}

	if(debug) {
		cout<<"Generation de la mer FINIT"<<endl;
	}
}

void Water::LoadTexture()
{
	unsigned char *Texture = 0;
	glGenTextures(1, texture_water);
	try {
		struct jpeg_decompress_struct cinfo;
		Texture = loadJpegImage(this->Data_Dir+"/Textures/water.jpg",&cinfo);
	} catch (const jpeg_load_exception &e) {
		if (debug) {
			cout<<e.what()<<endl;
		}
	}
	setTexture(Texture,this->size,this->size,texture_water[0]);
}
