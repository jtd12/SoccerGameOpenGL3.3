#ifndef DEF_GAME_H
#define DEF_GAME_H
#include"stadium.h"
#include"balle.h"
#include"joueur.h"
#include"membres.h"
#include"camera.hpp"
#include"common/text2D.hpp"
#include"passsystem.hpp"
#include"guiTexture.hpp"
#include"supporter.hpp"

class game
{
	public:
		game();
		~game();
		void initGL();
		void draw();
		void loadSupporters();
		void update();
		void movementBall();
		void movement();
		void movementAI();
		void collisionAI();
		void collision();
		void followAI();
		bool limitBalle();
		void limitJoueur();
		void passer(joueur* player);
		void passerAI();
		void passerGoal();
		void goal_();
		void collisionGOAL();
		void drawLimit(membres* membres,glm::vec3 pos);
		void loadCinematik();
		void gestionSpecial(int key, int x, int y);
		void gestionSpecialUp(int key, int x, int y);
		void normalKeys(unsigned char key, int x, int y);
		void normalKeysUp(unsigned char key, int x, int y);
		void setup(bool u);
		void setdown(bool u);
		void setright(bool u);
		void setleft(bool u);
		void setespace(bool e);
		bool getespace();
		bool getup();
		bool getdown();
		bool getright();
		bool getleft();
		void follow();
		void input(float speed);
		void input2(float speed);
		void input3(float speed);
		void input4(float speed);
		void input5(float speed);
		void input6(float speed);
		void input7(float speed);
		void input8(float speed);
		void input9(float speed);
		void input10(float speed);

		private:

gui * guiTexture;
gui * guiTexture2;
gui * guiTexture3;
gui* guiTexture4;
gui* guiTexture5;
std::vector<joueur*> player;
std::vector<joueur*> playerAI;	
std::vector<joueur*> goal;
stadium *stade;
stadium* echafaudage;
stadium* decor;
stadium* sky;
stadium* water;
camera* cam;
balle* ball;
std::vector<membres*> membres_;
std::vector<membres*> membres2_;
std::vector<membres*> membres3_;
std::vector<membres*> membres4_;
std::vector<membres*> membres5_;
std::vector<supporter*> support;
int menu,startgame;
bool up,down,right,left,espace;
float temps;
int mitemps;
int rand;
float delay;
float speed;
int scoreA,scoreB;
pass* p;
glm::vec3 locGuiTexture;
int numberSupporters;
bool tir,controls,controls2;

};
#endif

