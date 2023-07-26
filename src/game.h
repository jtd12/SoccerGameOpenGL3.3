#ifndef DEF_GAME_H
#define DEF_GAME_H
#include"stadium.h"
#include"balle.h"
#include"joueur.h"
#include"membres.h"
#include"common/text2D.hpp"

class game
{
	public:
		game();
		~game();
		void initGL();
		void draw();
		void update();
		void movementBall();
		void movement();
		void movementAI();
		void collisionAI();
		void collision();
		void followAI();
		bool limitBalle();
		void limitJoueur();
		void passer();
		void passerAI();
		void passerGoal();
		void goal_();
		void collisionGOAL();
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
		void input();
		void input2();
		void input3();
		void input4();
		void input5();
		void input6();
		void input7();
		void input8();
		void input9();
		void input10();

		private:
	std::vector<joueur*> player;
std::vector<joueur*> playerAI;	
std::vector<joueur*> goal;
		stadium *stade;
balle* ball;
std::vector<membres*> membres_;
std::vector<membres*> membres2_;
std::vector<membres*> membres3_;
std::vector<membres*> membres4_;
std::vector<membres*> membres5_;
int menu,startgame;
bool up,down,right,left,espace;
float temps;
int mitemps;
int scoreA,scoreB;
};
#endif

