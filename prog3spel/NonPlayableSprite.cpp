#include "NonPlayableSprite.h"
#include "PlayableSprite.h"
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
		spriteLeft = IMG_LoadTexture(win->getRenderer(), "images/fallingLeft.png");
		spriteRight = IMG_LoadTexture(win->getRenderer(), "images/fallingRight.png");
	}

	void NonPlayableSprite::draw() {
		if (tickCount % 10 == 0) {
			switchImg = !switchImg;
		}

		if (switchImg) {
			SDL_RenderCopy(win->getRenderer(), spriteRight, NULL, &rect);
		}
		else {
			SDL_RenderCopy(win->getRenderer(), spriteLeft, NULL, &rect);
		}
	}

	void NonPlayableSprite::tick() {
		rect.y++;
		tickCount++;
	}

	
	void NonPlayableSprite::collision() {
		//DEt som händer nör de krockar
	}

	NonPlayableSprite::~NonPlayableSprite()
	{
	}

}