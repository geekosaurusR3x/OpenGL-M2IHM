//include specifique a window
#ifdef __WINDOWS__
#include <windows.h>
#endif

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <getopt.h>
#include "world.h"
#include "sky_box.h"
#include "camera.h"

//fin des includes 

//defines
#define no_argument 0
#define required_argument 1 
#define optional_argument 2
//fin defines

using namespace std;

bool debug = true;
World Monde(1024.0,1024.0,1024.0);
MyCamera Camm;
double scrollSensivity = 2.0;

/* GLUT callback Handlers */

static void resize(int width, int height)
{
	if (height==0){height=1;}

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0f,(GLfloat)width/(GLfloat)height, 1 ,2048.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void display(void)
{	
	glLoadIdentity ();
	glClear (GL_COLOR_BUFFER_BIT);
	glClear (GL_DEPTH_BUFFER_BIT);

	Camm.PositonCamera(Monde.GetLargeur()/2.0,-(Monde.GetProfondeur()/2.0));
	Monde.Draw(Camm.GetFlecheX(),Camm.GetFlecheY(),Camm.GetFlecheZ());
	
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'q':
			exit(0);
			break;
		case 'r':
			break;
		case '-':
			break;
	}

	glutPostRedisplay();
}

void special(int key, int x, int y)
{
    switch (key)
    {
        case GLUT_KEY_LEFT :
			Monde.SetOrientationWind(5);
            break;

        case GLUT_KEY_RIGHT :
			Monde.SetOrientationWind(-5);
            break;
    }
}

void mouseMove(int x, int y) 
{ 	
}

void mouseButton(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN) {
			Camm.TogleRotate();
			if(debug){cout<<"Toggle Rotation : "<<Camm.IsRotateCam()<<endl;}
		}
	}
	if (button == 3)
	{
		Camm.SetRayonRotation(Camm.GetRayonRotation()-scrollSensivity);
		if(debug){cout<<"Zoom : "<<Camm.GetRayonRotation()<<endl;}
	}
	if (button == 4)
	{
		Camm.SetRayonRotation(Camm.GetRayonRotation()+scrollSensivity);
		if(debug){cout<<"Zoom : "<<Camm.GetRayonRotation()<<endl;}
	}
}


static void idle(void)
{
    glutPostRedisplay();
}

void WindChange(int choice)
{
	Monde.SetWind(choice);
}

void EolieneMenu(int choice)
{
	switch(choice) {
    case 1 : Monde.AddEoliene();break;
	case 2 : Monde.RemoveEoliene();break;
	}
}

void SkyBoxMenu(int choice)
{
	Monde.ChangeSkybox(choice);
}

void FogEnableMenu(int choice)
{
	switch(choice) {
		case 0 : Monde.FogOn();break;
		case 1 : Monde.FogOff();break;
	}
}

void SelectChoice(int choice)
{
	switch(choice) {
    case -1 : exit(EXIT_SUCCESS); break;
	}
						
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, 5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

/* Program entry point */

int main(int argc, char *argv[])
{
	debug = true;
	//parsage des arguments
	const struct option longopts[] =
	{
		{"help", no_argument, 0, 'h'},
		{"debug", no_argument, 0, 'd'},
		{0,0,0,0}
	};
	
	int index;
	int OptArg=0;
	
	 //turn off getopt error message
	  opterr=1; 

	  while(OptArg != -1)
	  {
		OptArg = getopt_long(argc, argv, "d:h", longopts, &index);

		switch (OptArg)
		{
		  case 'h':
			cout << "Debug Mode : -d or --debug" << endl;
			break;
		  case 'd':
			cout << "Debug Mode Active"<<endl;
			debug=true;
			break;
		}
	  }
	//fin

    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    glutCreateWindow("Projet OPENGL");

	int WindMenu = glutCreateMenu(WindChange);
		glutAddMenuEntry("Nul",0);
		glutAddMenuEntry("Lent",80);
		glutAddMenuEntry("Moyen",160);
		glutAddMenuEntry("Rapide",240);

	int EolMenu = glutCreateMenu(EolieneMenu);
		glutAddMenuEntry("Ajouter Eolienne",1);
		glutAddMenuEntry("Supprimer Eolienne",2);
		
	int SkyMenu = glutCreateMenu(SkyBoxMenu);
		glutAddMenuEntry("Ville",TEXTURE_SKYBOX_1);
		glutAddMenuEntry("Glace",TEXTURE_SKYBOX_2);
		
	int FogMenu = glutCreateMenu(FogEnableMenu);
		glutAddMenuEntry("Oui",0);
		glutAddMenuEntry("Non",1);
          
	glutCreateMenu(SelectChoice);
		glutAddSubMenu("Force du vent",WindMenu);
		glutAddSubMenu("Eoliennes",EolMenu);
		glutAddSubMenu("Changer Skybox",SkyMenu);
		glutAddSubMenu("Brouyard",FogMenu);
		glutAddMenuEntry("Quitter",-1);
	//menu		

	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
	glutMouseFunc(mouseButton);
	glutMotionFunc(mouseMove);
    glutIdleFunc(idle);

    glClearColor(1,1,1,1);
    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

	//fin initialisation OPENGL
	//init autre
	Monde.SetDebug(debug);
	Monde.LoadWorld();
	//lancement
	glutMainLoop();

    return EXIT_SUCCESS;
}
