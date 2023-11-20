#include "GameEngine.h"
#include <SDL.h>

void QuitGame() {
	exit(1);
	//SDL_Quit();
}

int onCollision(GameObject obj1, GameObject obj2) { 
	if (obj1.haveCollider == 0 || obj2.haveCollider == 0) {
		std::cout << "Um dos objetos nao possui colisores" << std::endl;
		return false;
	}

	if (
		obj1.x < obj2.x + obj2.w &&
		obj1.x + obj1.w > obj2.x &&
		obj1.y < obj2.y + obj2.h &&
		obj1.y + obj1.h > obj2.y
	) return true;
	
	return false;
}

int KeyDown(const char* KEY) {
	if (KEY == "VERTICAL1")
		return Player1Keys();

	return 0;
}

int Player1Keys() {
	SDL_Event e;
	SDL_PollEvent(&e);

	switch (e.type) {
		case SDL_KEYDOWN:
			if (e.key.keysym.sym == SDLK_w)
				return -1;
			else if (e.key.keysym.sym == SDLK_s)
				return 1;
	}

	return 0;
}


void DrawBackGround(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_SetRenderDrawColor(renderer, r, g, b, a);
	SDL_RenderClear(renderer);
}


void DrawRect(GameObject obj, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a) {
	SDL_Rect rect = { (int)obj.x, (int)obj.y, (int)obj.w, (int)obj.h };

	SDL_SetRenderDrawColor(renderer, r,g,b,a);
	SDL_RenderFillRect(renderer, &rect);
	SDL_RenderPresent(renderer);
}