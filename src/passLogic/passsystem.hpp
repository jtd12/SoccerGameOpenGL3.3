#ifndef DEF_PASSSYSTEM_HPP
#define DEF_PASSSYSTEM_HPP
#include<iostream>
#include<dos.h>   //for delay()
#include<conio.h>   //for getch()
#include<cstdlib>
#include <ctime>
#include"../entities/player/joueur.h"
#include"../entities/balle/balle.h"

inline int randMToN(int M, int N);
inline float distance3D(float x1, float y1, float z1, float x2, float y2, float z2);

	struct Zone
    {
         float xMin, xMax;
         float zMin, zMax;
         int playerMin, playerMax;
    };
    
class pass
{
	public:
		
	pass();
	~pass();
	void update(balle* b,std::vector<joueur*> player,
		std::vector<joueur*> playerAI);
		void TirerVersBut(joueur* player, balle* b);
	void PasserAI(std::vector<joueur*>playerAI,joueur* player, float xmin, float xmax, float zmin, float zmax, balle* b);
	void setTir(bool t);
	bool getTir();
	void setSpeed(float s);
	
	private:
		std::vector<Zone*> zones;
		float rand;
		float timer;
		bool tir;
		float delay;
		float speed;
		glm::vec3 targetGoal;
		
		
};

#endif

