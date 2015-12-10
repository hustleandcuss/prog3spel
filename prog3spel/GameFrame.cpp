#include "GameFrame.h"

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
		//cler ren
		//draw
		//while loop
		//while loop m. switch(eve)
		//osv
	}

	void GameFrame::add(Sprite * spr)
	{
		spritesVec.push_back(spr);
	}

}
