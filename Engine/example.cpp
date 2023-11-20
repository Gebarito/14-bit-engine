#include <iostream>
#include <random>
#include "GameEngine.h"

GameObject ball;
GameObject Player1;
GameObject Player2;

int Player_Speed = 500;
int ball_speed = 100;

void setup() {
	ball.x = WIN_WIDTH / 2;
	ball.y = WIN_HEIGHT / 2;
	ball.w = 15;
	ball.h = 15;
	ball.haveCollider = TRUE;

	Player1.w = 20;
	Player1.h = 100;
	Player1.x = 0 + Player1.w;
	Player1.y = 10;
	Player1.haveCollider = TRUE;

	Player2.w = 20;
	Player2.h = 100;
	Player2.x = WIN_WIDTH - Player2.w;
	Player2.y = 10;
	Player2.haveCollider = TRUE;

}

void update(float delta_time) {
	ball.x += ball_speed * delta_time;

	Player1.y += Player_Speed * KeyDown("VERTICAL1") *delta_time;
	
	//IA
	Player2.y = rand() % WIN_HEIGHT;
	
	if (onCollision(ball, Player1) || onCollision(ball, Player2)) {
		ball_speed *= -1;
	}

	if (ball.x < 0) {
		std::cout << "pontuou" << std::endl;
		ball.x = WIN_WIDTH/2;

	}
}

void draw(SDL_Renderer* renderer) {
	DrawBackGround(renderer, 0, 0, 0, 255);
	DrawRect(ball, renderer, 255, 255, 255, 255);
	DrawRect(Player1, renderer, 255, 255, 255, 255);
	DrawRect(Player2, renderer, 255, 255, 255, 255);
}