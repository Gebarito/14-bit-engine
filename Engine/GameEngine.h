#ifndef Game_Engine
#define Game_Engine

#include <iostream>
#include <SDL.h>
#include <stdlib.h>
//#include <SDL_IMAGE.h>

//CONSTANTES
#define FALSE 0
#define TRUE 1

#define WIN_WIDTH 680
#define WIN_HEIGHT 480
#define GAME_NAME "Game Name"

#define FPS 30
#define FRAME_TARGET_TIME (1000/FPS)

#define KEY_UP "SDLK_UP"
#define KEY_DOWN "SDLK_DOWN"

#define KEY_W SDLK_w
#define KEY_S SDLK_s

typedef struct {
	double x, y, z;
	double w, h;
	int haveCollider;
	char* name;
	SDL_Rect obj_rect;
	SDL_Renderer* renderer;
}GameObject;

void QuitGame();
int onCollision(GameObject obj1, GameObject obj2);

void DebugMessage(const char* message);

int KeyDown(const char* KEY);
int Player1Keys();
int Player2Keys();


void DrawRect(GameObject obj, SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
void DrawBackGround(SDL_Renderer* renderer, Uint8 r, Uint8 g, Uint8 b, Uint8 a);
#endif // !Game_Engine
