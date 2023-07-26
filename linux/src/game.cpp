#include"game.h"


game::game()
{
	
}
game::~game()
{
	   delete stade;

	   
	   cleanupText2D();
}
void game::initGL()
{

cam=new camera();
cam=new camera(vec3(20, 20, 50), vec3(0, 0, 0), vec3(0, 1, 0));
player.push_back(new joueur(0,3.5,30,0));
player.push_back(new joueur(0,3.5,32,0));
player.push_back(new joueur(0,3.5,35,0));
player.push_back(new joueur(0,3.5,37,0));
player.push_back(new joueur(10,3.5,39,0));
player.push_back(new joueur(10,3.5,20,0));
player.push_back(new joueur(10,3.5,21,0));
player.push_back(new joueur(10,3.5,0,25));
player.push_back(new joueur(10,3.5,27,0));
player.push_back(new joueur(10,3.5,29,0));


playerAI.push_back(new joueur(20,3.5,20,0));
playerAI.push_back(new joueur(20,3.5,25,0));
playerAI.push_back(new joueur(20,3.5,22,0));
playerAI.push_back(new joueur(20,3.5,24,0));
playerAI.push_back(new joueur(20,3.5,27,0));
playerAI.push_back(new joueur(20,3.5,29,0));
playerAI.push_back(new joueur(20,3.5,31,0));
playerAI.push_back(new joueur(20,3.5,33,0));
playerAI.push_back(new joueur(20,3.5,35,0));
playerAI.push_back(new joueur(20,3.5,37,0));
goal.push_back(new joueur(-45,3.5,0,0));
goal.push_back(new joueur(45,3.5,0,0));
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());
membres_.push_back(new membres());

membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());
membres2_.push_back(new membres());


membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());
membres3_.push_back(new membres());

membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());
membres4_.push_back(new membres());

membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());
membres5_.push_back(new membres());

for(int i=0;i<player.size();i++)
player[i]->loadContent("data/corps.obj","data/corps.bmp");
for(int i=0;i<membres_.size();i++)
membres_[i]->load("data/bras.obj","data/tete.bmp");
for(int i=0;i<membres2_.size();i++)
membres2_[i]->load("data/bras2.obj","data/tete.bmp");
for(int i=0;i<membres3_.size();i++)
membres3_[i]->load("data/tete.obj","data/tete.bmp");
for(int i=0;i<membres4_.size();i++)
membres4_[i]->load("data/jambe.obj","data/tete.bmp");
for(int i=0;i<membres5_.size();i++)
membres5_[i]->load("data/jambe2.obj","data/tete.bmp");
for(int i=0;i<playerAI.size();i++)
playerAI[i]->loadContent("data/corps.obj","data/corpsAI.bmp");
goal[0]->loadContent("data/corps.obj","data/corps.bmp");
goal[1]->loadContent("data/corps.obj","data/corpsAI.bmp");

stade=new stadium(0,0,0);
stade->loadContent();

ball=new balle(0,2.3,0,0);
ball->loadContent();
left=up=right=down=espace=false;
startgame=0;
menu=1;
mitemps=0;
scoreA=0;
scoreB=0;
initText2D( "data/Holstein.DDS" );


