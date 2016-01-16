#include "GameFrame.h"
#include "Sprite.h"
#include <vector>
#include <algorithm>
#include <functional>

namespace gamepackage {
	bool condition(gamepackage::Sprite* s)
	{
		return s->isDead;
	}
	GameFrame::GameFrame(std::string tit, int x, int y, int w, int h) : width(w), height(h)
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
		//loop som går så länge runOn = true
		int tickInterval = 1000 / fps;  // 1000 ms /fps = så lång tid ska ett varv ta
		int nextTick; //när nästa tick ska komma
		int delay; //hur lång tid det ska väntas innan nästa tick

		bool runOn = true;
		while (runOn) {
			SDL_Event e;
			//while loop m. switch(eve) som väntar på event
			nextTick = SDL_GetTicks() + tickInterval;

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

			for (Sprite* s : spritesVec) {
				s->tick();
			}

			//kollar om Spritsen krockar
			SDL_RenderClear(ren);
			for (Sprite* s : spritesVec) {
				for (Sprite* s2 : spritesVec) {
					if (SDL_HasIntersection(&s->getPos(), &s2->getPos()) && s != s2) {
						s->collision();
						s2->collision();
					}
				}
			}
			//rensa och rita om spritesen
			for (Sprite* s : spritesVec) {
				s->draw();
			}
			SDL_RenderPresent(ren);

			delay = nextTick - SDL_GetTicks(); //tar fram tiden som ska väntas om det ska väntas
			if (delay > 0) {
				SDL_Delay(delay);
			}
			remove_if(spritesVec.begin(), spritesVec.end(), condition);
		} //while runOn
	} //run()

	void GameFrame::add(Sprite * spr)
	{
		spritesVec.push_back(spr);
	}

	void GameFrame::kill(Sprite* s) {
		spritesVec.erase(std::remove(spritesVec.begin(), spritesVec.end(), s));
	}

	SDL_Window * GameFrame::getWindow() const
	{
		return win;
	}

	int GameFrame::getWidth() const
	{
		return width;
	}

	int GameFrame::getHeigth() const
	{
		return height;
	}


	void GameFrame::setFps(int newFps)
	{
		fps = newFps;
	}


}
