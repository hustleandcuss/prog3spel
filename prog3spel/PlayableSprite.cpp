#include "PlayableSprite.h"
#include "GameFrame.h"
#include <SDL_image.h>

namespace gamepackage {

	PlayableSprite::PlayableSprite(GameFrame* gf, int x, int y, int w, int h) :// : win(gf), rect{ x, y, w, h }
		Sprite(gf, x, y, w, h)
	{
		leftSprite = IMG_LoadTexture(win->getRenderer(), "imgURL");
		rightSprite = IMG_LoadTexture(win->getRenderer(), "imgURL");
		standingSprite = IMG_LoadTexture(win->getRenderer(), "imgURL");
	}


	PlayableSprite::~PlayableSprite()
	{
	}

}