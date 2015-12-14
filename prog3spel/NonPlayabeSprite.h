#ifndef NONPLAYABLESPRITE.H
#define NONPLAYABLESPRITE.H
#include "Sprite.h"

namespace gamepackage {

	class NonPlayabeSprite :
		public Sprite
	{
	public:
		NonPlayabeSprite(GameFrame* gf, int x, int y, int w, int h);
		~NonPlayabeSprite();
	};

}

#endif
