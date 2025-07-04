#ifndef DEF_BALLE_H
#define DEF_BALLE_H
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
#include <C:\library\glew-1.13.0\include\GL\glew.h>
#include <C:\library\glm\glm\glm.hpp>
#include <C:\library\glm\glm\glm.hpp>
#include <C:\library\glm\glm\gtc\matrix_transform.hpp>
#include <C:\library\glm\glm\gtx\transform.hpp>
#include "../../common/shader.hpp"
#include "../../textures/texture.hpp"
#include "../../common/objloader.hpp"
#include"C:\library\freeglut\include\GL\freeglut.h"
#include "../camera/cameragestion.h"

class balle
{
	
public:
balle(glm::vec3 position);
balle(float x, float y, float z,float rot);
~balle();
void loadContent();
void update();
void show(glm::vec3 addp);
void setLocation(glm::vec3 position);
glm::vec3 getLocation();
bool centrer_();
bool centrerAvant_();
bool centrerArriere_();
bool centrerCoteArriereGauche_();
bool centrerCoteArriereDroite_();
bool centrerCoteGauche_();
bool centrerCoteDroit_();
void centrer_(bool c);
void  centrerAvant_(bool c);
void  centrerArriere_(bool c);
void  centrerCoteArriereGauche_(bool c);
void  centrerCoteArriereDroite_(bool c);
void  centrerCoteGauche_(bool c);
void  centrerCoteDroit_(bool c);
glm::vec3 getangle();
void setangle(glm::vec3 a);
void setLocationIncremente(glm::vec3 newLoc);
float maxSpeed_();
float acce();
float dece();
float getSpeedBallJoueur();
float getSpeedBallJoueurAI();
float getSpeedBallGoal();
void setSpeedBallDecJoueur(float s);
void setSpeedBallAccJoueur(float s);
void setSpeedBallJoueur(float s);
void setSpeedBallDecJoueurAI(float s);
void setSpeedBallDecGoal(float s);
void setSpeedBallAccJoueurAI(float s);
void setSpeedBallAccGoal(float s);
void setSpeedBallJoueurAI(float s);
void setSpeedBallGoal(float s);
float getRot();
void setRot(float r);
void setdece(float dec);
void setVelocity(const glm::vec3& vel);
glm::vec3 getVelocity();
camera cam;

	private:
		bool centrer,centreravant,centrercotedroit,centrercotegauche,centrerarriere,centrercotearrieredroit,centrercotearrieregauche;
		GLuint vertexbuffer;
		GLuint programID;
		GLuint MatrixID;
		GLuint Texture;
		GLuint Texture2;
		GLuint TextureID;
		GLuint TextureID2;
			// Read our .obj file
 		std::vector<glm::vec3> vertices;
		std::vector<glm::vec2> uvs;
		std::vector<glm::vec3> normals; // Won't be used at the moment.
		GLuint uvbuffer;
		glm::vec3 position_;
		glm::vec3 angle;
   		float maxSpeed;
		float acc;
		float dec;
		float rot_;
		float speed,speed_ball_joueur,speed_ball_joueurAI,speed2_ball_joueurAI,speed_ball_goal;
		glm::vec3 velocity;

};
#endif
