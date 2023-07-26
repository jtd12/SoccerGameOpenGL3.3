#ifndef DEF_OBJANIM_H
#define DEF_OBJANIM_H
#include<string>
#include"common/objloader.hpp"



	bool loadAnimation(std::vector<glm::vec3>& frames, const std::string filename, unsigned int num);


extern std::vector<glm::vec3> vertices;
 extern	std::vector<glm::vec2> uvs;
 extern	std::vector<glm::vec3> normals; // Won't be used at the moment.
 

#endif
