#ifndef PLAYABLESPRITE.H
#define PLAYABLESPRITE.H
#include "Sprite.h"

namespace gamepackage {

	class PlayableSprite : public Sprite
	{
	public:
		void draw();
		void tick();
		void keyDown();
		void keyUp();
		PlayableSprite(GameFrame* gf, int x, int y, int w, int h);
		~PlayableSprite();
	protected:
		
	private:
		SDL_Texture *texture, *leftSprite, *rightSprite, *standingSprite;
	};

}

#endif
