#ifndef SPRITE_H
#define SPRITE_H
#include <SDL.h>

namespace gamepackage {

	//Säger/lovar att det kommer finnas en klass GameFrame.
	class GameFrame;

	class Sprite
	{
	public:
		virtual void draw() = 0;
		virtual ~Sprite();
	protected:
		Sprite(GameFrame* gf, int x, int y, int w, int h);
	//	SDL_Rect rect;
	//	GameFrame* frame;
	private:
		Sprite(const Sprite&) = delete;
		const Sprite& opetator=(const Sprite&) = delete;
		
	};

}

#endif

