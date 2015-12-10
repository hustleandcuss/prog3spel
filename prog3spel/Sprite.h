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
		virtual void tick() = 0;
		virtual void keyDown() = 0;
		virtual void keyUp() = 0;
		virtual ~Sprite();
	protected:
		Sprite(GameFrame* gf, int x, int y, int w, int h);
		SDL_Rect rect;
		GameFrame* win;
	private:
		Sprite(const Sprite&) = delete;
		const Sprite& operator=(const Sprite&) = delete;
		
	};

}

#endif

