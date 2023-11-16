#ifndef DEF_MEMBRES_H
#define DEF_MEMBRES_H
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
class membres
{
	public:
		membres();
		~membres();
		void load(const char * filename,const char * filenameTexture);
		void draw(glm::vec3 addp);
		void setLocation(glm::vec3 pos);
		glm::vec3  getLocation();
		void setRotation(float r);
		float getRotation();
		void setRotation2(float r);
		void setRotation3(float r);
		void setRotation4(float r);
		float getRotation3();
		private:
			camera cam;
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
					float rot2_;
};
#endif

