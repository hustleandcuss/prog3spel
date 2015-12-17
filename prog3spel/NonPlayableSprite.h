#ifndef NONPLAYABLESPRITE_H
#define NONPLAYABLESPRITE_H

#include "Sprite.h"

namespace gamepackage {

	class NonPlayableSprite :
		public Sprite
	{
	public:
		void draw();
		void tick();
		void keyDown(const SDL_Event&) {}
		void keyUp(const SDL_Event&) {}
		void collision();
		static NonPlayableSprite* getInstance(GameFrame* gf, int x, int y, int w, int h);
		~NonPlayableSprite();
	protected:
		NonPlayableSprite(GameFrame* gf, int x, int y, int w, int h);
	private:
		SDL_Texture *texture, *spriteImg;
	};

}

#endif
