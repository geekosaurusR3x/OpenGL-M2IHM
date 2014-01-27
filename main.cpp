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
#include <string>
#include "world.h"
#include "cam_rotate.h"
#include "cam_free.h"
#include "Couleur.h"
#include "terminal.h"
#include "loger.h"

//fin des includes 

//defines
#define no_argument 0
#define required_argument 1 
#define optional_argument 2
#define DATA_DIR "Datas"
#define WIDTH 800
#define HEIGHT 600
//fin defines

using namespace std;

bool debug;
bool terminal;
bool help;
bool free_cam = false;
bool under_five_fps = false;

World Monde(1024.0);
Terminal Term;
CamRotate Camm_fixe(0.0,200.0,0.0);
CamFree Camm_free(0.0,0.0,0.0);
Camera * Camm;
Loger *mylog;


double scrollSensivity = 2.0;

double current_time = 0;
double last_time = 0;
double start_time_minus_five_fps = 0;
int nb_frames=0;
int winIdMain;
int winIdSub;
int winHelp;

//exit func
void MyExit()
{
	mylog->kill();
	 exit(EXIT_SUCCESS);
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

static void subReshape (int w, int h)
{
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,w,0,h);
	glMatrixMode(GL_MODELVIEW);
}
static void display(void)
{	
	glutSetWindow (winIdMain);
	glClear (GL_COLOR_BUFFER_BIT);
	glClear (GL_DEPTH_BUFFER_BIT);

	glPushMatrix();
	glLoadIdentity ();
	
	Camm->LookAt();
	Monde.Draw();
	glPopMatrix();
	//calcul des fps
	nb_frames++;
	current_time = glutGet(GLUT_ELAPSED_TIME);
	if ((current_time - last_time) >= 1.0)
    {
      Term.SetFps((nb_frames/ (current_time - last_time))*1000);
      nb_frames = 0;
      last_time = current_time;
    }
	if(under_five_fps && Term.GetFps() > 5)
	{
		under_five_fps = false;
		mylog->Append("Passage au dessus des 5 fps");
	}
	if (Term.GetFps() <= 5 && Monde.IsBench())
	{
		
		if(!under_five_fps)
		{
			start_time_minus_five_fps = current_time;
			under_five_fps = true;
			mylog->Append("Passage en desous des 5 fps");
		}
		
		if((current_time - start_time_minus_five_fps)>=15000.0) //15seconds
		{
				Monde.StopBench();
				under_five_fps = false;
		}
	}
    glutSwapBuffers();
}

static void subDisplay ()
{

  /* Clear subwindow */
  glutSetWindow (winIdSub);
  glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Term.Draw();
  glutSwapBuffers ();
}

