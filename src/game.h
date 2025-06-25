#ifndef DEF_GAME_H
#define DEF_GAME_H
#include"together.hpp"

class game
{
	public:
		game();
		~game();
		void initGL();
		void draw();
		void update();
		void gestionSpecial(int key, int x, int y);
		void gestionSpecialUp(int key, int x, int y);
		void normalKeys(unsigned char key, int x, int y);
		void normalKeysUp(unsigned char key, int x, int y);
		
		private:
			together* p;
	
};
#endif

