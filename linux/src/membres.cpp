#include"membres.h"

static GLuint normalbuffer;
static GLuint ViewMatrixID ;
static GLuint ModelMatrixID;
static GLuint vertexUVID;
membres::membres()
{
	position_=glm::vec3(0,0,0);
	rot_=0;
	rot2_=0;

}


membres::~membres()
{
	
}
void membres::load(const char * filename,const char * filenameTexture)
{


programID  = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );


	// Get a handle for our "MVP" uniform
MatrixID = glGetUniformLocation(programID, "MVP");

	// Load the texture

	 vertexUVID = glGetAttribLocation(programID, "vertexUV");
 Texture =  loadBMP_custom(filenameTexture);
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
void membres::draw(glm::mat4 ProjectionMatrix,glm::mat4 ViewMatrix,glm::mat4 ModelMatrix)
	{
			glUseProgram(programID);

		// Compute the MVP matrix from keyboard and mouse input
	
		glm::mat4 myTranslationMatrix = glm::translate(ModelMatrix,glm::vec3 (position_));
		glm::mat4 myScalingMatrix = glm::scale(ModelMatrix,glm::vec3 (0.5f,0.5f,0.5f));
		glm::vec3 myRotationAxis( 0.0, 0.5,0.0);
		glm::vec3 myRotationAxis2( 0.0, 0.0,0.5);
		glm::mat4 myRotationMatrix=glm::rotate(rot_,myRotationAxis);
		glm::mat4 myRotationMatrix2=glm::rotate(rot2_,myRotationAxis2);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix* ModelMatrix*myTranslationMatrix*myRotationMatrix*myRotationMatrix2*myScalingMatrix;

 GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");

		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
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
	
		glDrawArrays(GL_TRIANGLES,0, vertices.size() );
	glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
	}
	
		void membres::setLocation(glm::vec3 pos)
		{
			position_=pos;
		}
		glm::vec3 membres:: getLocation()
		{
			return position_;
		}
		void membres::setRotation(float r)
		{
			rot_=r;
		}
		float membres::getRotation()
		{
			return rot_;
		}
			void membres::setRotation2(float r)
		{
			rot2_+=r;
		}
			void membres::setRotation3(float r)
		{
			rot2_=r;
		}
			void membres::setRotation4(float r)
		{
			rot2_-=r;
		}
		float membres::getRotation3()
		{
			return rot2_;
		}
