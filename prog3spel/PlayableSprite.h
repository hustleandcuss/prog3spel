#ifndef PLAYABLESPRITE.H
#define PLAYABLESPRITE.H
#include "Sprite.h"

namespace gamepackage {

	class PlayableSprite : public Sprite
	{
	public:
		PlayableSprite(GameFrame* gf, int x, int y, int w, int h);
		~PlayableSprite();
	protected:
		
	private:
		SDL_Texture *texture, *leftSprite, *rightSprite, *standingSprite;
	};

}

#endif
