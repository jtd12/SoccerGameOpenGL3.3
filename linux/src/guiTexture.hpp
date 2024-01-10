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
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>
#include "common/shader.hpp"
#include "camera.hpp"
#include "common/texture.hpp"
#define pi 3.14159265359

class gui
 {
 	public:
 	gui(const char * file);
 	~gui();
 	void init(const char * file);
	void update(glm::vec3 posCam);
	void draw(glm::mat4 ProjectionMatrix,glm::mat4 ViewMatrix,glm::mat4 ModelMatrix,glm::vec3 position_final,glm::vec3 scale,float rot);
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
