#ifndef WORLD_H
#define WORLD_H

#include "eolien.h"
#include "fonctions.h"
#include "Couleur.h"
#include "Fleche.h"

#include <vector>
#include <string>

#define TEXTURE_SKYBOX_1 1
#define TEXTURE_SKYBOX_2 2
#define TEXTURE_SKYBOX_NAME_1 "city"
#define TEXTURE_SKYBOX_NAME_2 "iceflow"
class World
{
public:
	World(double Largeur,double Profondeur,double Hauteur);
	~World();
	void SetWind(double Wind);
	double GetWind() const;
	void SetDebug(bool debug);
	bool IsDebug() const;
	double GetHauteur() const ;
	double GetProfondeur() const ;
	double GetLargeur() const;
	void LoadWorld();
	void RemoveEoliene();
	void AddEoliene();
	void LoadTextureSkybox(int num);
	void Draw(double camX,double camY,double camZ);

	void SetOrientationWind(int Orientation_Wind);
	int GetOrientationWind() const;
	
	void SetNumTexture(int NumTexture);

private:
	bool debug;
	double Wind;
	int SpaceEolien;
	int nbEoliene;
	double Largeur;
	double Profondeur;
	double Hauteur;
	int Orientation_Wind;

	GLuint texture_skybox[6];
	std::vector<Eolien> ListeEolien;

	Fleche Arrow;

	void DrawObject(double camX,double camY,double camZ);
	void DrawSky();
};

#endif // WORLD_H
