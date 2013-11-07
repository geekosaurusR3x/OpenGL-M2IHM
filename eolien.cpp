#include "eolien.h"

Eolien::Eolien()
{
	pas = 0;
}

Eolien::~Eolien()
{
}

void Eolien::Draw(double Wind,GLUquadric* params)
{
	pas++;
	double angle = Wind*(pas%360);
	glColor3d(1,0,0);

    glPushMatrix();
        glTranslated(1.0,1.2,-6);
        glRotated(80,1,0,0);
        gluCylinder(params,0.2,0.3,3.5,16,16);
    glPopMatrix();

    glPushMatrix();
        glTranslated(1.0,1.2,-6);
        glRotated(80,1,0,0);
        glutSolidCube(0.7);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.9,1.1,-5);
        glRotated(0,1,0,0);
        glRotated(angle,0,0,1);
        glutSolidTorus(0.1,0.1,16,16);
    glPopMatrix();

    glPushMatrix();
        glTranslated(0.9,1.1,-5);
        glRotated(0,1,0,0);
        glRotated(angle,0,0,1);
        glBegin(GL_POLYGON);
            glVertex3f(0,2,0);
            glVertex3f(-0.14,0.2,0);
            glVertex3f(0,0,0);
            glVertex3f(0.14,0.2,0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex3f(-0.32,-0.1,0);
            glVertex3f(-1.5,-1.2,0);
            glVertex3f(-0.12,-0.34,0);
            glVertex3f(0,0,0);
        glEnd();
        glBegin(GL_POLYGON);
            glVertex3f(0.12,-0.34,0);
            glVertex3f(1.5,-1.2,0);
            glVertex3f(0.32,-0.1,0);
            glVertex3f(0,0,0);
        glEnd();
    glPopMatrix();
}
