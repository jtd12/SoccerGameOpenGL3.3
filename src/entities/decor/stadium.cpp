#include"stadium.h"

static GLuint normalbuffer;
static GLuint ViewMatrixID ;
static GLuint ModelMatrixID;

stadium::stadium(glm::vec3 position)
{
	rot=0;
	position_=position;
}
stadium::stadium(float x, float y,float z)
{
position_= glm::vec3(x,y,z);
rot=0;
}
void stadium::loadContent(const char * filename,const char*textures)
{
// Generate 1 buffer, put the resulting identifier in vertexbuffer
programID  = LoadShaders( "entities/shaders/SimpleVertexShader.vertexshader", "entities/shaders/SimpleFragmentShader.fragmentshader" );


	// Get a handle for our "MVP" uniform
MatrixID = glGetUniformLocation(programID, "MVP");

	// Load the texture
	 ViewMatrixID = glGetUniformLocation(programID, "V");
	 ModelMatrixID = glGetUniformLocation(programID, "M");
 Texture =  loadBMP_custom(textures);
 
	// Get a handle for our "myTextureSampler" uniform
 TextureID  = glGetUniformLocation(programID, "myTextureSampler");


	bool res = loadOBJ(filename, vertices, uvs, normals);

	// Load it into a VBO


	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), &vertices[0], GL_STATIC_DRAW);


	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, uvs.size() * sizeof(glm::vec2), &uvs[0], GL_STATIC_DRAW);
	
  
	glGenBuffers(1, &normalbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
	glBufferData(GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3), &normals[0], GL_STATIC_DRAW);

}
stadium::~stadium()
{
	
}
void stadium::update()
{
	rot+=0.0002f;
}
void stadium::show(glm::vec3 addp)
{
	glUseProgram(programID);
   GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");

		// Compute the MVP matrix from keyboard and mouse input
		cam.computeMatricesFromInputs(addp);
		glm::mat4 ProjectionMatrix = cam.getProjectionMatrix();
		glm::mat4 ViewMatrix = cam.getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(10.0);
		glm::vec3 myRotationAxis( 0.0, 0.5f,0.0);
		glm::mat4 myRotationMatrix=glm::rotate(rot,myRotationAxis);
		glm::mat4 myMatrix = myRotationMatrix*glm::translate(glm::mat4(), glm::vec3 (position_));
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix* ModelMatrix*myMatrix;



		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
glUniformMatrix4fv(ModelMatrixID, 1, GL_FALSE, &ModelMatrix[0][0]);
		glUniformMatrix4fv(ViewMatrixID, 1, GL_FALSE, &ViewMatrix[0][0]);
		// Bind our texture in Texture Unit 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);
		// Set our "myTextureSampler" sampler to user Texture Unit 0
		glUniform1i(TextureID, 0);
glm::vec3 lightPos = glm::vec3(4,4,4);
		glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
		// 1rst attribute buffer : vertices
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);

		// 2nd attribute buffer : UVs
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glVertexAttribPointer(
			1,                                // attribute
			2,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);
glEnableVertexAttribArray(2);
		glBindBuffer(GL_ARRAY_BUFFER, normalbuffer);
		glVertexAttribPointer(
			2,                                // attribute
			3,                                // size
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);
		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
	glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
}
