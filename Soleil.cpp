#include "Soleil.h"

Soleil::Soleil(int light, GLfloat posx, GLfloat posy, GLfloat posz)
{
    this->lumiere = light;
    this->allumee=false;
    this->Lumiere_Position[0] = posx;
    this->Lumiere_Position[1] = posy;
    this->Lumiere_Position[2] = posz;
    this->Lumiere_Position[3] = 0.0f;
}

Soleil::~Soleil()
{
    //dtor
}

void Soleil::Draw()
{
    glLightfv(this->lumiere, GL_POSITION, this->Lumiere_Position);
    glLightfv(this->lumiere, GL_AMBIENT,  this->Lumiere_Ambiante);
    glLightfv(this->lumiere, GL_DIFFUSE,  this->Lumiere_Diffuse);
    glLightfv(this->lumiere, GL_SPECULAR, this->Lumiere_Speculaire);
}

void Soleil::Interupteur()
{
    //si la lumière est déjà allumer on l'éteint
    if(this->allumee)
    {
        glDisable(this->lumiere);
        glutPostRedisplay();
    }
    //sinon on l'allume
    else
    {
        glEnable(this->lumiere);
        glutPostRedisplay();
    }
    this->allumee=!this->allumee;
}

void Soleil::setPosition(GLfloat posx, GLfloat posy, GLfloat posz)
{
    this->Lumiere_Position[0] = posx;
    this->Lumiere_Position[1] = posy;
    this->Lumiere_Position[2] = posz;
}
