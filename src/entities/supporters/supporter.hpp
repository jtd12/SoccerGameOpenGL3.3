#ifndef DEF_SUPPORTER_HPP
#define DEF_SUPPORTER_HPP
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
#include"C:\library\freeglut\include\GL\freeglut.h"
#include "../../common/shader.hpp"
#include "../camera/cameragestion.h"
#include "../../textures/texture.hpp"
#define pi 3.14159265359

class supporter
{
	public:
	supporter(float x, float y,float z,float rot);
	~supporter();
	void init();
	void update();
	void draw(glm::vec3 addp);
		camera cam;
	
	private:
		float rot_;
		glm::vec3 position_bras;
		GLuint VertexArrayID;
		GLuint programID;
		GLuint MatrixID;
		GLuint vertexbuffer;
		GLuint uvbuffer;
		glm::vec3 position_;
		glm::vec3 position_final;
		GLuint Texture;
		GLuint TextureID;
		GLuint Texture2;
		GLuint TextureID2;
		
		GLuint vertexbuffer2;
		GLuint uvbuffer2;
	
		GLuint vertexbuffer3;
		GLuint uvbuffer3;
	
		GLuint vertexbuffer4;
		GLuint uvbuffer4;
	
		GLuint vertexbuffer5;
		GLuint uvbuffer5;
		
		GLuint vertexbuffer6;
		GLuint uvbuffer6;

	
	
};

#endif

