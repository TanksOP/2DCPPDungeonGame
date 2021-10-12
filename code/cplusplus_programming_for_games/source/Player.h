#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Player
{
public:
	Player(SDL_Renderer*);

	void init();
	void render();
	void update();
	void clean();

	void moveRight(){
		PlayerX += PlayerSpeed;
	}
	void moveLeft() {
		PlayerX -= PlayerSpeed;
	}
	void moveUp() {
		PlayerY -= PlayerSpeed;
	}
	void moveDown() {
		PlayerY += PlayerSpeed;
	}

private:
	int PlayerX = 0;
	int PlayerY = 0;
	int PlayerSpeed = 5;

	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
};

