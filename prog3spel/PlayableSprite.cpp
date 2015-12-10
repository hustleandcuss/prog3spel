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

	void PlayableSprite::draw() {
		SDL_RenderCopy(win->getRenderer(), standingSprite, NULL, &rect);
		//Ska finnas en if-sats som kollar vilken figur som ska ritas ut
		//standingSprite, leftSprite eller rightSprite...
	}

	void PlayableSprite::tick() {

	}

	void PlayableSprite::keyDown() {
		//Kolla om det är höger eller vänster pil och agera
	}

	void PlayableSprite::keyUp() {
		//standingSprite
	}

	PlayableSprite::~PlayableSprite()
	{
	}

}