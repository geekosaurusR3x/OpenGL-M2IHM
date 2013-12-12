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
#include <string.h>
#include "world.h"
#include "cam_rotate.h"
#include "cam_free.h"

//fin des includes 

//defines
#define no_argument 0
#define required_argument 1 
#define optional_argument 2
#define DATA_DIR "Datas"
//fin defines

using namespace std;

bool debug = true;
World Monde(1024.0);

CamRotate Camm_fixe(0.0,200.0,0.0);
CamFree Camm_free(0.0,0.0,0.0);
Camera * Camm;

double scrollSensivity = 2.0;
int frameCount = 0;
double camx_past = 0;
double camy_past = 0;
bool free_cam = false;

int winIdMain;
int winIdSub;

void output(GLfloat x, GLfloat y, std::string text)
{
    glPushMatrix();
    glTranslatef(x, y, 0);
    glScalef(1, 1, 1);
    for (int i = 0; i < (int)text.length(); i++)
    {
        glutStrokeCharacter(GLUT_STROKE_ROMAN, text[i]);
    }
    glPopMatrix();
}

/* GLUT callback Handlers */

static void resize(int width, int height)
{

	glViewport(0,0,width,height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(70,(double)width/height,1,1500);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void display(void)
{	
	glClear (GL_COLOR_BUFFER_BIT);
	glClear (GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glLoadIdentity ();
	
	Camm->LookAt();
	Monde.Draw();
	output(0,200,"test");
	glPopMatrix();
    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'z':
			if(free_cam){Camm_free.Avancer();}
			break;
		case 'q':
			if(free_cam){Camm_free.Gauche();}
			break;
		case 's':
			if(free_cam){Camm_free.Reculer();}
			break;
		case 'd':
			if(free_cam){Camm_free.Droite();}
			break;
		case 'e':
			exit(0);
			break;
		case 'c':
			free_cam = !free_cam;
			camx_past = x;
			camy_past = y;
			if(free_cam)
			{
				Camm = &Camm_free;
			}
			else
			{
				Camm = &Camm_fixe;
			}
			if(debug)
			{
				if(debug){cout<<"Free Cam : "<<free_cam<<endl;}
			}
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
	if(debug){cout<<"x: "<<x<<" y:"<<y<<endl;}
	int camx = x-camx_past;
	int camy = y-camy_past;
	if(free_cam){Camm_free.OnMouseMotion(camx,camy);}
	
}

void mouseButton(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN && !free_cam) {
			Camm_fixe.TogleRotate();
			if(debug){cout<<"Toggle Rotation : "<<Camm_fixe.IsRotateCam()<<endl;}
		}
	}
	if (button == 3 && !free_cam)
	{
		Camm_fixe.SetRayonRotation(Camm_fixe.GetRayonRotation()-scrollSensivity);
	}
	if (button == 4 && !free_cam)
	{
		Camm_fixe.SetRayonRotation(Camm_fixe.GetRayonRotation()+scrollSensivity);
	}
}


static void idle(void)
{
	if(free_cam){Camm_free.SetY(Monde.GetHauteur(Camm_free.GetX(),Camm_free.GetZ())+4);}
	Camm->Update();
	Monde.Update(Camm->GetFlecheX(),Camm->GetFlecheY(),Camm->GetFlecheZ());
    glutPostRedisplay();
}

void WindChange(int choice)
{
	Monde.SetWind(choice);
}

void AddSuppMenu(int choice)
{
	switch(choice) {
    case 1 : Monde.Add(EOLIENNE);break;
	case 2 : Monde.Remove(EOLIENNE);break;
    case 3 : Monde.Add(BUGDROID);break;
	case 4 : Monde.Remove(BUGDROID);break;
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

void TextureMapMenu(int choice)
{
	Monde.ChangeTextureMap(choice);
}

void EolColorMenu(int choice)
{
	Monde.ChangerColorEolienne(choice);
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
	srand (time(NULL));
	debug = true;
	string datadir = DATA_DIR;
	//parsage des arguments
	const struct option longopts[] =
	{
		{"help", no_argument, 0, 'h'},
		{"verbose", no_argument, 0, 'v'},
		{"datadir", required_argument, 0, 'd'},
		{0,0,0,0}
	};
	
	int index;
	int OptArg=0;
	
	 //turn off getopt error message
	  opterr=1; 

	  while(OptArg != -1)
	  {
		OptArg = getopt_long(argc, argv, "vd:h", longopts, &index);

		switch (OptArg)
		{
		  case 'h':
			cout << "Debug Mode : -v or --verbose" << endl;
			cout << "Specifi another Data Dir : -d or --datatdir exp: --datadir 'test' " << endl;
			break;
		  case 'v':
			cout << "Debug Mode Active"<<endl;
			debug=true;
			break;
		  case 'd':
			cout <<"Other Data Dir passed : "<<optarg<<endl;
			datadir = optarg;
			break;
		}
	  }
	//fin

    glutInit(&argc, argv);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(10,10);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);

    winIdMain = glutCreateWindow("Projet OPENGL");

	int WindMenu = glutCreateMenu(WindChange);
		glutAddMenuEntry("Nul",0);
		glutAddMenuEntry("Lent",80);
		glutAddMenuEntry("Moyen",160);
		glutAddMenuEntry("Rapide",240);

	int EolASMenu = glutCreateMenu(AddSuppMenu);
		glutAddMenuEntry("Ajouter Eolienne",1);
		glutAddMenuEntry("Supprimer Eolienne",2);
		
	int EolColMenu = glutCreateMenu(EolColorMenu);
		glutAddMenuEntry("Rouge Foncee",EOLIEN_COULEUR_1);
		glutAddMenuEntry("Gris",EOLIEN_COULEUR_2);
		glutAddMenuEntry("Blanc",EOLIEN_COULEUR_3);
		glutAddMenuEntry("Magenta",EOLIEN_COULEUR_4);

	int EolMenu = glutCreateMenu(AddSuppMenu);
		glutAddSubMenu("Ajouter / Supprimer",EolASMenu);
		glutAddSubMenu("Couleur",EolColMenu);
		
	int BugASMenu = glutCreateMenu(AddSuppMenu);
		glutAddMenuEntry("Ajouter BugDroid",3);
		glutAddMenuEntry("Supprimer BugDroid",4);
		
	int SkyMenu = glutCreateMenu(SkyBoxMenu);
		glutAddMenuEntry(TEXTURE_SKYBOX_NAME_1,TEXTURE_SKYBOX_1);
		glutAddMenuEntry(TEXTURE_SKYBOX_NAME_2,TEXTURE_SKYBOX_2);
		
	int FogMenu = glutCreateMenu(FogEnableMenu);
		glutAddMenuEntry("Oui",0);
		glutAddMenuEntry("Non",1);
          
	int MapMenu = glutCreateMenu(TextureMapMenu);
		glutAddMenuEntry("Texture herbe",TEXTURE_MAP_1);
		glutAddMenuEntry("Texture Zerg",TEXTURE_MAP_2);
		
	glutCreateMenu(SelectChoice);
		glutAddSubMenu("Force du vent",WindMenu);
		glutAddSubMenu("Eoliennes",EolMenu);
		glutAddSubMenu("BugDroid",BugASMenu);
		glutAddSubMenu("Changer Skybox",SkyMenu);
		glutAddSubMenu("Brouyard",FogMenu);
		glutAddSubMenu("Sol",MapMenu);
		glutAddMenuEntry("Quitter",-1);
	//menu		

	
	glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutSpecialFunc(special);
	glutMouseFunc(mouseButton);
	glutPassiveMotionFunc(mouseMove);
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
	Camm = &Camm_fixe; //on commence avec la cam fixe
	Monde.SetDebug(debug);
	Monde.SetDataDir(datadir);
	Monde.LoadWorld();
	//lancement
	glutMainLoop();

    return EXIT_SUCCESS;
}