static void helpDisplay()
{
	glutSetWindow(winHelp);
    glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	Term.WriteLine(2,2,"F1 pour afficher / masquer l'aide ",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,17,"a pour afficher / masquer le terminal ",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,34,"e pour quitter ",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,51,"c pour changer de mode de camera ",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,68,"<- -> pour changer l'orientation du vent ",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,85,"Click droit pour afficher le menu contextuel",GLUT_BITMAP_9_BY_15);
	
	Term.WriteLine(2,585,"En mode camera freefly :",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,568,"z pour avance",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,551,"q pour se deplacer vers la gauche",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,534,"d pour se deplacer vers la droite",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,517,"s pour reculer",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(2,500,"Bouger les sourie pour bouger le curseur",GLUT_BITMAP_9_BY_15);
	
	Term.WriteLine(350,585,"En mode camera tournante :",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(350,568,"Molette de la sourie pour zoomer/dezoomer",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(350,551,"Click gauche pour arreter/stoper le mouvement",GLUT_BITMAP_9_BY_15);
	
	Term.WriteLine(200,385,"Dans le terminal :",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(200,368,"Molette de la sourie pour monter descendre le log",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(200,351,"Taper un texte pour utiliser l'interpreteur :",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(220,334,"exit pour quitter",GLUT_BITMAP_9_BY_15);
	Term.WriteLine(220,317,"World.fog 0/1 pour afficher masquer le brouillard",GLUT_BITMAP_9_BY_15);
	
	glutSwapBuffers ();
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
			if(free_cam)
			{
				Camm = &Camm_free;
				glutSetCursor(GLUT_CURSOR_CROSSHAIR);
			}
			else
			{
				Camm = &Camm_fixe;
				glutSetCursor(GLUT_CURSOR_INFO);
			}
			mylog->Append("Free Cam : "+to_string(free_cam));
			break;
		case 'a':
			terminal = !terminal;
			mylog->Append("Terminal : "+to_string(terminal));
			break;
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
			Monde.TogleLight(key);
			break;
		
	}

	glutPostWindowRedisplay(winIdMain);
	glutPostWindowRedisplay(winIdSub);
}

void Interprate(std::string cmd)
{
	stringstream stream(cmd);
	string val;
	getline(stream, val, '.');
	if(val == INTERPRATE_NAME_WORLD)
	{
		getline(stream, val, '.');
		Monde.Interprate(val);
	}
	else if( val == "exit")
	{
		MyExit();
	}
	else if( val == "start bench")
	{
		Monde.StartBench();
	}
	else if( val == "stop bench")
	{
		Monde.StopBench();
	}
	else
	{
		mylog->Append("Master : "+val+" unknow commande");
	}
}

static void Subkey(unsigned char key, int x, int y)
{
	switch(key)
	{
		case 8: //backspace
			Term.Remove();
			break;
		case 13: //enterkey
			Interprate(Term.Validate());
			break;
		default:
			string temp = "";
			temp+=key;
			Term.Append(temp);
			break;
	}
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
		case GLUT_KEY_F1 :
			help = !help;
			
    }
}

void mouseMove(int x, int y) 
{
	//mylog->Append("x: "+to_string(x)+" y:"+to_string(y));
	int camx = -(x-(WIDTH/2));
	int camy = y-(HEIGHT/2);
	if(free_cam){Camm_free.OnMouseMotion(camx,camy);}
	
}

void mouseButton(int button, int state, int x, int y) 
{
	if (button == GLUT_LEFT_BUTTON) {
		if (state == GLUT_DOWN && !free_cam) {
			Camm_fixe.TogleRotate();
			mylog->Append("Toggle Rotation : "+to_string(Camm_fixe.IsRotateCam()));
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

void SubmouseButton(int button, int state, int x, int y) 
{

	if (button == 3)
	{
		Term.PreviousLine();
	}
	if (button == 4)
	{
		Term.NextLine();
	}
}

static void idle(void)
{
	if(free_cam){Camm_free.SetY(Monde.GetHauteur(Camm_free.GetX(),Camm_free.GetZ())+4);}
	Camm->Update();
	Monde.Update(Camm->GetFlecheX(),Camm->GetFlecheY(),Camm->GetFlecheZ());

	  glutSetWindow (winIdSub);
	  if (terminal)
	  {
		  glutShowWindow();
	  }
	  else
	  {
		  glutHideWindow();
	  }

	  glutSetWindow (winHelp);
	  if (help)
	  {
		  glutShowWindow();
	  }
	  else
	  {
		  glutHideWindow();
	  }
	  
	glutPostWindowRedisplay(winIdMain);
	glutPostWindowRedisplay(winIdSub);
	glutPostWindowRedisplay(winHelp);
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

void HelpEnableMenu(int choice)
{
	switch(choice) {
		case 0 : help = true;break;
		case 1 : help = false;break;
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
    case -1 : MyExit(); break;
	}
						
}

void SelectBench(int choice)
{
	switch(choice) {
    case 0 : Monde.StartBench(); break;
	case 1 : Monde.StopBench(); break;
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
	debug = false;
	terminal = false;
	string datadir = DATA_DIR;
	mylog = Loger::getInstance();
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
			debug = true;
			break;
		  case 'd':
			cout <<"Other Data Dir passed : "<<optarg<<endl;
			datadir = optarg;
			break;
		}
	  }
	//fin

	mylog->SetDebug(debug);
    glutInit(&argc, argv);
    glutInitWindowSize(WIDTH,HEIGHT);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowPosition(10,10);
    winIdMain = glutCreateWindow("Projet OPENGL");

	int BenchMenu = glutCreateMenu(SelectBench);
		glutAddMenuEntry("Start",0);
		glutAddMenuEntry("Stop",1);
		
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
		
	int HelpMenu = glutCreateMenu(HelpEnableMenu);
		glutAddMenuEntry("Oui",0);
		glutAddMenuEntry("Non",1);
          
	int MapMenu = glutCreateMenu(TextureMapMenu);
		glutAddMenuEntry("Texture herbe",TEXTURE_MAP_1);
		glutAddMenuEntry("Texture Zerg",TEXTURE_MAP_2);
		
	glutCreateMenu(SelectChoice);
		glutAddSubMenu("Benchmark",BenchMenu);
		glutAddSubMenu("Force du vent",WindMenu);
		glutAddSubMenu("Eoliennes",EolMenu);
		glutAddSubMenu("BugDroid",BugASMenu);
		glutAddSubMenu("Changer Skybox",SkyMenu);
		glutAddSubMenu("Brouyard",FogMenu);
		glutAddSubMenu("Sol",MapMenu);
		glutAddSubMenu("Aide",HelpMenu);
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

	Monde.SetDataDir(datadir);
	Monde.LoadWorld();
	glutSetCursor(GLUT_CURSOR_INFO);
	//fin fenetre principale
	//sous fenetre
	winIdSub = glutCreateSubWindow (winIdMain, 0, 0, WIDTH, HEIGHT / 3);
	glutReshapeFunc(subReshape);
	glutDisplayFunc(subDisplay);
	glutMouseFunc(SubmouseButton);
	glutKeyboardFunc(Subkey);
	glutHideWindow();
	//fenetre d'aide
	glutInitWindowPosition(200,200);
	winHelp = glutCreateWindow ("Help");
	glutReshapeFunc(subReshape);
	glutDisplayFunc(helpDisplay);
	glutSpecialFunc(special);
	glutHideWindow();
	
	//fin initialisation OPENGL
	//init autre
	Camm = &Camm_fixe; //on commence avec la cam fixe
	//lancement
	glutMainLoop();

	MyExit();
    return EXIT_FAILURE;
}