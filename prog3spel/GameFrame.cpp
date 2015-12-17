#include "GameFrame.h"
#include "Sprite.h"


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
		//loop som g�r s� l�nge runOn = true
		int tickInterval = 1000 / fps;  // 1000 ms /fps = s� l�ng tid ska ett varv ta
		int nextTick; //n�r n�sta tick ska komma
		int delay; //hur l�ng tid det ska v�ntas innan n�sta tick

		bool runOn = true;
		while (runOn) {
			SDL_Event e;
			//while loop m. switch(eve) som v�ntar p� event
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

			SDL_RenderClear(ren);
			for (Sprite* s : spritesVec) {
				for (Sprite* s2 : spritesVec) {
					if (SDL_HasIntersection(&s->getPos(), &s2->getPos())) {
						s->collision();
						s->collision();
					}
				}
			}

			//rensa och rita om spritesen
			for (Sprite* s : spritesVec) {
				s->draw();
			}
			SDL_RenderPresent(ren);
			
			delay = nextTick - SDL_GetTicks(); //tar fram tiden som ska v�ntas om det ska v�ntas
			if (delay > 0) {
				SDL_Delay(delay);
			}
		} //while runOn
	} //run()

	void GameFrame::add(Sprite * spr)
	{
		spritesVec.push_back(spr);
	}

	void GameFrame::setFps(int newFps)
	{
		fps = newFps;
	}

}
