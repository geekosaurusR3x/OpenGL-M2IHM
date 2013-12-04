#include "eolien.h"

Eolien::Eolien(double x, double y, double z)
{
	posx = x;
	posy = y;
	posz = z;
	pas = 0;
}

Eolien::~Eolien()
{
}

void Eolien::Draw(double Wind, double OrientationVent)
{
   //vitesse de rotation des pales
    double Periode = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    //orientation du vent
    double Vitesse_Rotation = Periode * (double)Wind;

    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
    //couleur de l'éolienne
    glColor4dv(rougeFonce);
    glPushMatrix();
        //pied de l'eolienne
        glPushMatrix();
            glTranslated(posx,posy,posz);
            glRotated(90,1,0,0);
            gluCylinder(params,0.10,0.15,2.5,50,50);
        glPopMatrix();

        //tete de l'eolienne
        glPushMatrix();
            glTranslated(posx,posy,posz);
            glRotated((double)OrientationVent,0,1,0);
            glPushMatrix();
                glTranslated(0,0,0.19);
                glutSolidTorus(0.075,0.075,15,15);
                glTranslated(0,0,-0.53);
                gluCylinder(params,0.15,0.15,0.55,50,50);
                glTranslated(0,0,0.035);
                glutSolidTorus(0.085,0.085,10,10);
            glPopMatrix();

            glPushMatrix();
                glTranslated(0,0,0.28);
                glRotated(Vitesse_Rotation,0,0,1);
                glutSolidCone(0.1,0.2,50,50);
                glutSolidTorus(0.05,0.05,10,10);
                glTranslated(0,0,0.05);
                //pale pointant vers le haut
                glBegin(GL_POLYGON);
                    glVertex3f(0,1.5,0);
                    glVertex3f(-0.12,0.5,-0.05);
                    glVertex3f(0,0,0);
                    glVertex3f(0.12,0.5,0.05);
                glEnd();
                //pale gauche
                glBegin(GL_POLYGON);
                    glVertex3f(-0.45,-0.1,-0.05);
                    glVertex3f(-1.35,-0.65,0);
                    glVertex3f(-0.35,-0.3,0.05);
                    glVertex3f(0,0,0);
                glEnd();
                //pale droite
                glBegin(GL_POLYGON);
                    glVertex3f(0.35,-0.3,-0.05);
                    glVertex3f(1.35,-0.5,0);
                    glVertex3f(0.45,-0.1,0.05);
                    glVertex3f(0,0,0);
                glEnd();
            glPopMatrix();
        glPopMatrix();
    glPopMatrix();
}

