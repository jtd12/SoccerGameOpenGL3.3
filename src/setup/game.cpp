#include"game.h"


game::game()
{
	
}
game::~game()
{
delete p;
}
void game::initGL()
{

p=new together();
}




void game::update()
{
p->update();

	
}



void game::draw()
{

update();
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClearColor(0.6,0.6,0.8,1.0);
p->draw();


		
glFlush();
glutSwapBuffers();
glutPostRedisplay();

}

void game::gestionSpecial(int key, int x, int y)
{
	p->gestionSpecial(key,x,y);
}
void game::gestionSpecialUp(int key, int x, int y)
{
	p->gestionSpecialUp(key,x,y);
}
void game::normalKeys(unsigned char key, int x, int y)
{
	p->normalKeys(key,x,y);
}
void game::normalKeysUp(unsigned char key, int x, int y)
{
		p->normalKeysUp(key,x,y);
}

