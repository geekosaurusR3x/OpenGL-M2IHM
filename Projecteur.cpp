#include "Projecteur.h"

Projecteur::Projecteur(int light,GLfloat posx,GLfloat posy,GLfloat posz,GLfloat dirx,GLfloat diry,GLfloat dirz)
{
    this->allumee=false;
    this->lumiere=light;
    Lumiere_Position[0] = posx;
    Lumiere_Position[1] = posy;
    Lumiere_Position[2] = posz;
    Lumiere_Position[3] = 1.0f;

    Lumiere_Spot_Direction[0] = dirx;
    Lumiere_Spot_Direction[1] = diry;
    Lumiere_Spot_Direction[2] = dirz;
}

Projecteur::~Projecteur()
{
    //dtor
}

void Projecteur::Draw()
{
    glLightfv(this->lumiere, GL_POSITION, this->Lumiere_Position);
    glLightfv(this->lumiere, GL_AMBIENT,  this->Lumiere_Ambiante);
    glLightfv(this->lumiere, GL_DIFFUSE,  this->Lumiere_Diffuse);
    glLightfv(this->lumiere, GL_SPECULAR, this->Lumiere_Speculaire);

    glLightfv(this->lumiere,GL_SPOT_DIRECTION,this->Lumiere_Spot_Direction);
    glLightf(this->lumiere,GL_SPOT_CUTOFF,90);
    glLightf(this->lumiere,GL_SPOT_EXPONENT,1);
    glPushMatrix();
        glTranslated(Lumiere_Position[0],Lumiere_Position[1],Lumiere_Position[2]);
        glRotatef(0,Lumiere_Position[0],Lumiere_Position[1],Lumiere_Position[2]);
        glutSolidCone(0.2,0.6,20,20);
    glPopMatrix();
}

void Projecteur::interupteur()
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
