#include "PlayableSprite.h"
#include "GameFrame.h"
#include <SDL_image.h>

namespace gamepackage {

	PlayableSprite::PlayableSprite(GameFrame* gf, int x, int y, int w, int h) :
		Sprite(gf, x, y, w, h)
	{
		leftSprite = IMG_LoadTexture(win->getRenderer(), "images/playableLeft150x163.png");
		rightSprite = IMG_LoadTexture(win->getRenderer(), "images/playableRight150x163.png");
		standingSprite = IMG_LoadTexture(win->getRenderer(),"images/playableStanding.png" );
		shownSprite = standingSprite;
		shownSprite = leftSprite;
	}

	void PlayableSprite::draw() {
		SDL_RenderCopy(win->getRenderer(), shownSprite, NULL, &rect);
		//Ska finnas en if-sats som kollar vilken figur som ska ritas ut
		//standingSprite, leftSprite eller rightSprite...
	}


	void PlayableSprite::keyDown(const SDL_Event& e) {
		if (e.key.keysym.sym == SDLK_LEFT) {
			++speed;
			rect.x -= speed;
			shownSprite = leftSprite;

		}
		else if (e.key.keysym.sym == SDLK_RIGHT) {
			++speed;
			rect.x += speed;
			shownSprite = rightSprite;
		}

	}
	void PlayableSprite::keyUp(const SDL_Event& e) {
		speed = 0;
		shownSprite = standingSprite;
	}

	PlayableSprite* PlayableSprite::getInstance(GameFrame* gf, int x, int y, int w, int h) {
		return new PlayableSprite(gf, x, y, w, h);
	}

	PlayableSprite::~PlayableSprite()
	{
		SDL_DestroyTexture(standingSprite);
		SDL_DestroyTexture(leftSprite);
		SDL_DestroyTexture(rightSprite);
		SDL_DestroyTexture(shownSprite);
	}

	void PlayableSprite::collision()
	{
		
	}


}