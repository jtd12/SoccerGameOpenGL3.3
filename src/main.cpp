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
#include <C:\glew-1.13.0\include\GL\glew.h>
#include <C:\glm\glm\glm.hpp>
#include <C:\glm\glm\glm.hpp>
#include <C:\glm\glm\gtc\matrix_transform.hpp>
#include"C:\freeglut\include\GL\freeglut.h"
#include"game.h"

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





int windowName;
glutInit(&argc, argv);
glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
glutInitWindowSize(960,540);	//Optionnel
windowName = glutCreateWindow("Soccer game OpenGL Modern!");

glewExperimental=true; // Needed in core profile
if (glewInit() != GLEW_OK) {
    fprintf(stderr, "Failed to initialize GLEW\n");
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
