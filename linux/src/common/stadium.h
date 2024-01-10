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
#include "shader.hpp"
#include "texture.hpp"
#include "controls.hpp"
#include "objloader.hpp"
#include"C:\freeglut\include\GL\freeglut.h"

class stadium
{
	public:
	stadium();
	void load();
	void update();
	void show();
	private:
		GLuint vertexbuffer;
GLuint programID;
	GLuint MatrixID;
		GLuint Texture;
		GLuint TextureID;
			// Read our .obj file
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // Won't be used at the moment.
				GLuint uvbuffer;
};
#endif
