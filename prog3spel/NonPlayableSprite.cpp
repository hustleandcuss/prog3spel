#include "NonPlayableSprite.h"
#include "Sprite.h"
#include "GameFrame.h"
#include <SDL_image.h>

namespace gamepackage {

	NonPlayableSprite::NonPlayableSprite(GameFrame* gf, int x, int y, int w, int h) :
		Sprite(gf, x, y, w, h)
	{
		spriteImg = IMG_LoadTexture(win->getRenderer(), "imgURL");
	}

	void NonPlayableSprite::draw() {

	}

	void NonPlayableSprite::tick() {

	}

	void NonPlayableSprite::keyDown() {

	}

	void NonPlayableSprite::keyUp() {

	}


	NonPlayableSprite::~NonPlayableSprite()
	{
	}

}