#include"joueur.h"

joueur::joueur(glm::vec3 position)
{
curFrame=1;
position_=position;
}
joueur::joueur(float x, float y,float z,float rot)
{
position_= glm::vec3(x,y,z);
rot_=rot;

}
void joueur::setLocation(glm::vec3 position)
{
	position_=position;
}
bool joueur::movement(glm::vec3 playerLoc)
		{
		
		
				
			glm::vec3 newpos(position_);
			     
			      direction=glm::normalize(playerLoc-position_);
		
			newpos.y-=0.5f;
			if(newpos.y<=3.5f)
			{ newpos.y=3.5f;
			}
			newpos+=0.03f*direction;
			setLocation(newpos);
			  
			 	rot_=std::acos(direction.x);
			 	if(direction.z>0)
			 	  {
			 	  	rot_=-rot_;
				   }
				   
				 
	 			
					 
				
				
							
			
		

	 			
					 
				
				
							
			
		}
		
		bool joueur::movementGOAL(glm::vec3 playerLoc)
		{
		
		
				
			glm::vec3 newpos(position_);
			     
			      direction=glm::normalize(playerLoc-position_);
		
			newpos.y-=0.5f;
			if(newpos.y<=3.5f)
			{ newpos.y=3.5f;
			}
		
			setLocation(newpos);
			  
			 	rot_=std::acos(direction.x);
			 	if(direction.z>0)
			 	  {
			 	  	rot_=-rot_;
				   }
				   
				 
	 			
					 
				
				
							
			
		

	 			
					 
				
				
							
			
		}
			
		bool joueur::movementGOALAI(glm::vec3 playerLoc)
		{
		
		
				
			glm::vec3 newpos(position_);
			     
			      direction=glm::normalize(playerLoc-position_);
		
			newpos.y-=0.5f;
			if(newpos.y<=3.5f)
			{ newpos.y=3.5f;
			}
		
			setLocation(newpos);
			  
			 	rot_=std::acos(-direction.x);
			 	if(direction.z<0)
			 	  {
			 	  	rot_=-rot_;
				   }
				   
				 
	 			
					 
				
				
							
			
		

	 			
					 
				
				
							
			
		}
		
		bool joueur::movementAI(glm::vec3 playerLoc)
		{
		
		
				
			glm::vec3 newpos(position_);
			     
			      direction=glm::normalize(playerLoc-position_);
		
			newpos.y-=0.5f;
			if(newpos.y<=3.5f)
			{ newpos.y=3.5f;
			}
			newpos+=0.05f*direction;
			setLocation(newpos);
			  
			 	rot_=std::acos(-direction.x);
			 	if(direction.z<0)
			 	  {
			 	  	rot_=-rot_;
				   }
				   
				 
	 			
					 
				
				
							
			
		

	 			
					 
				
				
							
			
		}



glm::vec3 joueur::getLocation()
{
	return position_;
}
void joueur::setNext(bool s)
{
	next=s;

}
bool joueur::getNext()
{
	return next;
}
bool joueur::getTirer()
 {
 	return tirer;
 }
 void joueur::setTirer(bool t)
 {
 	tirer=t;
 }
joueur::~joueur()
{

}
void joueur::loadContent(const char *filename,const char * filenameTexture)
{
programID = LoadShaders( "TransformVertexShader.vertexshader", "TextureFragmentShader.fragmentshader" );

	// Get a handle for our "MVP" uniform
MatrixID = glGetUniformLocation(programID, "MVP");

	// Load the texture
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
	
// Generate 1 buffer, put the resulting identifier in vertexbuffer


}
void joueur::update(glm::vec3 translation)
{

	position_+=translation*1.3f;
}
float joueur::getRot()
{
	return rot_;
}
void joueur::setRot(float r)
{
	rot_=r;
}
void joueur::show(glm::vec3 addp)
{

			glUseProgram(programID);

		// Compute the MVP matrix from keyboard and mouse input
		cam.computeMatricesFromInputs(addp); 
		glm::mat4 ProjectionMatrix = cam.getProjectionMatrix();
		glm::mat4 ViewMatrix = cam.getViewMatrix();
		glm::mat4 ModelMatrix = glm::mat4(10.0);
		glm::mat4 myTranslationMatrix = glm::translate(glm::mat4(), glm::vec3 (position_));
		glm::mat4 myScalingMatrix = glm::scale(glm::mat4(), glm::vec3 (0.5f,0.5f,0.5f));
		glm::vec3 myRotationAxis( 0.0, 0.5,0.0);
		glm::mat4 myRotationMatrix=glm::rotate(rot_,myRotationAxis);
		glm::mat4 MVP = ProjectionMatrix * ViewMatrix* ModelMatrix*myTranslationMatrix*myRotationMatrix*myScalingMatrix;



		// Send our transformation to the currently bound shader, 
		// in the "MVP" uniform
		glUniformMatrix4fv(MatrixID, 1, GL_FALSE, &MVP[0][0]);

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
	
		glDrawArrays(GL_TRIANGLES,0, vertices.size() );
	glDisableVertexAttribArray(0);
		glDisableVertexAttribArray(1);
		
		
}
		void joueur::sethastheball(bool has)
		{
			hastheball=has;
		}
		bool joueur::gethastheball()
		{
			return hastheball;
		}
			 void joueur::setattaquer(bool x)
		 {
		 	attaquer_=x;
		 }
		 	 void joueur::setdefendre(bool x)
		 {
		 	defendre_=x;
		 }
		 bool joueur::getattaquer()
		 {
		 	return attaquer_;
		 }
		 	 bool joueur::getdefendre()
		 {
		 	return defendre_;
		 }


