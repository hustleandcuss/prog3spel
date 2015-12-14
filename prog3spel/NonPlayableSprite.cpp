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
		SDL_RenderCopy(win->getRenderer(), spriteImg, NULL, &rect);

	}

	void NonPlayableSprite::tick() {
		&rect->y - 1;
	}

	void NonPlayableSprite::keyDown(const SDL_Event& e) {

	}

	void NonPlayableSprite::keyUp(const SDL_Event& e) {

	}


	NonPlayableSprite::~NonPlayableSprite()
	{
	}

}