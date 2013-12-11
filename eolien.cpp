#include "eolien.h"

Eolien::Eolien()
{
	Eolien(0,0,0,1);
}
Eolien::Eolien(double X, double Y, double Z,double Zoom):Object(X,Y,Z,Zoom)
{
	this->color = rougeFonce;
	this->pas = 0;
}

Eolien::~Eolien()
{
}

void Eolien::DrawChild()
{
   //vitesse de rotation des pales
    double Periode = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    //orientation du vent
    double Vitesse_Rotation = Periode * (double)this->Wind;

    GLUquadric* params = gluNewQuadric();
    gluQuadricDrawStyle(params,GLU_FILL);
    //couleur de l'éolienne
    glColor4dv(this->color);
	glPushMatrix();
		glTranslated(this->x,this->y,this->z);
		glScalef(this->size+2, this->size+2, this->size+2);
		glTranslated(0,2,0);
		glPushMatrix();
			//pied de l'eolienne
			glPushMatrix();
				glRotated(90,1,0,0);
				gluCylinder(params,0.10,0.15,2.5,50,50);
			glPopMatrix();

			//tete de l'eolienne
			glPushMatrix();
				glRotated((double)this->OrientationVent,0,1,0);
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
	glPopMatrix();
}

void Eolien::SetColor(int color)
{
	switch(color)
	{
		case EOLIEN_COULEUR_1:  this->color = rougeFonce;break;
        case EOLIEN_COULEUR_2 : this->color = grisClair ;break;
        case EOLIEN_COULEUR_3 : this->color = blanc ;break;
        case EOLIEN_COULEUR_4 : this->color = magenta ;break;
			
	}
}
