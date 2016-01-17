//Spelmotor av Simson Schweitz och Olivia Lennerö
//Vi aspirerar på betyg: C

#include "GameFrame.h"
#include "Sprite.h"
#include <vector>
#include <algorithm>
#include <SDL_image.h>

namespace gamepackage {

	GameFrame::GameFrame(std::string tit, int x, int y, int w, int h): height(h), width(w)
	{
		win = SDL_CreateWindow(tit.c_str(), x, y, w, h, 0);
		ren = SDL_CreateRenderer(win, -1, 0);
	}

	GameFrame::~GameFrame()
	{
		for (auto it = spritesVec.begin(); it != spritesVec.end(); it++) {
			delete (*it);
		}

		SDL_DestroyRenderer(ren);
		SDL_DestroyWindow(win);
	}

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
		
		//rita uta spritsen etc.

		for (Sprite* s : spritesVec) {
			s->draw();
		}
		
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

			//rita om spritesen
			SDL_Texture* tex = IMG_LoadTexture(ren, "images/background.jpg");
			SDL_RenderCopy(ren, tex, NULL, NULL);

			for (Sprite* s : spritesVec) {
				s->draw();
			}

			SDL_RenderPresent(ren);

			//tar bort alla sprites som är isDead
			/* fungerar ej
			for (auto it = spritesVec.begin(); it != spritesVec.end(); ++it) {
				if ((*it)->isDead) {
					auto tmp = it;
					++tmp;
					delete *it;
					it = tmp;
				}
			}
			*/
			/* fungerar ej
			for (auto it = spritesVec.begin(); it != spritesVec.end(); it++) {
				if ((*it)->isDead) {
					delete (*it);
				}
			}*/
			
		/*	for (int i = 0; i < spritesVec.size(); i++)
			{
				if(spritesVec[i]->isDead)
				delete spritesVec[i];
			}*/

			/*for (std::vector<Sprite*>::iterator iter = spritesVec.begin(); iter != spritesVec.end();) {
				if ((*iter)->isDead) {
					iter = kill(iter);
				}
				else {
					iter++;
				}

			}*/
			
			delay = nextTick - SDL_GetTicks(); //tar fram tiden som ska väntas om det ska väntas
			if (delay > 0) {
				SDL_Delay(delay);
			}
		} //while runOn
	} //run()

	void GameFrame::add(Sprite * spr)
	{
		spritesVec.push_back(spr);
	}

	std::vector<Sprite*>::iterator GameFrame::kill(std::vector<Sprite*>::iterator iter) {
		iter = spritesVec.erase(iter);
		return iter;
	}
	

	void GameFrame::setFps(int newFps)
	{
		fps = newFps;
	}

	int GameFrame::getWidth() const
	{
		return width;
	}

	int GameFrame::getHeight() const
	{
		return height;
	}
	void GameFrame::deleteSprite(Sprite * s)
	{
		delete s;
	}
}
