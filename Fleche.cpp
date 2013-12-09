#include "Fleche.h"
Fleche::Fleche()
{
	Fleche(1,-1,-6,1);
}
Fleche::Fleche(double x, double y, double z,double size):Object(x,y,z,size)
{
    this->Couleur = vertFonce;
}

Fleche::~Fleche()
{
    //dtor
}

void Fleche::Draw()
{
    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4dv(this->Couleur);

    glPushMatrix();
        glTranslated(this->x,this->y,this->z);
        glRotated(this->OrientationVent,0,1,0);
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
	glDisable(GL_BLEND);
}

void Fleche::Update()
{
	float alpha = this->ForceVent/240.0f;
	if(alpha == 0.0){alpha = 0.1;}
	this->Couleur[3]=alpha;
}
