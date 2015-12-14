#ifndef GameFrame_h
#define  GameFrame_h
#include "vector"
#include "SDL.h"
#include "string"
namespace gamepackage {

	class Sprite;

	class GameFrame
	{
	public:
		GameFrame(std::string tit, int x, int y, int w, int h);
		~GameFrame();
		SDL_Renderer* getRenderer();
		void run();
		void add(Sprite* spr);
	private:
		friend class Sprite;
		std::vector<Sprite*> spritesVec;
		SDL_Window* win;
		SDL_Renderer* ren;


	};
}
#endif
