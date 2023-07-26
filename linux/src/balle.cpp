#include"balle.h"

static GLuint normalbuffer;
static GLuint ViewMatrixID ;
static GLuint ModelMatrixID;
static GLuint 	 vertexUVID ;

balle::balle(glm::vec3 position)
{
	position_=position;

}
balle::balle(float x, float y,float z,float rot)
{
maxSpeed=1.5f;
acc=0.4f;
dec=0.004f;
angle=glm::vec3(0,0,0);
speed_ball_joueur=0;
speed_ball_joueurAI=0;
speed_ball_goal=0;
position_= glm::vec3(x,y,z);
rot_=rot;
}
void balle::loadContent()
{
// Generate 1 buffer, put the resulting identifier in vertexbuffer
programID  = LoadShaders( "SimpleVertexShader.vertexshader", "SimpleFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
MatrixID = glGetUniformLocation(programID, "MVP");

	// Load the texture
 vertexUVID = glGetAttribLocation(programID, "vertexUV");
 Texture =  loadBMP_custom("data/balle.bmp");
	// Get a handle for our "myTextureSampler" uniform
 TextureID  = glGetUniformLocation(programID, "myTextureSampler");

	// Load the texture
	
	bool res = loadOBJ("data/balle.obj", vertices, uvs, normals);

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
balle::~balle()
{
	
}
void balle::update(glm::vec3 translation)
{
	
}
void balle::setLocation(glm::vec3 position)
{
	position_=position;
}
void balle::setLocationIncremente(glm::vec3 position)
{
	position_+=position;
}
glm::vec3 balle::getLocation()
{
	return position_;
}
void balle::show(glm::mat4 ProjectionMatrix,glm::mat4 ViewMatrix,glm::mat4 ModelMatrix)
{
	glUseProgram(programID);

		// Compute the MVP matrix from keyboard and mouse input
		
				glm::mat4 myTranslationMatrix = glm::translate(ModelMatrix, glm::vec3 (position_));
		glm::mat4 myScalingMatrix = glm::scale(ModelMatrix, glm::vec3 (2.5f,2.5f,2.5f));
		glm::vec3 myRotationAxis( 0.0, 0.5,0.0);
		glm::mat4 myRotationMatrix=glm::rotate(rot_,myRotationAxis);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix* ModelMatrix*myTranslationMatrix*myRotationMatrix*myScalingMatrix;

 GLuint LightID = glGetUniformLocation(programID, "LightPosition_worldspace");

		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);
glm::vec3 lightPos = glm::vec3(4,4,4);
		glUniform3f(LightID, lightPos.x, lightPos.y, lightPos.z);
		// Bind our texture in Texture Unit 0
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, Texture);
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


		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
	glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
}

	 	bool balle::centrer_()
		 	{
		 		return centrer;
			 }
		bool balle::centrerAvant_()
		{
			return centreravant;
		}
		bool balle::centrerArriere_()
		{
			return centrerarriere;
		}
		bool balle::centrerCoteArriereGauche_()
		{
		
		return centrercotearrieregauche;
	}
	
		bool balle::centrerCoteArriereDroite_()
		{
		return centrercotearrieredroit;
		}
		bool balle::centrerCoteGauche_()
		{
		return centrercotegauche;
		}
		bool balle::centrerCoteDroit_()
		{
			return centrercotedroit;
		}
		
			void balle::centrer_(bool c)
		 	{
		 	 centrer=c;
			 }
	void balle::centrerAvant_(bool c)
		{
		 centreravant=c;
		}
		void balle::centrerArriere_(bool c)
		{
		centrerarriere=c;
		}
			void balle::centrerCoteArriereGauche_(bool c)
		{
		
		 centrercotearrieregauche=c;
	}
	
			void balle::centrerCoteArriereDroite_(bool c)
		{
		 centrercotearrieredroit=c;
		}
		void balle::centrerCoteGauche_(bool c)
		{
		centrercotegauche=c;
		}
		void balle::centrerCoteDroit_(bool c)
		{
		 centrercotedroit=c;
		}
void balle::setSpeedBallAccJoueur(float s)
			{
				speed_ball_joueur+=s;
			}
			void balle::setSpeedBallAccGoal(float s)
			{
				speed_ball_goal+=s;
			}
	void balle::setSpeedBallAccJoueurAI(float s)
			{
				speed_ball_joueurAI+=s;
			}		
			
				void balle::setSpeedBallDecJoueur(float s)
			{
				speed_ball_joueur-=s;
			}
				void balle::setSpeedBallDecGoal(float s)
			{
				speed_ball_goal-=s;
			}
				void balle::setSpeedBallDecJoueurAI(float s)
			{
				speed_ball_joueurAI-=s;
			}
				 void balle::setangle(glm::vec3 a)
		 {
		 	angle=a;
		 }
		 glm::vec3 balle::getangle()
		 {
		 	return angle;
		 }
		 
			void balle::setSpeedBallJoueur(float s)
			{
				speed_ball_joueur=s;
			}
				void balle::setSpeedBallGoal(float s)
			{
				speed_ball_goal=s;
			}
				void balle::setSpeedBallJoueurAI(float s)
			{
				speed_ball_joueurAI=s;
			}
				float balle::getSpeedBallJoueur()
			{
				return speed_ball_joueur;
			}
				float balle::getSpeedBallGoal()
			{
				return speed_ball_goal;
			}
				float balle::getSpeedBallJoueurAI()
			{
				return speed_ball_joueurAI;
			}
		 float balle::dece()
		 {
		 	return dec;
		 }
		 void balle::setdece(float d)
		 {
		 	dec=d;
		 }
		 float balle::acce()
		 {
		 	return acc;
		 }
		
		 float balle::maxSpeed_()
		 {
		 	return maxSpeed;
		 }
		 float balle::getRot()
{
	return rot_;
}
void balle::setRot(float r)
{
	rot_=r;
}
