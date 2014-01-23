#include "Lumieres.h"

Lumieres::Lumieres()
{
	glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
    glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHT0);
	glEnable(GL_LIGHT1);
	glEnable(GL_LIGHT2);
	glEnable(GL_LIGHT3);
	glEnable(GL_LIGHT4);
    glEnable(GL_LIGHTING);

    glMaterialfv(GL_FRONT_AND_BACK,GL_SPECULAR,this->Materiaux_Speculaire);
    glMateriali(GL_FRONT_AND_BACK,GL_SHININESS,this->Brillance_Materiaux);
	
    soleil = Soleil(GL_LIGHT0,0,300,0);
    projecteur1 = Projecteur(GL_LIGHT1,100,300,100,0,0,0);
    projecteur2 = Projecteur(GL_LIGHT2,-100,300,-100,0,0,0);
    projecteur3 = Projecteur(GL_LIGHT3,100,300,-100,0,0,0);
    projecteur4 = Projecteur(GL_LIGHT4,-100,300,100,0,0,0);
}

Lumieres::~Lumieres()
{
    //dtor
}

void Lumieres::Draw()
{

    soleil.Draw();
    projecteur1.Draw();
    projecteur2.Draw();
    projecteur3.Draw();
    projecteur4.Draw();
}

void Lumieres::Interupteur_p1()
{
    projecteur1.interupteur();
}

void Lumieres::Interupteur_p2()
{
    projecteur2.interupteur();
}

void Lumieres::Interupteur_p3()
{
    projecteur3.interupteur();
}

void Lumieres::Interupteur_p4()
{
    projecteur4.interupteur();
}

void Lumieres::Interupteur_soleil()
{
    soleil.Interupteur();
}
