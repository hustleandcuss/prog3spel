#include "GameFrame.h"
#include "Sprite.h"
#include "PlayableSprite.h"
#include "NonPlayableSprite.h"
#include <stdexcept>
#include <iostream>

using namespace std;
using namespace gamepackage;

int main(int argc, char** arv) {
	try {

		int gfWidth = 700;
		GameFrame* gf = new GameFrame("Play a Sprite", 200, 200, gfWidth, 500);

		for(int i = 0; i < 100; i++) {
			int xcord = rand() % gfWidth;
			int ycord = rand() % 5000 + 0;
			NonPlayableSprite* s = NonPlayableSprite::getInstance(gf, xcord, -ycord, 30, 30);
		}

		gf->run();

	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}

	return 0;
}
