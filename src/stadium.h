#ifndef DEF_STADIUM_H
#define DEF_STADIUM_H
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
#include"cameragestion.h"

class stadium
{
	public:
	stadium(glm::vec3 position);
	stadium(float x, float y, float z);
	~stadium();
		void loadContent(const char * filename,const char*textures);
	void update();
	void show(glm::vec3 addp);
			camera cam;	 
	private:
		 std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // Won't be used at the moment.
			
						glm::vec3 position_;
				
		GLuint vertexbuffer;
GLuint programID;
	GLuint MatrixID;
		GLuint Texture;
			GLuint Texture2;
		GLuint TextureID;
		GLuint TextureID2;
		GLuint uvbuffer;
		float rot;
			// Read our .obj file

			 
};
#endif
