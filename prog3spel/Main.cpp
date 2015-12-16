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
		GameFrame* gf = new GameFrame("Play a Sprite", 200, 200, 500, 300);
		Sprite* s1 = new PlayableSprite(gf, 100, 100, 30, 15);
		gf->run();

	}
	catch (runtime_error& e) {
		cerr << e.what() << endl;
	}

	return 0;
}
