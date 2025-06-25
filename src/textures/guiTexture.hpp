#ifndef DEF_GUITEXTURE_HPP
#define DEF_GUITEXTURE_HPP
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
#include "../common/shader.hpp"
#include "../entities/camera/cameragestion.h"
#include "texture.hpp"
#define pi 3.14159265359

class gui
 {
 	public:
 	gui(const char * file);
 	~gui();
 	void init(const char * file);
	void update(glm::vec3 posCam);
	void draw(glm::vec3 addp,glm::vec3 position_final,glm::vec3 scale,float rot);
	camera cam;
	
 	private:
 		GLuint VertexArrayID;
		GLuint programID;
		GLuint MatrixID;
		GLuint vertexbuffer;
		GLuint uvbuffer;
		glm::vec3 position_;
		glm::vec3 position_final;
		GLuint Texture;
		GLuint TextureID;
	
 };
 #endif
