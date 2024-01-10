#include"guiTexture.hpp"

gui::gui(const char * file)
{
	init(file);
}
gui::~gui()
{
	
}
void gui::init(const char * file)
{
	glGenVertexArrays(1, &VertexArrayID);
	glBindVertexArray(VertexArrayID);
	

	// Create and compile our GLSL program from the shaders
    programID = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
	MatrixID = glGetUniformLocation(programID, "MVP");
	

	 Texture = loadBMP_custom(file);

	// Get a handle for our "myTextureSampler" uniform
	 TextureID  = glGetUniformLocation(programID, "myTextureSampler");

	 
static const GLfloat g_vertex_buffer_data[] = { 
		-5.0f,-5.0f,0.0f,
		-5.0f,5.0f, 0.0f,
		0.0f, -5.0f, 0.0f,
		 0.0f, 5.0f,0.0f,

		 
	};
	
	// Our vertices. Tree consecutive floats give a 3D vertex; Three consecutive vertices give a triangle.
	// A cube has 6 faces with 2 triangles each, so this makes 6*2=12 triangles, and 12*3 vertices
static const GLfloat g_uv_buffer_data[] = { 
	1.0f, 1.0f, 
		0, 1.0f,
		1, 0.0f, 
		0, 0, 
	
	
	
	
	};




	glGenBuffers(1, &vertexbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);


	glGenBuffers(1, &uvbuffer);
	glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
	glBufferData(GL_ARRAY_BUFFER, sizeof(g_uv_buffer_data), g_uv_buffer_data, GL_STATIC_DRAW);
}
void gui::update(glm::vec3 posCam)
{

}
void gui::draw(glm::mat4 ProjectionMatrix,glm::mat4 ViewMatrix,glm::mat4 ModelMatrix,glm::vec3 position_final,glm::vec3 scale,float rot)
{
		glUseProgram(programID);

		// Compute the MVP matrix from keyboard and mouse input
		glm::mat4 myTranslationMatrix = glm::translate(ModelMatrix,glm::vec3 (position_));
		glm::mat4 myScalingMatrix = glm::scale(ModelMatrix,glm::vec3 (2.5f,2.5f,2.5f));
		glm::vec3 myRotationAxis( 0.0, 0.5,0.0);
		glm::mat4 myRotationMatrix=glm::rotate(0.0f,myRotationAxis);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix* 			ModelMatrix*myTranslationMatrix*myRotationMatrix*myScalingMatrix;


		GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");


		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
	

		// Bind our texture in Texture Unit 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);
		// Set our "myTextureSampler" sampler to user Texture Unit 0
		glUniform1i(TextureID, 0);
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

		
		// Draw the triangle !

		glDrawArrays(GL_QUAD_STRIP,0, 4);
	glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		
	
		
		
}
