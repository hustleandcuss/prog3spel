#include "GameFrame.h"
#include "Sprite.h"
#include "PlayableSprite.h"
#include "NonPlayableSprite.h"
//Spelmotor av Simson Schweitz och Olivia Lennerö
//Vi aspirerar på betyg: C

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

		int xcord = rand() % gfWidth;
		int ycord = rand() % 5000 + 0;

		gf->installShortCmd(quit, SDL_SCANCODE_ESCAPE);
	
		for(int i = 0; i < 100; i++) {
			int xcord = rand() % gfWidth;
			int ycord = rand() % 5000 + 0;
			NonPlayableSprite* s = NonPlayableSprite::getInstance(gf, xcord, -ycord, 60, 60);
		}
		
		gf->run();

	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}

	return 0;
}