// Generate 1 buffer, put the resulting identifier in vertexbuffer

	// Get a handle for our "MVP" un
}
void game::collision()
{
	for(int i=0;i<player.size();i++)
	 	for(int j=0;j<playerAI.size();j++)
	{
	
	float d=sqrt(((player[i]->getLocation().x-ball->getLocation().x)*(player[i]->getLocation().x-ball->getLocation().x))
	+((player[i]->getLocation().y-ball->getLocation().y)*(player[i]->getLocation().y-ball->getLocation().y))
	+((player[i]->getLocation().z-ball->getLocation().z)*(player[i]->getLocation().z-ball->getLocation().z)));
	
//	d = sqrt(((p1x - p2x) * (p1x – p2x)) + ((p1y – p2y) * (p1y – p2y)) + ((p1z – p2z) * (p1z – p2z)));

		if(d<2.0f &&  player[i]->getTirer()==false)
		{
			player[i]->sethastheball(true);
			playerAI[j]->sethastheball(false);
			
			
		}
		else
		{
			player[i]->sethastheball(false);	
		}
		if(player[i]->gethastheball() )
		{
			ball->setLocation(glm::vec3(player[i]->getLocation().x+1.2f,ball->getLocation().y,player[i]->getLocation().z));
		}
			if(player[i]->gethastheball() && getup())
		{
			ball->setLocation(glm::vec3(player[i]->getLocation().x+1.4f,ball->getLocation().y,player[i]->getLocation().z));
		}
			if(player[i]->gethastheball() && getdown())
		{
			ball->setLocation(glm::vec3(player[i]->getLocation().x-0.4f,ball->getLocation().y,player[i]->getLocation().z));
		}
		if(player[i]->gethastheball() && getright())
		{
			ball->setLocation(glm::vec3(player[i]->getLocation().x,ball->getLocation().y,player[i]->getLocation().z+0.4f));
		}
		if(player[i]->gethastheball() && getleft())
		{
			ball->setLocation(glm::vec3(player[i]->getLocation().x,ball->getLocation().y,player[i]->getLocation().z-0.4f));
		}
		
		
	}	
}
void game::collisionGOAL()
{
	for(int i=0;i<goal.size();i++)
	{
	
	float d=sqrt(((goal[i]->getLocation().x-ball->getLocation().x)*(goal[i]->getLocation().x-ball->getLocation().x))
	+((goal[i]->getLocation().y-ball->getLocation().y)*(goal[i]->getLocation().y-ball->getLocation().y))
	+((goal[i]->getLocation().z-ball->getLocation().z)*(goal[i]->getLocation().z-ball->getLocation().z)));
	
//	d = sqrt(((p1x - p2x) * (p1x – p2x)) + ((p1y – p2y) * (p1y – p2y)) + ((p1z – p2z) * (p1z – p2z)));

		if(d<2 &&  goal[i]->getTirer()==false)
		{
			goal[i]->sethastheball(true);
			
			
			
		}
		else
		{
			goal[i]->sethastheball(false);	
		}
	
		
	}
	
}
void game::collisionAI()
{
	for(int i=0;i<playerAI.size();i++)
 	for(int j=0;j<player.size();j++)
	{
	
	float d=sqrt(((playerAI[i]->getLocation().x-ball->getLocation().x)*(playerAI[i]->getLocation().x-ball->getLocation().x))
	+((playerAI[i]->getLocation().y-ball->getLocation().y)*(playerAI[i]->getLocation().y-ball->getLocation().y))
	+((playerAI[i]->getLocation().z-ball->getLocation().z)*(playerAI[i]->getLocation().z-ball->getLocation().z)));
	
//	d = sqrt(((p1x - p2x) * (p1x – p2x)) + ((p1y – p2y) * (p1y – p2y)) + ((p1z – p2z) * (p1z – p2z)));

		if(d<2.0f &&  playerAI[i]->getTirer()==false)
		{
			playerAI[i]->sethastheball(true);
			
			player[j]->sethastheball(false);
			
		}
		else
		{
			playerAI[i]->sethastheball(false);	
		}
		if(playerAI[i]->gethastheball())
		{
			
			ball->setLocation(glm::vec3(playerAI[i]->getLocation().x-0.8f,ball->getLocation().y,playerAI[i]->getLocation().z));
		
		}
		
	
		
		
	}
	
}
void game::passer()
{
float x=ball->getSpeedBallJoueur()*ball->getangle().x;
float z=ball->getSpeedBallJoueur()*ball->getangle().z;


	ball->setLocationIncremente(glm::vec3(x,0,z));
	for(int j=0;j<player.size();j++)
			{
				 if(player[j]->gethastheball()==true)
				 {
				 
						ball->setangle(glm::vec3(cos(player[j]->getRot()),0,sin(-player[j]->getRot())));
					
				}
			}


				for(int j=0;j<player.size();j++)
			{
					if(getespace() && player[j]->gethastheball())
					{
						player[j]->setTirer(true);
							
				}
			}
				for(int j=0;j<player.size();j++)
			{
				if(getespace()&& player[j]->gethastheball()==false)
					{
					player[j]->setTirer(false);
					}
			}
		
				
				for(int j=0;j<player.size();j++)
				if(	player[j]->getTirer()  &&  ball->getSpeedBallJoueur()<=ball->maxSpeed_())
				{
				
			
					ball->setSpeedBallAccJoueur(ball->acce());
				}
			
				
				for(int j=0;j<player.size();j++)
				if(player[j]->getTirer()==false)
			{
				if(ball->getSpeedBallJoueur()-ball->dece()>0)
				{
					ball->setSpeedBallDecJoueur(ball->dece());
				}
				else if(ball->getSpeedBallJoueur()+ball->dece()<0)
				{
					ball->setSpeedBallDecJoueur(ball->dece());
				}
				else
				{
					ball->setSpeedBallJoueur(0);
				}
			
		
		}


				
			
			
	}
	void game::passerGoal()
	{
	
		
		
		float x=ball->getSpeedBallGoal()*ball->getangle().x;
float z=ball->getSpeedBallGoal()*ball->getangle().z;


	ball->setLocationIncremente(glm::vec3(x*0.5f,0,z));
	for(int j=0;j<goal.size();j++)
			{
				 if(goal[j]->gethastheball()==true)
				 {
				 
						ball->setangle(glm::vec3(cos(goal[j]->getRot()),0,sin(goal[j]->getRot())));
					
				}
			}


				for(int j=0;j<goal.size();j++)
			{
					if(ball->getLocation().x<-35 && ball->getLocation().x>-55 && goal[j]->gethastheball() || ball->getLocation().x<55 && ball->getLocation().x>35  && goal[j]->gethastheball())
					{
						
						goal[j]->setTirer(true);
							
				}
			else
			{
			
			
					goal[j]->setTirer(false);
					
		}
	}
		
				
				for(int j=0;j<goal.size();j++)
				if(	goal[j]->getTirer()  &&  ball->getSpeedBallGoal()<=ball->maxSpeed_())
				{
			
			
				if(ball->getSpeedBallGoal()<0)
				{
					ball->setSpeedBallAccGoal(ball->dece());
				}
				else
				{
				
					ball->setSpeedBallAccGoal(ball->acce());
				}
			}
			
				
				for(int j=0;j<goal.size();j++)
				if(goal[j]->getTirer()==false)
			{
				if(ball->getSpeedBallGoal()-ball->dece()>0)
				{
					ball->setSpeedBallDecGoal(ball->dece());
				}
				else if(ball->getSpeedBallGoal()+ball->dece()<0)
				{
					ball->setSpeedBallDecGoal(ball->dece());
				}
				else
				{
					ball->setSpeedBallGoal(0);
				}
			
		
		}


				
		
	
	


}

	void game::passerAI()
	{
	
float x=ball->getSpeedBallJoueurAI()*ball->getangle().x;
float z=ball->getSpeedBallJoueurAI()*ball->getangle().z;


	ball->setLocationIncremente(glm::vec3(-x*2.0f,0,z));
	for(int j=0;j<playerAI.size();j++)
			{
				 if(playerAI[j]->gethastheball()==true)
				 {
				 
						ball->setangle(glm::vec3(cos(playerAI[j]->getRot()),0,sin(playerAI[j]->getRot())));
					
				}
			}


				for(int j=0;j<playerAI.size();j++)
			{
					if(ball->getLocation().x<-25 && ball->getLocation().x>-55 && playerAI[j]->gethastheball())
					{
						
						playerAI[j]->setTirer(true);
							
				}
			else
			{
			
			
					playerAI[j]->setTirer(false);
					
		}
	}
		
				
				for(int j=0;j<playerAI.size();j++)
				if(	playerAI[j]->getTirer()  &&  ball->getSpeedBallJoueurAI()<=ball->maxSpeed_())
				{
			
				if(ball->getSpeedBallJoueurAI()<0)
				{
					ball->setSpeedBallAccJoueurAI(ball->dece());
				}
				else
				{
				
					ball->setSpeedBallAccJoueurAI(ball->acce());
				}
			}
			
				
				for(int j=0;j<playerAI.size();j++)
				if(playerAI[j]->getTirer()==false)
			{
				if(ball->getSpeedBallJoueurAI()-ball->dece()>0)
				{
					ball->setSpeedBallDecJoueurAI(ball->dece());
				}
				else if(ball->getSpeedBallJoueurAI()+ball->dece()<0)
				{
					ball->setSpeedBallDecJoueurAI(ball->dece());
				}
				else
				{
					ball->setSpeedBallJoueurAI(0);
				}
			
		
		}


				

}
void game::movementBall()
{
	
	
										
									if( ball->getLocation().x>=-20 && ball->getLocation().x<=20 && ball->getLocation().z>=-20.5f && ball->getLocation().z<=20  )
												{
													ball->centrer_(true);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
												
												
													
													if( ball->getLocation().x>=20.0f && ball->getLocation().x<=50 && ball->getLocation().z>=-20.5f && ball->getLocation().z<=20  )
												{
														ball->centrer_(false);
													ball->centrerAvant_(true);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
												
												
														if( ball->getLocation().x>=-20.5f && ball->getLocation().x<=50 && ball->getLocation().z>=20.5f && ball->getLocation().z<=40  )
												{
													ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(true);
													ball->centrerCoteGauche_(false);
													
												}
											
													
														if( ball->getLocation().x>=-20.5f && ball->getLocation().x<=50 && ball->getLocation().z>=-40.5f && ball->getLocation().z<=-20  )
												{
														ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(true);
													
												}
											
											
											
											
											
											
												if( ball->getLocation().x>=-50.5f && ball->getLocation().x<=0 && ball->getLocation().z>=-20.5f && ball->getLocation().z<=20  )
												{
														ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(true);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
												
													
													if( ball->getLocation().x>=-50.0f && ball->getLocation().x<0 && ball->getLocation().z>=20.5f && ball->getLocation().z<=40  )
												{
														ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(true);
													ball->centrerCoteArriereGauche_(false);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
												
												
														if( ball->getLocation().x>=-50.5f && ball->getLocation().x<=0 && ball->getLocation().z>=-40.5f && ball->getLocation().z<=-20  )
												{
													ball->centrer_(false);
													ball->centrerAvant_(false);
													ball->centrerArriere_(false);
													ball->centrerCoteArriereDroite_(false);
													ball->centrerCoteArriereGauche_(true);
													ball->centrerCoteDroit_(false);
													ball->centrerCoteGauche_(false);
													
												}
											
												
											
											
									
												
											
											
											
												
											
										
}

void game::movement()
{
	
									
									
										for(int i=0;i<10;i++)
											{
											
													
												if(   player[i]->gethastheball()==false && player[i]->getNext()==false
												)
												{
													player[i]->setattaquer(true);
												}
												else
												{
													player[i]->setattaquer(false);
												}
											
											
										
									}
									
										
//centrerarriere
										for(int i=0;i<4;i++)
											{
											if( ball->centrerArriere_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-10+i,4,-20+(12*i))))
											 {
											 	
											 }
										
									}
									
										}
									
									
										for(int i=4;i<6;i++)
											{
										if( ball->centrerArriere_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-40+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
											for(int i=6;i<10;i++)
											{
										if( ball->centrerArriere_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-30+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
								
									//centrercotearrieredroit
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteArriereDroite_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-15+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<6;i++)
											{
										if( ball->centrerCoteArriereDroite_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-40+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=6;i<10;i++)
											{
										if( ball->centrerCoteArriereDroite_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-30+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
										//centrercotearrieregauche
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteArriereGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-15+i,4,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<6;i++)
											{
										if( ball->centrerCoteArriereGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-30+i,4,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=6;i<10;i++)
											{
										if( ball->centrerCoteArriereGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-30+i,4,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
									//centreravant
									
											for(int i=0;i<4;i++)
											{
										if( ball->centrer_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(10+i,4,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrer_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(20+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrer_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-20+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									//centreravant
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerAvant_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(25+i,4,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerAvant_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
							if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(30+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerAvant_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-30+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									//centrercotedroit
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteDroit_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(15+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerCoteDroit_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(40+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerCoteDroit_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-30+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
										//centrercotegauche
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(15+i,4,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerCoteGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
											if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(30+i,4,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerCoteGauche_() && player[i]->getattaquer()&& player[i]->gethastheball()==false)
										{
										if( getup() || getdown() || getright() || getleft() )
											 if(player[i]->movement(glm::vec3(-20+i,4,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									
									
							
		
									
									
									
}

void game::movementAI()
{
	
		
							
								for(int j=0;j<playerAI.size();j++)
	{
										
										
											
													
												if(playerAI[j]->gethastheball()==false  &&  playerAI[j]->getNext()==false)
												{
													playerAI[j]->setattaquer(true);
												
												}
											
												else
												{
													playerAI[j]->setattaquer(false);
												
												}
											
											
										
									}
												for(int i=0;i<playerAI.size();i++)
											{
											if(playerAI[i]->gethastheball() && playerAI[i]->movementAI(glm::vec3(-35+i,4,0)))
			{
				
			}
		}
//centrer
										for(int i=0;i<4;i++)
											{
										if( ball->centrer_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(-10+i,4,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrer_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(20+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( ball->centrer_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(10+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerAvant_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(30+i,4,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerAvant_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(35+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( ball->centrerAvant_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(45+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									//centreravant
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerArriere_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(5+i,4,-20+(12*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerArriere_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(-10+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerArriere_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(30+i,4,-25+(7*i))))
											 {
											 	
											 }
										}
									}
									
									//centrercotedroit
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteDroit_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(-15+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerCoteDroit_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(-10+i,4,-15+(7*i))))
											 {
											 	
											 }
										}
									}
									
										for(int i=8;i<10;i++)
											{
										if( ball->centrerCoteDroit_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(10+i,4,-15+(7*i))))
											 {
											 	
											 }
										}
									}
										//centrercotegauche
									
										for(int i=0;i<4;i++)
											{
										if( ball->centrerCoteGauche_() && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(5+i,4,-35+(7*i))))
											 {
											 	
											 }
										}
									}
									
											
									
									
										for(int i=4;i<8;i++)
											{
										if( ball->centrerCoteGauche_()  && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(-10+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
											for(int i=8;i<10;i++)
											{
										if( ball->centrerCoteGauche_()  && playerAI[i]->getattaquer()&& playerAI[i]->gethastheball()==false)
										{
											
											 if(playerAI[i]->movementAI(glm::vec3(30+i,4,-5+(7*i))))
											 {
											 	
											 }
										}
									}
									
									
									
									
												
							
										
//centrer
									
											
							
		
	
}

bool game::limitBalle()
{
	if(ball->getLocation().x>48)
	{
	return true;
	
}
else if(ball->getLocation().x<-48)
{
		return true;
}
else if(ball->getLocation().z>40)
{
			return true;
}
  else if(ball->getLocation().z<-40)
{
		return true;
}
else
{

return false;

}
}

void game::limitJoueur()
{
	
 if(player[0]->getLocation().x>49)
{
	player[0]->setLocation(glm::vec3(0,10,0));
}
 if(player[1]->getLocation().x>49)
{
	player[1]->setLocation(glm::vec3(0,10,0));
}
 if(player[2]->getLocation().x>49)
{
	player[2]->setLocation(glm::vec3(0,10,0));
}
 if(player[3]->getLocation().x>49)
{
	player[3]->setLocation(glm::vec3(0,10,0));
}
 if(player[4]->getLocation().x>49)
{
	player[4]->setLocation(glm::vec3(0,10,0));
}
 if(player[5]->getLocation().x>49)
{
	player[5]->setLocation(glm::vec3(0,10,0));
}
 if(player[6]->getLocation().x>49)
{
	player[6]->setLocation(glm::vec3(0,10,0));
}
 if(player[7]->getLocation().x>49)
{
	player[7]->setLocation(glm::vec3(0,10,0));
}
 if(player[8]->getLocation().x>49)
{
	player[8]->setLocation(glm::vec3(0,10,0));
}
 if(player[9]->getLocation().x>49)
{
	player[9]->setLocation(glm::vec3(0,10,0));
}
 if(player[0]->getLocation().x<-49)
{
	player[0]->setLocation(glm::vec3(0,10,0));
}
 if(player[1]->getLocation().x<-49)
{
	player[1]->setLocation(glm::vec3(0,10,0));
}
 if(player[2]->getLocation().x<-49)
{
	player[2]->setLocation(glm::vec3(0,10,0));
}
 if(player[3]->getLocation().x<-49)
{
	player[3]->setLocation(glm::vec3(0,10,0));
}
 if(player[4]->getLocation().x<-49)
{
	player[4]->setLocation(glm::vec3(0,10,0));
}
 if(player[5]->getLocation().x<-49)
{
	player[5]->setLocation(glm::vec3(0,10,0));
}
 if(player[6]->getLocation().x<-49)
{
	player[7]->setLocation(glm::vec3(0,10,0));
}
 if(player[8]->getLocation().x<-49)
{
	player[8]->setLocation(glm::vec3(0,10,0));
}
 if(player[9]->getLocation().x<-49)
{
	player[9]->setLocation(glm::vec3(0,10,0));
}

 if(playerAI[0]->getLocation().x>49)
{
	playerAI[0]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[1]->getLocation().x>49)
{
	playerAI[1]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[2]->getLocation().x>49)
{
	playerAI[2]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[3]->getLocation().x>49)
{
	playerAI[3]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[4]->getLocation().x>49)
{
	playerAI[4]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[5]->getLocation().x>49)
{
	playerAI[5]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[6]->getLocation().x>49)
{
	playerAI[6]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[7]->getLocation().x>49)
{
	playerAI[7]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[8]->getLocation().x>49)
{
	playerAI[8]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[9]->getLocation().x>49)
{
	playerAI[9]->setLocation(glm::vec3(0,10,0));
}

 if(playerAI[0]->getLocation().x<-49)
{
	playerAI[0]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[1]->getLocation().x<-49)
{
	playerAI[1]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[2]->getLocation().x<-49)
{
	playerAI[2]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[3]->getLocation().x<-49)
{
	playerAI[3]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[4]->getLocation().x<-49)
{
	playerAI[4]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[5]->getLocation().x<-49)
{
	playerAI[5]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[6]->getLocation().x<-49)
{
	playerAI[6]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[7]->getLocation().x<-49)
{
	playerAI[7]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[8]->getLocation().x<-49)
{
	playerAI[8]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[9]->getLocation().x<-49)
{
	playerAI[9]->setLocation(glm::vec3(0,10,0));
}






if(player[0]->getLocation().z>38)
{
	player[0]->setLocation(glm::vec3(0,10,0));
}
 if(player[1]->getLocation().z>38)
{
	player[1]->setLocation(glm::vec3(0,10,0));
}
 if(player[2]->getLocation().z>38)
{
	player[2]->setLocation(glm::vec3(0,10,0));
}
 if(player[3]->getLocation().z>38)
{
	player[3]->setLocation(glm::vec3(0,10,0));
}
 if(player[4]->getLocation().z>38)
{
	player[4]->setLocation(glm::vec3(0,10,0));
}
 if(player[5]->getLocation().z>38)
{
	player[5]->setLocation(glm::vec3(0,10,0));
}
 if(player[6]->getLocation().z>38)
{
	player[6]->setLocation(glm::vec3(0,10,0));
}
 if(player[7]->getLocation().z>38)
{
	player[7]->setLocation(glm::vec3(0,10,0));
}
 if(player[8]->getLocation().z>38)
{
	player[8]->setLocation(glm::vec3(0,10,0));
}
 if(player[9]->getLocation().z>38)
{
	player[9]->setLocation(glm::vec3(0,10,0));
}
 if(player[0]->getLocation().z<-38)
{
	player[0]->setLocation(glm::vec3(0,10,0));
}
 if(player[1]->getLocation().z<-38)
{
	player[1]->setLocation(glm::vec3(0,10,0));
}
 if(player[2]->getLocation().z<-38)
{
	player[2]->setLocation(glm::vec3(0,10,0));
}
 if(player[3]->getLocation().z<-38)
{
	player[3]->setLocation(glm::vec3(0,10,0));
}
 if(player[4]->getLocation().z<-38)
{
	player[4]->setLocation(glm::vec3(0,10,0));
}
 if(player[5]->getLocation().z<-38)
{
	player[5]->setLocation(glm::vec3(0,10,0));
}
 if(player[6]->getLocation().z<-38)
{
	player[7]->setLocation(glm::vec3(0,10,0));
}
 if(player[8]->getLocation().z<-38)
{
	player[8]->setLocation(glm::vec3(0,10,0));
}
 if(player[9]->getLocation().z<-38)
{
	player[9]->setLocation(glm::vec3(0,10,0));
}

 if(playerAI[0]->getLocation().z>38)
{
	playerAI[0]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[1]->getLocation().z>38)
{
	playerAI[1]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[2]->getLocation().z>38)
{
	playerAI[2]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[3]->getLocation().z>38)
{
	playerAI[3]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[4]->getLocation().z>38)
{
	playerAI[4]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[5]->getLocation().z>38)
{
	playerAI[5]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[6]->getLocation().z>38)
{
	playerAI[6]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[7]->getLocation().z>38)
{
	playerAI[7]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[8]->getLocation().z>38)
{
	playerAI[8]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[9]->getLocation().z>38)
{
	playerAI[9]->setLocation(glm::vec3(0,10,0));
}

 if(playerAI[0]->getLocation().z<-38)
{
	playerAI[0]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[1]->getLocation().z<-38)
{
	playerAI[1]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[2]->getLocation().z<-38)
{
	playerAI[2]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[3]->getLocation().z<-38)
{
	playerAI[3]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[4]->getLocation().z<-38)
{
	playerAI[4]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[5]->getLocation().z<-38)
{
	playerAI[5]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[6]->getLocation().z<-38)
{
	playerAI[6]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[7]->getLocation().z<-38)
{
	playerAI[7]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[8]->getLocation().z<-38)
{
	playerAI[8]->setLocation(glm::vec3(0,10,0));
}
 if(playerAI[9]->getLocation().z<-38)
{
	playerAI[9]->setLocation(glm::vec3(0,10,0));
}



}

void game::followAI()
{
		glm::vec3 Distance = playerAI[0]->getLocation()-ball->getLocation();
		glm::vec3 Distance2 = playerAI[1]->getLocation()-ball->getLocation();
			glm::vec3 Distance3 = playerAI[2]->getLocation()-ball->getLocation();
		glm::vec3 Distance4 = playerAI[3]->getLocation()-ball->getLocation();
		glm::vec3 Distance5 = playerAI[4]->getLocation()-ball->getLocation();
		glm::vec3 Distance6 = playerAI[5]->getLocation()-ball->getLocation();
		glm::vec3 Distance7 = playerAI[6]->getLocation()-ball->getLocation();
		glm::vec3 Distance8 = playerAI[7]->getLocation()-ball->getLocation();
		glm::vec3 Distance9 = playerAI[8]->getLocation()-ball->getLocation();
		glm::vec3 Distance10 = playerAI[9]->getLocation()-ball->getLocation();
		float hypotenuse = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hypotenuse2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hypotenuse3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hypotenuse4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hypotenuse5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hypotenuse6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hypotenuse7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hypotenuse8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hypotenuse9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hypotenuse10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));

	if(hypotenuse<hypotenuse2 && hypotenuse<hypotenuse3 && hypotenuse<hypotenuse4 && hypotenuse<hypotenuse5 && hypotenuse<hypotenuse6 && hypotenuse<hypotenuse7 && hypotenuse<hypotenuse8 && hypotenuse<hypotenuse9 
&& hypotenuse<hypotenuse10 && hypotenuse>1)
{
playerAI[0]->setNext(true);
}
else
{
playerAI[0]->setNext(false);
}
if(playerAI[0]->getNext()  )
{



											playerAI[0]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
										
}


if(hypotenuse2<hypotenuse && hypotenuse2<hypotenuse3 && hypotenuse2<hypotenuse4 && hypotenuse2<hypotenuse5 && hypotenuse2<hypotenuse6 && hypotenuse2<hypotenuse7 && hypotenuse2<hypotenuse8 && hypotenuse2<hypotenuse9 
&& hypotenuse2<hypotenuse10 &&hypotenuse2>1)
{
			
playerAI[1]->setNext(true);
}
else
{
playerAI[1]->setNext(false);
}
			if(playerAI[1]->getNext() )
			{
										playerAI[1]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
										
}
if(hypotenuse3<hypotenuse && hypotenuse3<hypotenuse2 && hypotenuse3<hypotenuse4 && hypotenuse3<hypotenuse5 && hypotenuse3<hypotenuse6 && hypotenuse3<hypotenuse7 && hypotenuse3<hypotenuse8 && hypotenuse3<hypotenuse9 
&& hypotenuse3<hypotenuse10 &&hypotenuse3>1)
{
playerAI[2]->setNext(true);
}
else
{
playerAI[2]->setNext(false);
}
if(playerAI[2]->getNext()   )
{


										playerAI[2]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
}

if(hypotenuse4<hypotenuse && hypotenuse4<hypotenuse2 && hypotenuse4<hypotenuse3 && hypotenuse4<hypotenuse5 && hypotenuse4<hypotenuse6 && hypotenuse4<hypotenuse7 && hypotenuse4<hypotenuse8 && hypotenuse4<hypotenuse9 
&& hypotenuse4<hypotenuse10 &&hypotenuse4>1)
{
playerAI[3]->setNext(true);
}
else
{
playerAI[3]->setNext(false);
}
if(playerAI[3]->getNext()  )
{


											playerAI[3]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
}


if(hypotenuse5<hypotenuse && hypotenuse5<hypotenuse2 && hypotenuse5<hypotenuse3 && hypotenuse5<hypotenuse4 && hypotenuse5<hypotenuse6 && hypotenuse5<hypotenuse7 && hypotenuse5<hypotenuse8 && hypotenuse5<hypotenuse9
&& hypotenuse5<hypotenuse10  &&hypotenuse5>1)
{
playerAI[4]->setNext(true);
}
else
{
playerAI[4]->setNext(false);
}
if(playerAI[4]->getNext()  )
{

				
											playerAI[4]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
}


if(hypotenuse6<hypotenuse && hypotenuse6<hypotenuse2 && hypotenuse6<hypotenuse3 && hypotenuse6<hypotenuse4 && hypotenuse6<hypotenuse5 && hypotenuse6<hypotenuse7 && hypotenuse6<hypotenuse8 && hypotenuse6<hypotenuse9 
&& hypotenuse6<hypotenuse10 &&hypotenuse6>1 )
{
playerAI[5]->setNext(true);
}
else
{
playerAI[5]->setNext(false);
}
if(playerAI[5]->getNext() )
{


											playerAI[5]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
										
}


if(hypotenuse7<hypotenuse && hypotenuse7<hypotenuse2 && hypotenuse7<hypotenuse3 && hypotenuse7<hypotenuse4 && hypotenuse7<hypotenuse5 && hypotenuse7<hypotenuse6 && hypotenuse7<hypotenuse8 && hypotenuse7<hypotenuse9 
&& hypotenuse7<hypotenuse10 &&hypotenuse7>1 )
{
playerAI[6]->setNext(true);
}
else
{
playerAI[6]->setNext(false);
}
if(playerAI[6]->getNext()  )
{

							playerAI[6]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
}




if(hypotenuse8<hypotenuse && hypotenuse8<hypotenuse2 && hypotenuse8<hypotenuse3 && hypotenuse8<hypotenuse4 && hypotenuse8<hypotenuse5 && hypotenuse8<hypotenuse6 && hypotenuse8<hypotenuse7 && hypotenuse8<hypotenuse9 
&& hypotenuse8<hypotenuse10 &&hypotenuse8>1 )
{

playerAI[7]->setNext(true);
}
else
{
playerAI[7]->setNext(false);
}
if(playerAI[7]->getNext()  )
{


									playerAI[7]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
							
}


if(hypotenuse9<hypotenuse && hypotenuse9<hypotenuse2 && hypotenuse9<hypotenuse3 && hypotenuse9<hypotenuse4 && hypotenuse9<hypotenuse5 && hypotenuse9<hypotenuse6 && hypotenuse9<hypotenuse7 && hypotenuse9<hypotenuse8 
&& hypotenuse9<hypotenuse10  &&hypotenuse9>1)
{
playerAI[8]->setNext(true);
}
else
{
playerAI[8]->setNext(false);
}
if(playerAI[8]->getNext()  )
{


											playerAI[8]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
										
}


if(hypotenuse10<hypotenuse && hypotenuse10<hypotenuse2 && hypotenuse10<hypotenuse3 && hypotenuse10<hypotenuse4 && hypotenuse10<hypotenuse5 && hypotenuse10<hypotenuse6 && hypotenuse10<hypotenuse7 && hypotenuse10<hypotenuse8 
&&  hypotenuse10<hypotenuse9&&hypotenuse10>1)
{
playerAI[9]->setNext(true);
}
else
{
playerAI[9]->setNext(false);
}
if(playerAI[9]->getNext()   )
{



	playerAI[9]->movementAI(glm::vec3(ball->getLocation().x,3.5f,ball->getLocation().z));
										
}


	
								
									
								
							

}
void game::follow()
{//si joueur proche de lennemi alors suivre ennemi
	glm::vec3 Distance = player[0]->getLocation()-ball->getLocation();
		glm::vec3 Distance2 = player[1]->getLocation()-ball->getLocation();
			glm::vec3 Distance3 = player[2]->getLocation()-ball->getLocation();
		glm::vec3 Distance4 = player[3]->getLocation()-ball->getLocation();
		glm::vec3 Distance5 = player[4]->getLocation()-ball->getLocation();
		glm::vec3 Distance6 = player[5]->getLocation()-ball->getLocation();
		glm::vec3 Distance7 = player[6]->getLocation()-ball->getLocation();
		glm::vec3 Distance8 = player[7]->getLocation()-ball->getLocation();
		glm::vec3 Distance9 = player[8]->getLocation()-ball->getLocation();
		glm::vec3 Distance10 = player[9]->getLocation()-ball->getLocation();
		float hyp1 = sqrt((Distance.x * Distance.x) + (Distance.z * Distance.z));
float hyp2 = sqrt((Distance2.x * Distance2.x) + (Distance2.z * Distance2.z));
float hyp3 = sqrt((Distance3.x * Distance3.x) + (Distance3.z * Distance3.z));
float hyp4 = sqrt((Distance4.x * Distance4.x) + (Distance4.z * Distance4.z));
float hyp5 = sqrt((Distance5.x * Distance5.x) + (Distance5.z * Distance5.z));
float hyp6 = sqrt((Distance6.x * Distance6.x) + (Distance6.z * Distance6.z));
float hyp7 = sqrt((Distance7.x * Distance7.x) + (Distance7.z * Distance7.z));
float hyp8 = sqrt((Distance8.x * Distance8.x) + (Distance8.z * Distance8.z));
float hyp9 = sqrt((Distance9.x * Distance9.x) + (Distance9.z * Distance9.z));
float hyp10 = sqrt((Distance10.x * Distance10.x) + (Distance10.z * Distance10.z));



if(hyp1<=hyp2 && hyp1<=hyp3 && hyp1<=hyp4 && hyp1<=hyp5 && hyp1<=hyp6  && hyp1<=hyp7 && hyp1<=hyp8 && hyp1<=hyp9 && hyp1<=hyp10
   )
   {
     
    player[0]->setNext(true);
  
    
     
   }
    else
   {
       player[0]->setNext(false);
    
   
   }
      if(hyp2<=hyp1 && hyp2<=hyp3 && hyp2<=hyp4 && hyp2<=hyp5 && hyp2<=hyp6 && hyp2<=hyp7 && hyp2<=hyp8 && hyp2<=hyp9 && hyp2<=hyp10
      )
   {
     

       player[1]->setNext(true);
    
    
     
   }
   else
   {
       player[1]->setNext(false);
   }
   if(hyp3<=hyp1 && hyp3<=hyp2 && hyp3<=hyp4 && hyp3<=hyp5 && hyp3<=hyp6 && hyp3<=hyp7 && hyp3<=hyp8 && hyp3<=hyp9 && hyp3<=hyp10)
   {
      
       player[2]->setNext(true);
     
   }
   else
   {
       player[2]->setNext(false);
   }
  
  if(hyp4<=hyp1 && hyp4<=hyp2 && hyp4<=hyp3 && hyp4<=hyp5 && hyp4<=hyp6 && hyp4<=hyp7 && hyp4<=hyp8 && hyp4<=hyp9 && hyp4<=hyp10)
   {
    
       player[3]->setNext(true);
   
   }
   else
   {
       player[3]->setNext(false);
   }
   if(hyp5<=hyp1 && hyp5<=hyp2 && hyp5<=hyp3 && hyp5<=hyp4 && hyp5<=hyp6  && hyp5<=hyp7 && hyp5<=hyp8 && hyp5<=hyp9 && hyp5<=hyp10)
   {
    
       player[4]->setNext(true);
   
   }
   else
   {
       player[4]->setNext(false);
   }
  
 if(hyp6<=hyp1 && hyp6<=hyp2 && hyp6<=hyp3 && hyp6<=hyp4 && hyp6<=hyp5  && hyp6<=hyp7 && hyp6<=hyp8 && hyp6<=hyp9 && hyp6<=hyp10
 )
   {
    
       player[5]->setNext(true);
   
   }
   else
   {
       player[5]->setNext(false);
   }
  
 if(hyp7<=hyp1 && hyp7<=hyp2 && hyp7<=hyp3 && hyp7<=hyp4 && hyp7<=hyp5  && hyp7<=hyp6 && hyp7<=hyp8 && hyp7<=hyp9 && hyp7<=hyp10 )
   {
    
       player[6]->setNext(true);
   
   }
   else
   {
       player[6]->setNext(false);
   }
  if(hyp8<=hyp1 && hyp8<=hyp2 && hyp8<=hyp3 && hyp8<=hyp4 && hyp8<=hyp5  && hyp8<=hyp6 && hyp8<=hyp10
 )
   {
    
       player[7]->setNext(true);
   
   }
   else
   {
       player[7]->setNext(false);
   }

   
    if(hyp9<=hyp1 && hyp9<=hyp2 && hyp9<=hyp3 && hyp9<=hyp4 && hyp9<=hyp5   && hyp9<=hyp10
 )
   {
    
       player[8]->setNext(true);
   
   }
   else
   {
       player[8]->setNext(false);
   }

    if(hyp10<=hyp1  && hyp10<=hyp2 && hyp10<=hyp3 && hyp10<=hyp4  && hyp10<=hyp6 && hyp10<=hyp7 && hyp10<=hyp8 && hyp10<=hyp9
 )
   {
    
       player[9]->setNext(true);
   
   }
   else
   {
  
       player[9]->setNext(false);
   }
  
 
   
    if(player[0]->getNext())
{



										input();
										
}

if(player[1]->getNext())
{



										input2();
										
}
if(player[2]->getNext())
{



										input3();
										
}
if(player[3]->getNext())
{



										input4();
										
}
if(player[4]->getNext())
{



										input5();
										
}
if(player[5]->getNext())
{



										input6();
										
}
if(player[6]->getNext())
{



										input7();
										
}
if(player[7]->getNext())
{



										input8();
										
}
if(player[8]->getNext())
{



										input9();
										
}
if(player[9]->getNext())
{



										input10();
										
}
   
if(player[0]->gethastheball())
{
	input();
}
	
if(player[1]->gethastheball())
{
	input2();
}
	
if(player[2]->gethastheball())
{
	input3();
}
	
if(player[3]->gethastheball())
{
	input4();
}
	
if(player[4]->gethastheball())
{
	input5();
}
	
if(player[5]->gethastheball())
{
	input6();
}
	
if(player[6]->gethastheball())
{
	input7();
}
	
if(player[7]->gethastheball())
{
	input8();
}
	
if(player[8]->gethastheball())
{
	input9();
}
	
if(player[9]->gethastheball())
{
	input10();
}


	

}

void game::input()
{

		if(getup())
	{
			
			player[0]->update(glm::vec3(0.02,0,0));
			player[0]->setRot(0.0f);
		
	}
		if(getdown())
	{
			player[0]->setRot(3.0f);
			player[0]->update(glm::vec3(-0.02,0,0));
			
	}
	if(getright())
	{
		player[0]->setRot(-1.5f);
			player[0]->update(glm::vec3(0.0,0,0.02));
			
			
	}
	if(getleft())
	{
		player[0]->setRot(1.5f);
			player[0]->update(glm::vec3(0.0,0,-0.02));

	}
	if(getup() && getright())
	{
			player[0]->setRot(-0.75f);
			
	}
		if(getup() && getleft())
	{
			player[0]->setRot(0.75f);
		
	}
		if(getdown() && getright())
	{
			player[0]->setRot(-2.25f);
			
				}
		if(getdown() && getleft())
	{
			player[0]->setRot(2.25f);
		
	}
}
void game::input2()
{
		if(getup())
	{

			player[1]->update(glm::vec3(0.02,0,0));
			player[1]->setRot(0.0f);
	}
		if(getdown())
	{
			player[1]->setRot(3.0f);
			player[1]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[1]->setRot(-1.5f);
			player[1]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[1]->setRot(1.5f);
			player[1]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[1]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[1]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[1]->setRot(-2.25f);
	}
		if(getdown() && getleft())
	{
			player[1]->setRot(2.25f);
	}
}
void game::input3()
{
			if(getup())
	{
		
			player[2]->update(glm::vec3(0.02,0,0));
			player[2]->setRot(0.0f);
	}
		if(getdown())
	{
			player[2]->setRot(3.0f);
			player[2]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[2]->setRot(-1.5f);
			player[2]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[2]->setRot(1.5f);
			player[2]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[2]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[2]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[2]->setRot(-2.25f);
	}
		if(getdown() && getleft())
	{
			player[2]->setRot(2.25f);
	}
}
void game::input4()
{
		if(getup())
	{
		
			player[3]->update(glm::vec3(0.02,0,0));
			player[3]->setRot(0.0f);
	}
		if(getdown())
	{
			player[3]->setRot(3.0f);
			player[3]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[3]->setRot(-1.5f);
			player[3]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[3]->setRot(1.5f);
			player[3]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[3]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[3]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[3]->setRot(-2.25f);
	}
		if(getdown() && getleft())
	{
			player[3]->setRot(2.25f);
	}
}
void game::input5()
{
			if(getup())
	{
		
			player[4]->update(glm::vec3(0.02,0,0));
			player[4]->setRot(0.0f);
	}
		if(getdown())
	{
			player[4]->setRot(3.0f);
			player[4]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[4]->setRot(-1.5f);
			player[4]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[4]->setRot(1.5f);
			player[4]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[4]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[4]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[4]->setRot(-2.25f);
	}
		if(getdown() && getleft())
	{
			player[4]->setRot(2.25f);
	}
}
void game::input6()
{
		if(getup())
	{
		
			player[5]->update(glm::vec3(0.02,0,0));
			player[5]->setRot(0.0f);
	}
		if(getdown())
	{
			player[5]->setRot(3.0f);
			player[5]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[5]->setRot(-1.5f);
			player[5]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[5]->setRot(1.5f);
			player[5]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[5]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[5]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[5]->setRot(2.25f);
	}
		if(getdown() && getleft())
	{
			player[5]->setRot(-2.25f);
	}
}
void game::input7()
{
		if(getup())
	{
		
			player[6]->update(glm::vec3(0.02,0,0));
			player[6]->setRot(0.0f);
	}
		if(getdown())
	{
			player[6]->setRot(3.0f);
			player[6]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[6]->setRot(-1.5f);
			player[6]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[6]->setRot(1.5f);
			player[6]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[6]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[6]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[6]->setRot(-2.25f);
	}
		if(getdown() && getleft())
	{
			player[6]->setRot(2.25f);
	}
}
void game::input8()
{
		if(getup())
	{
		
			player[7]->update(glm::vec3(0.02,0,0));
			player[7]->setRot(0.0f);
	}
		if(getdown())
	{
			player[7]->setRot(3.0f);
			player[7]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[7]->setRot(-1.5f);
			player[7]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[7]->setRot(1.5f);
			player[7]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[7]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[7]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[7]->setRot(-2.25f);
	}
		if(getdown() && getleft())
	{
			player[7]->setRot(2.25f);
	}
}
void game::input9()
{
		if(getup())
	{
		
			player[8]->update(glm::vec3(0.02,0,0));
			player[8]->setRot(0.0f);
	}
		if(getdown())
	{
			player[8]->setRot(3.0f);
			player[8]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[8]->setRot(-1.5f);
			player[8]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[8]->setRot(1.5f);
			player[8]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[8]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[8]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[8]->setRot(-2.25f);
	}
		if(getdown() && getleft())
	{
			player[8]->setRot(2.25f);
	}
}
void game::input10()
{
		if(getup())
	{
		
			player[9]->update(glm::vec3(0.02,0,0));
			player[9]->setRot(0.0f);
	}
		if(getdown())
	{
			player[9]->setRot(3.0f);
			player[9]->update(glm::vec3(-0.02,0,0));
	}
	if(getright())
	{
		player[9]->setRot(-1.5f);
			player[9]->update(glm::vec3(0.0,0,0.02));
	}
	if(getleft())
	{
		player[9]->setRot(1.5f);
			player[9]->update(glm::vec3(0.0,0,-0.02));
	}
	if(getup() && getright())
	{
			player[9]->setRot(-0.75f);
	}
		if(getup() && getleft())
	{
			player[9]->setRot(0.75f);
	}
		if(getdown() && getright())
	{
			player[9]->setRot(-2.25f);
	}
		if(getdown() && getleft())
	{
			player[9]->setRot(2.25f);
	}
}


void game::goal_()
{
	if(ball->getLocation().x>47 && ball->getLocation().z>-10 && ball->getLocation().z<10)
	{
		scoreA+=1;
	}
		if(ball->getLocation().x<-47 && ball->getLocation().z>-10 && ball->getLocation().z<10)
	{
		scoreB+=1;
	}
}
void game::update()
{
cam->setLocation(ball->getLocation(),ball->getRot());
//printf("Allemagne:%d - France:%d\n",scoreA,scoreB);
//printf("temps: %f\n",temps);
//printf("mitemps: %d\n",mitemps);
if(temps>=205)
{
	mitemps+=1;
	temps=0;
	ball->setLocation(glm::vec3(0,2.3f,0));
}
if(mitemps>=2)
{
	mitemps=0;
	ball->setLocation(glm::vec3(0,2.3f,0));
}
	if(startgame<3)
	{
		temps+=0.01f;
		 player[0]->movement(glm::vec3(0,10,0));
   player[1]->movement(glm::vec3(-10,10,10));
    player[2]->movement(glm::vec3(-10,10,5));
     player[3]->movement(glm::vec3(-20,10,-20));
      player[4]->movement(glm::vec3(-20,10,-10));
       player[5]->movement(glm::vec3(-30,10,10));
        player[6]->movement(glm::vec3(-30,10,-10));
         player[7]->movement(glm::vec3(-40,10,0));
         player[8]->movement(glm::vec3(-40,10,-5));
          player[9]->movement(glm::vec3(-40,10,-10));
           playerAI[0]->movement(glm::vec3(5,10,0));
            playerAI[1]->movement(glm::vec3(10,10,10));
             playerAI[2]->movement(glm::vec3(10,10,5));
                playerAI[3]->movement(glm::vec3(20,10,-20));
                   playerAI[4]->movement(glm::vec3(20,10,-10));
                      playerAI[5]->movement(glm::vec3(30,10,10));
                         playerAI[6]->movement(glm::vec3(30,10,-10));
   						playerAI[7]->movement(glm::vec3(40,10,0));
     						 playerAI[8]->movement(glm::vec3(40,10,-5));
        					 playerAI[9]->movement(glm::vec3(40,10,-10));

}


if(startgame>3 && startgame<10 && temps>15)
{

		temps+=0.01f;
	if(goal[0]->movementGOAL(ball->getLocation()))
	{
		
	}
	if(goal[1]->movementGOALAI(ball->getLocation()))
	{
		
	}
	collisionGOAL();
	collision();
	collisionAI();
	follow();
	followAI();
	goal_();
	movement();
	movementAI();
	movementBall();
	passer();
	passerAI();
	passerGoal();

			if(limitBalle())
	{
	ball->setLocation(glm::vec3(0,ball->getLocation().y,0));
	ball->setSpeedBallJoueur(0);
	ball->setSpeedBallJoueurAI(0);
ball->setSpeedBallGoal(0);

  player[0]->setLocation(glm::vec3(0,5,0));
 player[1]->setLocation(glm::vec3(-10,5,2));
  player[2]->setLocation(glm::vec3(-15,5,5));
  player[3]->setLocation(glm::vec3(-20,5,-10));
  player[4]->setLocation(glm::vec3(-20,5,-10));
  player[5]->setLocation(glm::vec3(-30,5,5));
  player[6]->setLocation(glm::vec3(-30,5,-10));
  player[7]->setLocation(glm::vec3(-40,5,0));
  player[8]->setLocation(glm::vec3(-40,5,-5));
  player[9]->setLocation(glm::vec3(-40,5,-10));
  
    playerAI[0]->setLocation(glm::vec3(0,5,0));
 playerAI[1]->setLocation(glm::vec3(10,5,10));
  playerAI[2]->setLocation(glm::vec3(10,5,5));
  playerAI[3]->setLocation(glm::vec3(20,5,-20));
  playerAI[4]->setLocation(glm::vec3(20,5,-10));
  playerAI[5]->setLocation(glm::vec3(30,5,10));
  playerAI[6]->setLocation(glm::vec3(30,5,-10));
  playerAI[7]->setLocation(glm::vec3(40,5,0));
  playerAI[8]->setLocation(glm::vec3(40,5,-5));
  playerAI[9]->setLocation(glm::vec3(40,5,-10));
  
	}
 limitJoueur();

}


	
}
void game::draw()
{

update();

glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glClearColor(0.6,0.6,0.8,1.0);



cam->computeMatricesFromInputs();





membres_[0]->setLocation(player[0]->getLocation()+glm::vec3(0,-0.0,0));
membres_[1]->setLocation(player[1]->getLocation()+glm::vec3(0,-0.0,0));
membres_[2]->setLocation(player[2]->getLocation()+glm::vec3(0,-0.0,0));
membres_[3]->setLocation(player[3]->getLocation()+glm::vec3(0,-0.0,0));
membres_[4]->setLocation(player[4]->getLocation()+glm::vec3(0,-0.0,0));
membres_[5]->setLocation(player[5]->getLocation()+glm::vec3(0,-0.0,0));
membres_[6]->setLocation(player[6]->getLocation()+glm::vec3(0,-0.0,0));
membres_[7]->setLocation(player[7]->getLocation()+glm::vec3(0,-0.0,0));
membres_[8]->setLocation(player[8]->getLocation()+glm::vec3(0,-0.0,0));
membres_[9]->setLocation(player[9]->getLocation()+glm::vec3(0,-0.0,0));

membres_[10]->setLocation(playerAI[0]->getLocation()+glm::vec3(0,-0.0,0));
membres_[11]->setLocation(playerAI[1]->getLocation()+glm::vec3(0,-0.0,0));
membres_[12]->setLocation(playerAI[2]->getLocation()+glm::vec3(0,-0.0,0));
membres_[13]->setLocation(playerAI[3]->getLocation()+glm::vec3(0,-0.0,0));
membres_[14]->setLocation(playerAI[4]->getLocation()+glm::vec3(0,-0.0,0));
membres_[15]->setLocation(playerAI[5]->getLocation()+glm::vec3(0,-0.0,0));
membres_[16]->setLocation(playerAI[6]->getLocation()+glm::vec3(0,-0.0,0));
membres_[17]->setLocation(playerAI[7]->getLocation()+glm::vec3(0,-0.0,0));
membres_[18]->setLocation(playerAI[8]->getLocation()+glm::vec3(0,-0.0,0));
membres_[19]->setLocation(playerAI[9]->getLocation()+glm::vec3(0,-0.0,0));
membres_[20]->setLocation(goal[0]->getLocation()+glm::vec3(0,-0.0,0));
membres_[21]->setLocation(goal[1]->getLocation()+glm::vec3(0,-0.0,0));

membres_[0]->setRotation(player[0]->getRot());
membres_[1]->setRotation(player[1]->getRot());
membres_[2]->setRotation(player[2]->getRot());
membres_[3]->setRotation(player[3]->getRot());
membres_[4]->setRotation(player[4]->getRot());
membres_[5]->setRotation(player[5]->getRot());
membres_[6]->setRotation(player[6]->getRot());
membres_[7]->setRotation(player[7]->getRot());
membres_[8]->setRotation(player[8]->getRot());
membres_[9]->setRotation(player[9]->getRot());

membres_[10]->setRotation(playerAI[0]->getRot());
membres_[11]->setRotation(playerAI[1]->getRot());
membres_[12]->setRotation(playerAI[2]->getRot());
membres_[13]->setRotation(playerAI[3]->getRot());
membres_[14]->setRotation(playerAI[4]->getRot());
membres_[15]->setRotation(playerAI[5]->getRot());
membres_[16]->setRotation(playerAI[6]->getRot());
membres_[17]->setRotation(playerAI[7]->getRot());
membres_[18]->setRotation(playerAI[8]->getRot());
membres_[19]->setRotation(playerAI[9]->getRot());

membres_[20]->setRotation(goal[0]->getRot());
membres_[21]->setRotation(goal[1]->getRot());

membres2_[0]->setLocation(player[0]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[1]->setLocation(player[1]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[2]->setLocation(player[2]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[3]->setLocation(player[3]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[4]->setLocation(player[4]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[5]->setLocation(player[5]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[6]->setLocation(player[6]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[7]->setLocation(player[7]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[8]->setLocation(player[8]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[9]->setLocation(player[9]->getLocation()+glm::vec3(0,-0.0,0));

membres2_[10]->setLocation(playerAI[0]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[11]->setLocation(playerAI[1]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[12]->setLocation(playerAI[2]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[13]->setLocation(playerAI[3]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[14]->setLocation(playerAI[4]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[15]->setLocation(playerAI[5]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[16]->setLocation(playerAI[6]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[17]->setLocation(playerAI[7]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[18]->setLocation(playerAI[8]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[19]->setLocation(playerAI[9]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[20]->setLocation(goal[0]->getLocation()+glm::vec3(0,-0.0,0));
membres2_[21]->setLocation(goal[1]->getLocation()+glm::vec3(0,-0.0,0));

membres2_[0]->setRotation(player[0]->getRot());
membres2_[1]->setRotation(player[1]->getRot());
membres2_[2]->setRotation(player[2]->getRot());
membres2_[3]->setRotation(player[3]->getRot());
membres2_[4]->setRotation(player[4]->getRot());
membres2_[5]->setRotation(player[5]->getRot());
membres2_[6]->setRotation(player[6]->getRot());
membres2_[7]->setRotation(player[7]->getRot());
membres2_[8]->setRotation(player[8]->getRot());
membres2_[9]->setRotation(player[9]->getRot());


membres2_[10]->setRotation(playerAI[0]->getRot());
membres2_[11]->setRotation(playerAI[1]->getRot());
membres2_[12]->setRotation(playerAI[2]->getRot());
membres2_[13]->setRotation(playerAI[3]->getRot());
membres2_[14]->setRotation(playerAI[4]->getRot());
membres2_[15]->setRotation(playerAI[5]->getRot());
membres2_[16]->setRotation(playerAI[6]->getRot());
membres2_[17]->setRotation(playerAI[7]->getRot());
membres2_[18]->setRotation(playerAI[8]->getRot());
membres2_[19]->setRotation(playerAI[9]->getRot());
membres2_[20]->setRotation(goal[0]->getRot());
membres2_[21]->setRotation(goal[1]->getRot());

membres3_[0]->setLocation(player[0]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[1]->setLocation(player[1]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[2]->setLocation(player[2]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[3]->setLocation(player[3]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[4]->setLocation(player[4]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[5]->setLocation(player[5]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[6]->setLocation(player[6]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[7]->setLocation(player[7]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[8]->setLocation(player[8]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[9]->setLocation(player[9]->getLocation()+glm::vec3(0,-0.0,0));

membres3_[10]->setLocation(playerAI[0]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[11]->setLocation(playerAI[1]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[12]->setLocation(playerAI[2]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[13]->setLocation(playerAI[3]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[14]->setLocation(playerAI[4]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[15]->setLocation(playerAI[5]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[16]->setLocation(playerAI[6]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[17]->setLocation(playerAI[7]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[18]->setLocation(playerAI[8]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[19]->setLocation(playerAI[9]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[20]->setLocation(goal[0]->getLocation()+glm::vec3(0,-0.0,0));
membres3_[21]->setLocation(goal[1]->getLocation()+glm::vec3(0,-0.0,0));

membres3_[0]->setRotation(player[0]->getRot());
membres3_[1]->setRotation(player[1]->getRot());
membres3_[2]->setRotation(player[2]->getRot());
membres3_[3]->setRotation(player[3]->getRot());
membres3_[4]->setRotation(player[4]->getRot());
membres3_[5]->setRotation(player[5]->getRot());
membres3_[6]->setRotation(player[6]->getRot());
membres3_[7]->setRotation(player[7]->getRot());
membres3_[8]->setRotation(player[8]->getRot());
membres3_[9]->setRotation(player[9]->getRot());

membres3_[10]->setRotation(playerAI[0]->getRot());
membres3_[11]->setRotation(playerAI[1]->getRot());
membres3_[12]->setRotation(playerAI[2]->getRot());
membres3_[13]->setRotation(playerAI[3]->getRot());
membres3_[14]->setRotation(playerAI[4]->getRot());
membres3_[15]->setRotation(playerAI[5]->getRot());
membres3_[16]->setRotation(playerAI[6]->getRot());
membres3_[17]->setRotation(playerAI[7]->getRot());
membres3_[18]->setRotation(playerAI[8]->getRot());
membres3_[19]->setRotation(playerAI[9]->getRot());
membres3_[20]->setRotation(goal[0]->getRot());
membres3_[21]->setRotation(goal[1]->getRot());

membres4_[0]->setLocation(player[0]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[1]->setLocation(player[1]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[2]->setLocation(player[2]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[3]->setLocation(player[3]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[4]->setLocation(player[4]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[5]->setLocation(player[5]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[6]->setLocation(player[6]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[7]->setLocation(player[7]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[8]->setLocation(player[8]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[9]->setLocation(player[9]->getLocation()+glm::vec3(0,-0.0,0));

membres4_[10]->setLocation(playerAI[0]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[11]->setLocation(playerAI[1]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[12]->setLocation(playerAI[2]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[13]->setLocation(playerAI[3]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[14]->setLocation(playerAI[4]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[15]->setLocation(playerAI[5]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[16]->setLocation(playerAI[6]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[17]->setLocation(playerAI[7]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[18]->setLocation(playerAI[8]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[19]->setLocation(playerAI[9]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[20]->setLocation(goal[0]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[21]->setLocation(goal[1]->getLocation()+glm::vec3(0,-0.0,0));

membres4_[0]->setRotation(player[0]->getRot());
membres4_[1]->setRotation(player[1]->getRot());
membres4_[2]->setRotation(player[2]->getRot());
membres4_[3]->setRotation(player[3]->getRot());
membres4_[4]->setRotation(player[4]->getRot());
membres4_[5]->setRotation(player[5]->getRot());
membres4_[6]->setRotation(player[6]->getRot());
membres4_[7]->setRotation(player[7]->getRot());
membres4_[8]->setRotation(player[8]->getRot());
membres4_[9]->setRotation(player[9]->getRot());

membres4_[10]->setRotation(playerAI[0]->getRot());
membres4_[11]->setRotation(playerAI[1]->getRot());
membres4_[12]->setRotation(playerAI[2]->getRot());
membres4_[13]->setRotation(playerAI[3]->getRot());
membres4_[14]->setRotation(playerAI[4]->getRot());
membres4_[15]->setRotation(playerAI[5]->getRot());
membres4_[16]->setRotation(playerAI[6]->getRot());
membres4_[17]->setRotation(playerAI[7]->getRot());
membres4_[18]->setRotation(playerAI[8]->getRot());
membres4_[19]->setRotation(playerAI[9]->getRot());
membres4_[20]->setRotation(goal[0]->getRot());
membres4_[21]->setRotation(goal[1]->getRot());

membres4_[0]->setLocation(player[0]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[1]->setLocation(player[1]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[2]->setLocation(player[2]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[3]->setLocation(player[3]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[4]->setLocation(player[4]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[5]->setLocation(player[5]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[6]->setLocation(player[6]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[7]->setLocation(player[7]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[8]->setLocation(player[8]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[9]->setLocation(player[9]->getLocation()+glm::vec3(0,-0.0,0));

membres4_[10]->setLocation(playerAI[0]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[11]->setLocation(playerAI[1]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[12]->setLocation(playerAI[2]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[13]->setLocation(playerAI[3]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[14]->setLocation(playerAI[4]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[15]->setLocation(playerAI[5]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[16]->setLocation(playerAI[6]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[17]->setLocation(playerAI[7]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[18]->setLocation(playerAI[8]->getLocation()+glm::vec3(0,-0.0,0));
membres4_[19]->setLocation(playerAI[9]->getLocation()+glm::vec3(0,-0.0,0));

membres5_[0]->setLocation(player[0]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[1]->setLocation(player[1]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[2]->setLocation(player[2]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[3]->setLocation(player[3]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[4]->setLocation(player[4]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[5]->setLocation(player[5]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[6]->setLocation(player[6]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[7]->setLocation(player[7]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[8]->setLocation(player[8]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[9]->setLocation(player[9]->getLocation()+glm::vec3(0,-0.0,0));

membres5_[10]->setLocation(playerAI[0]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[11]->setLocation(playerAI[1]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[12]->setLocation(playerAI[2]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[13]->setLocation(playerAI[3]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[14]->setLocation(playerAI[4]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[15]->setLocation(playerAI[5]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[16]->setLocation(playerAI[6]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[17]->setLocation(playerAI[7]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[18]->setLocation(playerAI[8]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[19]->setLocation(playerAI[9]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[20]->setLocation(goal[0]->getLocation()+glm::vec3(0,-0.0,0));
membres5_[21]->setLocation(goal[1]->getLocation()+glm::vec3(0,-0.0,0));

membres5_[0]->setRotation(player[0]->getRot());
membres5_[1]->setRotation(player[1]->getRot());
membres5_[2]->setRotation(player[2]->getRot());
membres5_[3]->setRotation(player[3]->getRot());
membres5_[4]->setRotation(player[4]->getRot());
membres5_[5]->setRotation(player[5]->getRot());
membres5_[6]->setRotation(player[6]->getRot());
membres5_[7]->setRotation(player[7]->getRot());
membres5_[8]->setRotation(player[8]->getRot());
membres5_[9]->setRotation(player[9]->getRot());

membres5_[10]->setRotation(playerAI[0]->getRot());
membres5_[11]->setRotation(playerAI[1]->getRot());
membres5_[12]->setRotation(playerAI[2]->getRot());
membres5_[13]->setRotation(playerAI[3]->getRot());
membres5_[14]->setRotation(playerAI[4]->getRot());
membres5_[15]->setRotation(playerAI[5]->getRot());
membres5_[16]->setRotation(playerAI[6]->getRot());
membres5_[17]->setRotation(playerAI[7]->getRot());
membres5_[18]->setRotation(playerAI[8]->getRot());
membres5_[19]->setRotation(playerAI[9]->getRot());
membres5_[20]->setRotation(goal[0]->getRot());
membres5_[21]->setRotation(goal[1]->getRot());


	
	

		for(int i=0;i<membres_.size();i++)
	{
	
	membres_[i]->setRotation2(0.03f);
	if(membres_[i]->getRotation3()>1.0f)
		membres_[i]->setRotation3(-1.0f);
		if(membres_[i]->getRotation3()<-1.0f)
		membres_[i]->setRotation3(1.0f);
	}
	for(int j=0;j<membres2_.size();j++)
	{
	
		membres2_[j]->setRotation4(0.03f);	
if(membres2_[j]->getRotation3()>1.0f)
		membres2_[j]->setRotation3(-1.0f);
		if(membres2_[j]->getRotation3()<-1.0f)
		membres2_[j]->setRotation3(1.0f);
	}
	for(int x=0;x<membres4_.size();x++)
	{
	
		membres4_[x]->setRotation4(0.03f);
		if(membres4_[x]->getRotation3()>1.0f)
		membres4_[x]->setRotation3(-1.0f);
		if(membres4_[x]->getRotation3()<-1.0f)
		membres4_[x]->setRotation3(1.0f);
	}
		for(int y=0;y<membres5_.size();y++)
	{
	
		membres5_[y]->setRotation2(0.03f);	

if(membres5_[y]->getRotation3()>1.0f)
		membres5_[y]->setRotation3(-1.0f);
		if(membres5_[y]->getRotation3()<-1.0f)
		membres5_[y]->setRotation3(1.0f);
	}
for(int i=0;i<player.size();i++)
player[i]->show(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
for(int i=0;i<goal.size();i++)
goal[i]->show(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
for(int i=0;i<playerAI.size();i++)
playerAI[i]->show(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
for(int i=0;i<membres_.size();i++)
membres_[i]->draw(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
for(int i=0;i<membres2_.size();i++)
membres2_[i]->draw(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
for(int i=0;i<membres3_.size();i++)
membres3_[i]->draw(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
for(int i=0;i<membres4_.size();i++)
membres4_[i]->draw(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
for(int i=0;i<membres5_.size();i++)
membres5_[i]->draw(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
stade->show(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));
ball->show(cam->getProjectionMatrix(),cam->getViewMatrix(),glm::mat4(1.0));

		char text[256];
		sprintf(text,"Allemagne %d - France %d",scoreA,scoreB);
		printText2D(text, 10, 500, 20);
		char text2[256];
		sprintf(text2,"temps: %.2f",temps);
		printText2D(text2, 10, 450, 20);
		char text3[256];
		sprintf(text3,"mitemps: %.2f",mitemps);
		printText2D(text3, 10, 400, 20);


		
glFlush();
glutSwapBuffers();
glutPostRedisplay();

}
void game::gestionSpecial(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			setup(true);
			glutPostRedisplay();
		
			break;
			case GLUT_KEY_DOWN:
				setdown(true);
					glutPostRedisplay();
				break;
					case GLUT_KEY_LEFT:
					setleft(true);
					glutPostRedisplay();
					break;
					case GLUT_KEY_RIGHT:
						setright(true);
						glutPostRedisplay();
						break;
				
			
	}

	
}

void game::gestionSpecialUp(int key, int x, int y)
{
	switch(key)
	{
		case GLUT_KEY_UP:
			setup(false);
			glutPostRedisplay();
		
			break;
			case GLUT_KEY_DOWN:
				setdown(false);
					glutPostRedisplay();
				break;
				case GLUT_KEY_LEFT:
					setleft(false);
					glutPostRedisplay();
					break;
					case GLUT_KEY_RIGHT:
						setright(false);
						glutPostRedisplay();
						break;
				
			
	}

	
}
void game::normalKeys(unsigned char key, int x, int y)
{
	switch(key)
	  {
	  	case 32:

	  		break;
	  	case 'c':
	  
		  
	  				menu++;
	  			
				  if(menu>2)
				  {
				  	menu=2;
					  }	
					  
					  if(menu==2)
					  {
					  	startgame++;
					  
					  if(startgame>15)
					  {
					  	startgame=0;
					  }
				}
				glutPostRedisplay();
				break;
				case 'v':
				if(menu==2)
				{
				
	  					for(int i=0;i<player.size();i++)
			if(player[i]->gethastheball()&& limitBalle()==false)
	  		setespace(true);
	  	}
	  			glutPostRedisplay();
	  	
	  		break;
	  }
}
void game::normalKeysUp(unsigned char key, int x, int y)
{
	switch(key)
	  {
	  	case 'v':
	  	if(menu==2)
	  	{
		  
			for(int i=0;i<player.size();i++)
				 if(player[i]->gethastheball()==false)
	  		setespace(false);
	  	}
	  		glutPostRedisplay();
	  		break;
	  }
}

bool game::getup()
{
	return up;
}
bool game::getdown()
{
	return down;
}
bool game::getright()
{
	return right;
}
bool game::getleft()
{
	return left;
}
void game::setup(bool u)
{
	up=u;
}
void game::setdown(bool u)
{
	down=u;
}
void game::setright(bool u)
{
	right=u;
}
void game::setleft(bool u)
{
	left=u;
}
void game::setespace(bool e)
 {
 	espace=e;
 }
 bool game::getespace()
  {
  	return espace;
  }
