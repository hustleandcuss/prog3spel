//Spelmotor av Simson Schweitz och Olivia Lenner�
//Vi aspirerar p� betyg: C

#include "Sprite.h"
#include "GameFrame.h"

namespace gamepackage {

	Sprite::Sprite(GameFrame* gf, int x, int y, int w, int h) : win(gf), rect{ x, y, w, h }
	{
		gf->add(this);
	}


	Sprite::~Sprite()
	{
		delete &rect; //wtf delete beh�ver pointers, beh�ver man ta bort 
	}

	SDL_Rect Sprite::getPos()
	{
		return rect;
	}
}

