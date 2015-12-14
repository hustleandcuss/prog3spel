#ifndef NONPLAYABLESPRITE.H
#define NONPLAYABLESPRITE.H
#include "Sprite.h"

namespace gamepackage {

	class NonPlayableSprite :
		public Sprite
	{
	public:
		void draw();
		void tick() {}
		void keyDown(const SDL_Event&) {}
		void keyUp(const SDL_Event&) {}
		NonPlayableSprite(GameFrame* gf, int x, int y, int w, int h);
		~NonPlayableSprite();
	protected:

	private:
		SDL_Texture *texture, *spriteImg;
	};

}

#endif
