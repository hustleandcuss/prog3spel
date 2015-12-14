#include "PlayableSprite.h"
#include "GameFrame.h"
#include <SDL_image.h>

namespace gamepackage {

	PlayableSprite::PlayableSprite(GameFrame* gf, int x, int y, int w, int h) :
		Sprite(gf, x, y, w, h)
	{
		leftSprite = IMG_LoadTexture(win->getRenderer(), "images/square.jpg");
		rightSprite = IMG_LoadTexture(win->getRenderer(), "images/square.jpg");
		standingSprite = IMG_LoadTexture(win->getRenderer(), "images/square.jpg");
	}

	void PlayableSprite::draw() {
		SDL_RenderCopy(win->getRenderer(), standingSprite, NULL, &rect);
		//Ska finnas en if-sats som kollar vilken figur som ska ritas ut
		//standingSprite, leftSprite eller rightSprite...
	}

	void PlayableSprite::keyDown(const SDL_Event& e) {
		if (e.key.keysym.sym == SDLK_LEFT) {
		//	x--;
		}
		else if (e.key.keysym.sym == SDLK_RIGHT) {
			//x++;
		}
	}

	void PlayableSprite::keyUp(const SDL_Event& e) {
		//standingSprite
	}

	PlayableSprite::~PlayableSprite()
	{
	}

}