#include "GameFrame.h"
#include "Sprite.h"
#include "PlayableSprite.h"
#include "NonPlayableSprite.h"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace gamepackage;


void quit() {
	exit(0);
}

int main(int argc, char** arv) {
	try {

		int gfWidth = 700;
		GameFrame* gf = new GameFrame("Play a Sprite", 200, 200, gfWidth, 500);
		PlayableSprite* s1 = PlayableSprite::getInstance(gf, 100, 400, 100, 100);
	//	PlayableSprite* s4 = PlayableSprite::getInstance(gf, 200, 400, 100, 100);

		int xcord = rand() % gfWidth;
		int ycord = rand() % 5000 + 0;
		/*
		NonPlayableSprite* s = NonPlayableSprite::getInstance(gf, 10, 5, 50, 50);
		NonPlayableSprite* s2 = NonPlayableSprite::getInstance(gf, 500, 5, 60, 60);
		NonPlayableSprite* s5 = NonPlayableSprite::getInstance(gf, 300, -50, 60, 60);
		NonPlayableSprite* s6 = NonPlayableSprite::getInstance(gf, 150, -30, 60, 60);
		NonPlayableSprite* s7 = NonPlayableSprite::getInstance(gf, 50, -10, 60, 60);
		NonPlayableSprite* s8 = NonPlayableSprite::getInstance(gf, 600, 0, 60, 60);
		*/
	//	gf->kill(s);

	//	cout << gf->getSpritesVec().size();

		gf->installShortCmd(quit, SDL_SCANCODE_ESCAPE);
	
		for(int i = 0; i < 100; i++) {
			int xcord = rand() % gfWidth;
			int ycord = rand() % 5000 + 0;
			NonPlayableSprite* s = NonPlayableSprite::getInstance(gf, xcord, -ycord, 60, 60);
		}
		
		gf->run();
	//	SDL_Delay(2000);
	//	gf->kill(s);

	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}

	return 0;
}
