#include "GameFrame.h"
#include "Sprite.h"
#include "NonPlayableSprite.h"

namespace gamepackage {

	GameFrame::GameFrame(std::string tit, int x, int y, int w, int h)
	{
		win = SDL_CreateWindow(tit.c_str(), x, y, w, h, 0);
		ren = SDL_CreateRenderer(win, -1, 0);

	}

	GameFrame::~GameFrame()
	{
		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
	}

	SDL_Renderer * GameFrame::getRenderer()
	{
		return ren;
	}

	void GameFrame::run()
	{
		//rensa bilden
		SDL_RenderClear(ren);
		//rita uta spritsen etc.
		for (Sprite* s : spritesVec) {
			s->draw();
		}

		const int TIMEPERTICK = 50;
		//loop som går så länge runOn = true
		bool runOn = true;
		while (runOn) {
			Uint32 nextTick = SDL_GetTicks() + TIMEPERTICK;
			SDL_Event e;
			//while loop m. switch(eve) som väntar på event
			while (SDL_PollEvent(&e)) {
				switch (e.type) {
				case SDL_QUIT: 
					runOn = false;
					break;
				case SDL_KEYDOWN:
					for (Sprite* s : spritesVec) {
						s->keyDown(e);
					}
					break;
				case SDL_KEYUP:
					for (Sprite* s : spritesVec) {
						s->keyUp(e);
					}
					break;
				} //switch
			} //while event

			//rensa och rita om spritesen
			SDL_RenderClear(ren);
			for (Sprite* s : spritesVec) {
				s->tick();
				s->draw();
			}
			SDL_RenderPresent(ren);

			//kolla om NonPlayableSprites krockar med PlayableSprite
			/*
			for (Sprite* s : spritesVec) {
				for (Sprite* other : spritesVec) {
					if (other->getPos().x >= s->getPos.x && other->getPos().x <= s->getPos.x + s->getPos().w &&
						other->getPos().y >= s->getPos().y && other->getPos().y <= s->getPos().y + s->getPos().h) {
						if (typeid(NonPlayableSprite) == typeid(s) && other != s) {
							spritesVec.erase(s);
						}
					}
				}
			}
			*/
			/*
			std::vector <Sprite*>::iterator iter;
			for (iter = spritesVec.begin(); iter != spritesVec.end();) {
				for (Sprite* other : spritesVec) {
					if (other->getPos().x >= (*iter)->getPos().x && other->getPos().x <= (*iter)->getPos().x + (*iter)->getPos().w &&
						other->getPos().y >= (*iter)->getPos().y && other->getPos().y <= (*iter)->getPos().y + (*iter)->getPos().h) {
						if (other != (*iter)) {
							(*iter)->collision();
						//	iter = spritesVec.erase(iter);
						}
					}
				}
				iter++;
			}*/
			/*
			for (Sprite* s : spritesVec) {
				s->collision();

			}*/

			std::vector <Sprite*>::iterator iter;
			for (iter = spritesVec.begin(); iter != spritesVec.end();) {
				iter = kill(iter);
				iter++;
			}

			if (!SDL_TICKS_PASSED(SDL_GetTicks(), nextTick)) {
				SDL_Delay(nextTick - SDL_GetTicks());
			}

		} //while runOn
	} //run()

	void GameFrame::add(Sprite * spr)
	{
		spritesVec.push_back(spr);
	}

	std::vector <Sprite*>::iterator GameFrame::kill(std::vector <Sprite*>::iterator iter) {
		std::vector <Sprite*>::iterator i = spritesVec.erase(iter);

		return i;
	}

}
