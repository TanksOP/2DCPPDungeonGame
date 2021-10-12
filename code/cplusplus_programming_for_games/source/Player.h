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
		PlayerX++;
	}
	void moveLeft() {
		PlayerX--;
	}
	void moveUp() {
		PlayerY--;
	}
	void moveDown() {
		PlayerY++;
	}

private:
	int PlayerX = 0;
	int PlayerY = 0;

	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
};

