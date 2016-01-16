//Spelmotor av Simson Schweitz och Olivia Lennerö
//Vi aspirerar på betyg: C

#include "PlayableSprite.h"
#include "GameFrame.h"
#include <SDL_image.h>

namespace gamepackage {

	PlayableSprite::PlayableSprite(GameFrame* gf, int x, int y, int w, int h) :
		Sprite(gf, x, y, w, h)
	{
		leftSprite = IMG_LoadTexture(win->getRenderer(), "images/playableLeft.gif");
		rightSprite = IMG_LoadTexture(win->getRenderer(), "images/playableRight.gif");
		standingSprite = IMG_LoadTexture(win->getRenderer(),"images/playableStanding.gif" );
		shownSprite = leftSprite;
	}

	void PlayableSprite::draw() {
		SDL_RenderCopy(win->getRenderer(), shownSprite, NULL, &rect);
	}


	void PlayableSprite::keyDown(const SDL_Event& e) {
		if (e.key.keysym.sym == SDLK_LEFT) {
			
			if (rect.x >= 0) {
				++speed;
				rect.x -= speed;
				shownSprite = leftSprite;
			}

		}
		else if (e.key.keysym.sym == SDLK_RIGHT) {
			if (rect.x <= win->getWidth()) {
				++speed;
				rect.x += speed;
				shownSprite = rightSprite;
			}
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