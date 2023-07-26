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
#include <C:\glew-1.13.0\include\GL\glew.h>
#include <C:\glm\glm\glm.hpp>
#include <C:\glm\glm\glm.hpp>
#include <C:\glm\glm\gtc\matrix_transform.hpp>
#include "common/shader.hpp"
#include "common/texture.hpp"
#include "common/objloader.hpp"
#include"C:\freeglut\include\GL\freeglut.h"
#include"cameragestion.h"

class stadium
{
	public:
	stadium(glm::vec3 position);
	stadium(float x, float y, float z);
	~stadium();
		void loadContent();
	void update(glm::vec3 translation);
	void show(glm::vec3 addp);
	private:
		 std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // Won't be used at the moment.
			
						glm::vec3 position_;
						camera cam;	 
		GLuint vertexbuffer;
GLuint programID;
	GLuint MatrixID;
		GLuint Texture;
			GLuint Texture2;
		GLuint TextureID;
		GLuint TextureID2;
		GLuint uvbuffer;
			// Read our .obj file

			 
};
#endif
