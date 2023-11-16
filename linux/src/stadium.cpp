#include"stadium.h"

static GLuint normalbuffer;
static GLuint ViewMatrixID ;
static GLuint ModelMatrixID;

stadium::stadium(glm::vec3 position)
{
	position_=position;
}
stadium::stadium(float x, float y,float z)
{
position_= glm::vec3(x,y,z);

}
void stadium::loadContent()
{
// Generate 1 buffer, put the resulting identifier in vertexbuffer
programID  = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );


	// Get a handle for our "MVP" uniform
MatrixID = glGetUniformLocation(programID, "MVP");

	// Load the texture

	 vertexUVID = glGetAttribLocation(programID, "vertexUV");
 Texture =  loadBMP_custom("data/stadium.bmp");
 
	// Get a handle for our "myTextureSampler" uniform
 TextureID  = glGetUniformLocation(programID, "myTextureSampler");


	bool res = loadOBJ("data/stade.obj", vertices, uvs, normals);

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
void stadium::update(glm::vec3 translation)
{
	
}
void stadium::show(glm::mat4 ProjectionMatrix,glm::mat4 ViewMatrix,glm::mat4 ModelMatrix)
{
glUseProgram(programID);

   GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");

		// Compute the MVP matrix from keyboard and mouse input
	
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
	// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

		// Bind our texture in Texture Unit 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);
glUniform1i(TextureID, 0);
glm::vec3 lightPos = glm::vec3(4,4,4);
		glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);

		// Set our "myTextureSampler" sampler to user Texture Unit 0
		glUniform1i(TextureID, 0);

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
		glDisableVertexAttribArray(2);

	}
