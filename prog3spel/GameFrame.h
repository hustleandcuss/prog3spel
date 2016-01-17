//Spelmotor av Simson Schweitz och Olivia Lennerö
//Vi aspirerar på betyg: C

#ifndef GameFrame_h
#define  GameFrame_h
#include <vector>
#include "SDL.h"
#include <string>
#include <map>
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
		void setFps(int newFps);
		std::vector<Sprite*>::iterator GameFrame::kill(std::vector<Sprite*>::iterator);
		std::vector<Sprite*>& getSpritesVec();
		void installShortCmd(void(*f)(), SDL_Scancode);
		int getWidth() const;
		int getHeight() const;
		void deleteSprite(Sprite*);
	private:
		std::vector<Sprite*> spritesVec;
		std::map<SDL_Scancode, void(*)()> shortCommands;
		int fps = 60;
		int varv = 0; //ska gå 60 varv per sekund
		SDL_Window* win;
		SDL_Renderer* ren;
		int width, height;


	};
}
#endif
