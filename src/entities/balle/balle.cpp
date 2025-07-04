#include"balle.h"

static GLuint normalbuffer;
static GLuint ViewMatrixID ;
static GLuint ModelMatrixID;

balle::balle(glm::vec3 position)
{
	position_=position;

}
balle::balle(float x, float y,float z,float rot)
{
maxSpeed=100.5f;
acc=5.9f;
dec=0.000002f;
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
programID  = LoadShaders( "entities/shaders/SimpleVertexShader.vertexshader", "entities/shaders/SimpleFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
MatrixID = glGetUniformLocation(programID, "MVP");

	// Load the texture
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


}
balle::~balle()
{
	
}
void balle::update()
{
//	cam.setLocation(glm::vec3(0,80,50));
	float deltaTime=0.1f;
	position_ += velocity * deltaTime;

    // Appliquer un ralentissement progressif (friction)
    velocity *= 0.98f; // tu peux ajuster ce facteur (proche de 1.0) selon ton besoin
    if (glm::length(velocity) < 0.05f) {
        velocity = glm::vec3(0.0f);
    }
    
    position_.y-=0.15f;
	if(position_.y<2.25f)
		position_.y=2.25f;
}
void balle::setLocation(glm::vec3 position)
{
	position_=position;
}
void balle::setLocationIncremente(glm::vec3 position)
{
	position_+=position;
	velocity *= 0.98f; // par exemple pour ralentir doucement
}
glm::vec3 balle::getLocation()
{
	return position_;
}
void balle::show(glm::vec3 addp)
{
	glUseProgram(programID);

		// Compute the MVP matrix from keyboard and mouse input
		
		cam.computeMatricesFromInputs( addp);
		glm::mat4 ProjectionMatrix = cam.getProjectionMatrix();
		glm::mat4 ViewMatrix = cam.getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(10.0);
		glm::mat4 myTranslationMatrix = glm::translate(glm::mat4(), glm::vec3 (position_));
		glm::mat4 myScalingMatrix = glm::scale(glm::mat4(), glm::vec3 (2.5f,2.5f,2.5f));
		glm::vec3 myRotationAxis( 0.0, 0.5,0.0);
		glm::mat4 myRotationMatrix=glm::rotate(rot_,myRotationAxis);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix* ModelMatrix*myTranslationMatrix*myScalingMatrix;

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

		// Draw the triangle !
		glDrawArrays(GL_TRIANGLES, 0, vertices.size() );
	glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
}

  void balle::setVelocity(const glm::vec3& vel) 
		  { 
		  velocity = vel;
		   }
		  glm::vec3 balle::getVelocity()
		  {
		  	return velocity;
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
