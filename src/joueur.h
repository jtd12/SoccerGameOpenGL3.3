#ifndef DEF_JOUEUR_H
#define DEF_JOUEUR_H
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
#include "common/shader.hpp"
#include "common/texture.hpp"
#include "common/objloader.hpp"
#include"C:\library\freeglut\include\GL\freeglut.h"
#include "cameragestion.h"
#define pi 3.14159265359



class joueur
{
	public:
	joueur(glm::vec3 position);
	joueur(float x, float y,float z,float rot);
	~joueur();
	void loadContent(const char * filename,const char * filenameTexture);
	void update(glm::vec3 translation);
	void show(glm::vec3 addp);
	bool movement(glm::vec3 playerLoc);
	bool movementAI(glm::vec3 playerLoc);
	bool movementGOAL(glm::vec3 playerLoc);
	bool movementGOALAI(glm::vec3 playerLoc);
	void setLocation(glm::vec3 position);
	glm::vec3  getLocation();
    float getRot();
    void setRot(float r);
	void setNext(bool s);
	bool getNext();
	void setTirer(bool t);
	bool getTirer();
		void sethastheball(bool has);
		bool gethastheball();
		void setattaquer(bool x);
		void setdefendre(bool x);
		bool getattaquer();
		bool getdefendre();
	

	private:
		GLuint vertexbuffer;
GLuint programID;
	GLuint MatrixID;
		GLuint Texture;
			GLuint Texture2;
		GLuint TextureID;
		GLuint TextureID2;
		float curFrame;
		std::vector<unsigned int > frames;
			// Read our .obj file
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // Won't be used at the moment.
				GLuint uvbuffer;
				glm::vec3 position_;
				glm::vec3 direction;
				float rot_;
				bool next;
				bool hastheball;
					bool attaquer_,defendre_;
					bool tirer;
					camera cam;
				
			

};
#endif


