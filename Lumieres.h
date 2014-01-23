#ifndef LUMIERES_H
#define LUMIERES_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Soleil.h"
#include "Projecteur.h"

class Lumieres
{
    public:
        Lumieres();
        virtual ~Lumieres();
        void Draw();
        void Interupteur_p1();
        void Interupteur_p2();
        void Interupteur_p3();
        void Interupteur_p4();
        void Interupteur_soleil();
    protected:
    private:
        Soleil soleil;
        Projecteur projecteur1;
        Projecteur projecteur2;
        Projecteur projecteur3;
        Projecteur projecteur4;
        //matériaux
        GLint Brillance_Materiaux =100;
        GLfloat Materiaux_Ambient[4]    = { 0.7f, 0.7f, 0.7f, 1.0f };
        GLfloat Materiaux_Diffuse[4]    = { 0.8f, 0.8f, 0.8f, 1.0f };
        GLfloat Materiaux_Speculaire[4] = { 0.3f, 0.3f, 0.3f, 1.0f };
};

#endif // LUMIERES_H
