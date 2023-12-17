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
void gui::draw(glm::vec3 addp,glm::vec3 position_final,glm::vec3 scale,float rot)
{
		glUseProgram(programID);
	
		cam.computeMatricesFromInputs( addp);
		glm::mat4 Projection = cam.getProjectionMatrix();
	// Camera matrix
		glm::mat4 View       = cam.getViewMatrix();
	// Model matrix : an identity matrix (model will be at the origin)
		glm::mat4 Model      = glm::mat4(1.0f);
		glm::vec3 myRotationAxis( 0.5, 0.0,0.0);
		glm::mat4 myRotationMatrix=glm::rotate(rot,myRotationAxis);
		glm::mat4 myTranslationMatrix_final = glm::translate(glm::mat4(), glm::vec3 (position_final.x,position_final.y,position_final.z));
		glm::mat4 myScalingMatrix = glm::scale(glm::mat4(), glm::vec3 (scale.x,scale.y,scale.z));
		glm::mat4 myScalingMatrix_final = glm::scale(glm::mat4(), glm::vec3 (0.8f,0.8f,0.8f));
		
	
		
	// Our ModelViewProjection : multiplication of our 3 matrices
		glm::mat4 MVP        =   Projection * View * Model*myRotationMatrix*myTranslationMatrix_final*myScalingMatrix*myScalingMatrix_final; // Remember, matrix multiplication is the other way around
	
		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
		
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);
		// Set our "myTextureSampler" sampler to user Texture Unit 0
		glUniform1i(TextureID, 0);

		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
		glVertexAttribPointer(
			0,                  // attribute. No particular reason for 0, but must match the layout in the shader.
			3,                  // size
			GL_FLOAT,           // type
			GL_FALSE,           // normalized?
			0,                  // stride
			(void*)0            // array buffer offset
		);
		glEnableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, uvbuffer);
		glVertexAttribPointer(
			1,                                // attribute. No particular reason for 1, but must match the layout in the shader.
			2,                                // size : U+V => 2
			GL_FLOAT,                         // type
			GL_FALSE,                         // normalized?
			0,                                // stride
			(void*)0                          // array buffer offset
		);


		// Draw the triangle !
		glDrawArrays(GL_QUAD_STRIP, 0, 4); // 12*3 indices starting at 0 -> 12 triangles

		glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		
	
		
		
}
