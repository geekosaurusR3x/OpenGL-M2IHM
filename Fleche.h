#ifndef FLECHE_H
#define FLECHE_H
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Couleur.h"

class Fleche
{
    public:
        Fleche(double x, double y, double z);
        Fleche();
        virtual ~Fleche();
        void Draw(double camX,double camY,double camZ,int OrientationVent);
    protected:
    private:
        double posx;
        double posy;
        double posz;
        double* Couleur;
};

#endif // FLECHE_H
