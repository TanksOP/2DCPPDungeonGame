#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Player
{
public:
	Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight);

	void init();
	void render();
	void update();
	void clean();

	void moveRight(){
		portion.x += playerSpeed;
		if (portion.x + portion.w >= windowWidth) {
			portion.x = windowWidth - portion.w;
		}
	}
	void moveLeft() {
		portion.x -= playerSpeed;
		if (portion.x < 0) {
			portion.x = 0;
		}
	}
	void moveUp() {
		portion.y -= playerSpeed;
		if (portion.y < 0) {
			portion.y = 0;
		}
	}
	void moveDown() {
		portion.y += playerSpeed;
		if (portion.y + portion.h >= windowHeight) {
			portion.y = windowHeight - portion.h;
		}
	}

private:
	
	int playerSpeed = 5;

	int windowWidth = 0;
	int windowHeight = 0;

	SDL_Rect portion;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;
};

