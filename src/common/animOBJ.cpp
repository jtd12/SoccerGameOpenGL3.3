#include"animOBJ.h"


	
bool animOBJ::loadAnimation(std::vector<unsigned int>& frames, std::string filename, unsigned int num)
{
	char tmp[200];
//	std::vector<collisionplane> collP;
	for(int i=0;i<=num;i++)
	{
		if(i<10)
			sprintf(tmp,"_00000%d",i);
		else if(i<100)
			sprintf(tmp,"_0000%d",i);
		else if(i<1000)
				sprintf(tmp,"_000%d",i);
		else if(i<10000)
				sprintf(tmp,"_00%d",i);
		else if(i<100000)
				sprintf(tmp,"_0%d",i);
		else if(i<1000000)
				sprintf(tmp,"_%d",i);
	
		std::string tmp2(filename+tmp);
		tmp2+=".obj";
		unsigned int id=obj.loadOBJ(tmp2,vertices,uvs,normals);
		frames.push_back(id);		
	 } 
}


