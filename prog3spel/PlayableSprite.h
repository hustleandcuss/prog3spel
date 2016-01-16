//Spelmotor av Simson Schweitz och Olivia Lenner�
//Vi aspirerar p� betyg: C

#ifndef PLAYABLESPRITE_H
#define PLAYABLESPRITE_H
#include "Sprite.h"

namespace gamepackage {

	class PlayableSprite : public Sprite
	{
	public:
		void draw();
		void keyDown(const SDL_Event&);
		void keyUp(const SDL_Event&);
		static PlayableSprite* getInstance(GameFrame* gf, int x, int y, int w, int h);
		~PlayableSprite();
		int speed;
		void collision();

	protected:
		PlayableSprite(GameFrame* gf, int x, int y, int w, int h);
	private:
		SDL_Texture *texture, *leftSprite, *rightSprite, *standingSprite, *shownSprite;
	};

}

#endif
