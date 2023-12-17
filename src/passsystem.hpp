#ifndef DEF_PASSSYSTEM_HPP
#define DEF_PASSSYSTEM_HPP
#include<iostream>
#include<dos.h>   //for delay()
#include<conio.h>   //for getch()
#include<cstdlib>
#include <ctime>
#include"joueur.h"
#include"balle.h"

using namespace std;

inline int randMToN(int M, int N);


class pass
{
	public:
		
	pass();
	~pass();
	void update(balle* b, joueur* aiplayer, float xpos,float xpos2,float zpos,float zpos2,int randX,int randZ,std::vector<joueur*> player,
		std::vector<joueur*> playerAI);
	void passer(balle* b, joueur* aiplayer, float xpos,float xpos2,float zpos,float zpos2,int randX,int randZ,std::vector<joueur*> player,
		std::vector<joueur*> playerAI);
	void setTir(bool t);
	bool getTir();
	void setSpeed(float s);
	
	private:
		float rand;
		float timer;
		bool tir;
		float delay;
		float speed;
		
};

#endif
