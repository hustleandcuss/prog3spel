#include "NonPlayableSprite.h"
#include "Sprite.h"
#include "GameFrame.h"
#include <SDL_image.h>

namespace gamepackage {

	NonPlayableSprite* NonPlayableSprite::getInstance(GameFrame* gf, int x, int y, int w, int h) {
		return new NonPlayableSprite(gf, x, y, w, h);
	}

	NonPlayableSprite::NonPlayableSprite(GameFrame* gf, int x, int y, int w, int h) :
		Sprite(gf, x, y, w, h)
	{
		spriteImg = IMG_LoadTexture(win->getRenderer(), "images/squareOr.png");
	}

	void NonPlayableSprite::draw() {
		SDL_RenderCopy(win->getRenderer(), spriteImg, NULL, &rect);

	}

	void NonPlayableSprite::tick() {
		rect.y++;
	}

	NonPlayableSprite::~NonPlayableSprite()
	{
	}

}