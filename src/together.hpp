#ifndef DEF_TOGETHER_HPP
#define DEF_TOGETHER_HPP
#include"stadium.h"
#include"balle.h"
#include"joueur.h"
#include"membres.h"
#include"supporter.hpp"
#include"passsystem.hpp"
#include"common/text2D.hpp"
#include"guiTexture.hpp"

class together
{
	public:		
	
		together();
		~together();
		void update();
		void draw();
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
		void separatePlayer();
		void separatePlayerAI();
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
		void drawLimit(membres* membres,glm::vec3 pos);
		void loadSupporters();
		void loadCinematik();
		
	private:
		
	std::vector<joueur*> player;
	std::vector<supporter*> support;

	std::vector<joueur*> playerAI;	
	std::vector<joueur*> goal;
	stadium *stade;
	stadium* echafaudage;
	stadium* decor;
	stadium* sky;
	stadium* water;
	pass* p;
	balle* ball;
	std::vector<membres*> membres_;
	std::vector<membres*> membres2_;
	std::vector<membres*> membres3_;
	std::vector<membres*> membres4_;
	std::vector<membres*> membres5_;
	gui * guiTexture;
	gui * guiTexture2;
	gui * guiTexture3;
	gui* guiTexture4;
	gui* guiTexture5;
	int numberSupporters;
	int menu,startgame;
	bool up,down,right,left,espace;
	float temps;
	float speed;
	int mitemps;
	int rand;
	float delay;
	int scoreA,scoreB;
	bool tir,controls,controls2;
	camera cam;
	glm::vec3 locGuiTexture;
		
};

#endif
