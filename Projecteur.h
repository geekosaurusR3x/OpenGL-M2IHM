#ifndef PROJECTEUR_H
#define PROJECTEUR_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

class Projecteur
{
    public:
        Projecteur(int light=GL_LIGHT1,GLfloat posx =0.0f,GLfloat posy=0.0f,GLfloat posz=0.0f,
                   GLfloat dirx=0,GLfloat diry=0,GLfloat dirz=-9);
        virtual ~Projecteur();
        void Draw();
        void interupteur();
    protected:
    private:
        bool allumee;
        int lumiere;
        //source ponctuelle
        GLfloat Lumiere_Position[4];
        GLfloat Lumiere_Ambiante[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        GLfloat Lumiere_Diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat Lumiere_Speculaire[4]= { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat Lumiere_Spot_Direction[3];
};

#endif // PROJECTEUR_H
