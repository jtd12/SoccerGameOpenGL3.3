#ifndef DEF_CAMERAGESTION_H
#define DEF_CAMERAGESTION_H
#include <C:\library\glm\glm\glm.hpp>
#include <C:\library\glm\glm\gtc\matrix_transform.hpp>

using namespace glm;

class camera
{
	public:
		camera();
		void computeMatricesFromInputs(glm::vec3 addp);
		glm::mat4 getViewMatrix();
		glm::mat4 getProjectionMatrix();
		void setLocation(glm::vec3 l);
		void setLocationInc(glm::vec3 l);
		glm::vec3 getLocation();
		private:
glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;
glm::vec3 location;
float verticalAngle;
float horizontalAngle;
float initialFoV;
glm::vec3 position;
glm::vec3 position2;
glm::vec3 position3;
};
 #endif
