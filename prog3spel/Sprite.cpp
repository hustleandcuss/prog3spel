#include "Sprite.h"
#include "GameFrame.h"

namespace gamepackage {

	Sprite::Sprite(GameFrame* gf, int x, int y, int w, int h) : win(gf), rect{ x, y, w, h }
	{
		gf->add(this);
	}


	Sprite::~Sprite()
	{
		delete &rect; //wtf delete behöver pointers, behöver man ta bort 
	}

	SDL_Rect Sprite::getPos()
	{
		return rect;
	}
}


