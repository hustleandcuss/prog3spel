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
		std::vector <Sprite*>::iterator kill(std::vector <Sprite*>::iterator iter);
	private:
		friend class Sprite;
		friend class NonPlayableSprite;
		std::vector<Sprite*> spritesVec;
		SDL_Window* win;
		SDL_Renderer* ren;


	};
}
#endif
