//Spelmotor av Simson Schweitz och Olivia Lennerö
//Vi aspirerar på betyg: C

#include "GameFrame.h"
#include "Sprite.h"
#include <vector>
#include <algorithm>
#include <SDL_image.h>

namespace gamepackage {

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

	/*
	bool condition(g*/

	SDL_Renderer * GameFrame::getRenderer()
	{
		return ren;
	}

	void GameFrame::installShortCmd(void(*f)(), SDL_Scancode sc) {
		shortCommands[sc] = f;
	}

	void GameFrame::run()
	{	
		//rensa bilden
		SDL_RenderClear(ren);
		
		int tickInterval = 1000 / fps;  // 1000 ms /fps = så lång tid ska ett varv ta
		int nextTick; //när nästa tick ska komma
		int delay; //hur lång tid det ska väntas innan nästa tick

		//loop som går så länge runOn = true
		bool runOn = true;
		while (runOn) {
			SDL_Event e;
			nextTick = SDL_GetTicks() + tickInterval;

			//while loop m. switch(eve) som väntar på event
			while (SDL_PollEvent(&e)) {
				SDL_Scancode sc = SDL_GetScancodeFromKey(e.key.keysym.sym);
				switch (e.type) {
				case SDL_QUIT: 
					runOn = false;
					break;
				case SDL_KEYDOWN:
					if (shortCommands.count(sc)) {
						shortCommands[sc]();
					}
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
					}
				}
			}

			//rita ut spritesen etc.
			SDL_Texture* tex = IMG_LoadTexture(ren, "images/background.jpg");
			SDL_RenderCopy(ren, tex, NULL, NULL);

			//tar bort alla sprites som är isDead
			//och ritar ut spritsen
			for (std::vector<Sprite*>::iterator iter = spritesVec.begin(); iter != spritesVec.end();) {
				if ((*iter)->isDead) {
					iter = kill(iter);
				}
				else {
					(*iter)->draw();
					iter++;
				}

			}

			SDL_RenderPresent(ren);
			
			delay = nextTick - SDL_GetTicks(); //tar fram tiden som ska väntas om det ska väntas
			if (delay > 0) {
				SDL_Delay(delay);
			}
		} //while runOn
	} //run()


	//lägg till Sprite
	void GameFrame::add(Sprite * spr)
	{
		spritesVec.push_back(spr);
	}

	//ta bort Sprite
	std::vector<Sprite*>::iterator GameFrame::kill(std::vector<Sprite*>::iterator iter) {
		delete &iter;
		iter = spritesVec.erase(iter);
		return iter;
	}

	std::vector<Sprite*> GameFrame::getSpritesVec() {
		return spritesVec;
	}

	int GameFrame::getWidth() const {
		return width;
	}

	int GameFrame::getHeight() const {
		return height;
	}

	void GameFrame::setFps(int newFps)
	{
		fps = newFps;
	}
}
