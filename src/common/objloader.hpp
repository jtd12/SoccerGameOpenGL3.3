#ifndef OBJLOADER_H
#define OBJLOADER_H
#include<vector>
#include <C:\library\glm\glm\glm.hpp>
#include <C:\library\glm\glm\glm.hpp>
#include <C:\library\glm\glm\gtc\matrix_transform.hpp>
bool loadOBJ(
	std::string filename, 
	std::vector<glm::vec3> & out_vertices, 
	std::vector<glm::vec2> & out_uvs, 
	std::vector<glm::vec3> & out_normals
);



bool loadAssImp(
	const char * path, 
	std::vector<unsigned short> & indices,
	std::vector<glm::vec3> & vertices,
	std::vector<glm::vec2> & uvs,
	std::vector<glm::vec3> & normals
);

#endif
