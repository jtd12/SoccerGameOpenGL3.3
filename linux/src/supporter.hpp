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
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#include "common/shader.hpp"
#include "camera.hpp"
#include "common/texture.hpp"
#define pi 3.14159265359

class supporter
{
	public:
	supporter(float x, float y,float z,float rot);
	~supporter();
	void init();
	void update();
	void draw(glm::mat4 ProjectionMatrix,glm::mat4 ViewMatrix,glm::mat4 ModelMatrix);
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

