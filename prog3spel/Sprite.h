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
		virtual void tick() {}
		virtual void keyDown(const SDL_Event&) {}
		virtual void keyUp(const SDL_Event&) {}
		virtual void collision() {}
		bool isDead = false;
		virtual ~Sprite();
		SDL_Rect getPos();
		bool isDead = false;
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

