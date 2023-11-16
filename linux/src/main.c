#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;
#include <stdlib.h>
#include <string.h>
#define GLEW_STATIC
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include<GL/freeglut.h>
#include"game.h"

#define LARGEUR 960
#define HAUTEUR 540

int windowsName;

using namespace glm;
game g;
void draw();
void gestionSpecial(int key, int x, int y);
void gestionSpecialUp(int key, int x, int y);
void normalKeys(unsigned char key, int x, int y);
void normalKeysUp(unsigned char key, int x, int y);
char name;
int main( int argc, char *argv[ ], char *envp[ ] )

{	 

	glutInit(&argc,argv);
	glutInitWindowSize(LARGEUR,HAUTEUR);
	glutInitWindowPosition(100,100); 
	glutInitDisplayMode(GLUT_RGBA|GLUT_DOUBLE|GLUT_DEPTH | GLUT_STENCIL);
	windowsName=glutCreateWindow("car game OpenGL 3.3");

	// Initialize GLEW
	glewExperimental = true; // Needed for core profile
	if (glewInit() != GLEW_OK) {
		fprintf(stderr, "Failed to initialize GLEW\n");
		getchar();
		//glfwTerminate();
		return -1;
	}

 glEnable(GL_DEPTH_TEST);
 glDepthFunc(GL_LESS);
 g.initGL();
 glutDisplayFunc(draw);
 glutSpecialFunc(gestionSpecial);
 glutSpecialUpFunc(gestionSpecialUp);
 glutKeyboardFunc(normalKeys);
 glutKeyboardUpFunc(normalKeysUp);
 glutPostRedisplay();
 glutMainLoop();

return 0;
 
}	 
void draw()
{



	g.draw();
}
void gestionSpecial(int key, int x, int y)
{
	g.gestionSpecial(key,x,y);
}
void gestionSpecialUp(int key, int x, int y)
{
	g.gestionSpecialUp(key,x,y);
}
void normalKeys(unsigned char key, int x, int y)
 {
 	g.normalKeys( key,  x, y);
 }
 void normalKeysUp(unsigned char key, int x, int y)
 {
 	g.normalKeysUp( key,  x,  y);
 }
