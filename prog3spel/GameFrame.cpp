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
		//loop som går så länge runOn = true
		bool runOn = true;
		while (runOn) {
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
				s->draw();
			}
			SDL_RenderPresent(ren);

		} //while runOn
	} //run()

	void GameFrame::add(Sprite * spr)
	{
		spritesVec.push_back(spr);
	}

}
