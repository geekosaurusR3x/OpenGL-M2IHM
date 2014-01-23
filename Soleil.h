#ifndef SOLEIL_H
#define SOLEIL_H

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif


class Soleil
{
    public:
        Soleil(int light=GL_LIGHT0, GLfloat posx=0.0f, GLfloat posy=0.0f, GLfloat posz=1.0f);
        virtual ~Soleil();
        void Draw();
        void Interupteur();
        void setPosition(GLfloat posx, GLfloat posy, GLfloat posz);
    protected:
    private:
        bool allumee;
        int lumiere;
        //source directionnelle
        GLfloat Lumiere_Position[4];
        GLfloat Lumiere_Ambiante[4] = { 0.0f, 0.0f, 0.0f, 1.0f };
        GLfloat Lumiere_Diffuse[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
        GLfloat Lumiere_Speculaire[4] = { 1.0f, 1.0f, 1.0f, 1.0f };
};

#endif // SOLEIL_H
