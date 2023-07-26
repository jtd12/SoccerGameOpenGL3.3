#ifndef DEF_ANIMOBJ
#define DEF_ANIMOBJ
#include"objloader.hpp"
class animOBJ
{
public:
bool loadAnimation(std::vector<unsigned int>& frames, std::string filename, unsigned int num);
	std::vector<glm::vec3> vertices;
	std::vector<glm::vec2> uvs;
	std::vector<glm::vec3> normals; // Won't be used at the moment.
private:
	
	objModel obj;
};
#endif
