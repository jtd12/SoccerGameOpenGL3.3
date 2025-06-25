#include"cameragestion.h"

camera::camera()
 {
// Initial position : on +Z
 position = glm::vec3(0, 0, 0 ); 
  position2 = glm::vec3( 0, 0, 0 ); 
   position3 = glm::vec3( 0, -1, 0 ); 
// Initial horizontal angle : toward -Z

// Initial Field of View
initialFoV = 30.0f;

 }
 
 glm::mat4 camera::getViewMatrix(){
	return ViewMatrix;
}
glm::mat4 camera::getProjectionMatrix(){
	return ProjectionMatrix;
}
void camera::setLocation(glm::vec3 l)
{
	position=l;
}
void camera::setLocationInc(glm::vec3 l)
{
	position+=l;
	if(position.x>100)
	  position.x=0;
}
glm::vec3 camera::getLocation()
{
	return position;
}
void camera::computeMatricesFromInputs(glm::vec3 addp){




	
	float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(FoV, 4.0f / 3.0f, 0.1f, 10000.0f);
	// Camera matrix
	ViewMatrix       = glm::lookAt(
								position+addp,           // Camera is here
								addp, // and looks here : at the same position, plus "direction"
								position3                  // Head is up (set to 0,-1,0 to look upside-down)
						   );

	// For the next frame, the "last time" will be "now"
	//lastTime = currentTime;
}
