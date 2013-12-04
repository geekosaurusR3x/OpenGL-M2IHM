#include "Fleche.h"

Fleche::Fleche(double x, double y, double z)
{
    this->posx = x;
    this->posy = y;
    this->posz = z;
    this->Couleur = vertFonce;
}

Fleche::Fleche()
{
    this->posx = 1;
    this->posy = -1;
    this->posz = -6;
    this->Couleur=vertFonce;
}

Fleche::~Fleche()
{
    //dtor
}

void Fleche::Draw(double camX,double camY,double camZ,int OrientationVent)
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
    glColor4dv(Couleur);

    glPushMatrix();
        glTranslated(camX,camY,camZ);
        glRotated(OrientationVent,0,1,0);
        glPushMatrix();
            gluCylinder(params,0.025,0.025,0.2,25,25);
            glPopMatrix();
                glRotated(180,0,1,0);
                glutSolidTorus(0.025,0.025,10,10);
                glutSolidCone(0.05,0.15,50,50);
                glTranslated(0,0,-0.2);
                glutSolidTorus(0.014,0.014,10,10);
            glPushMatrix();
        glPopMatrix();
    glPopMatrix();
}
