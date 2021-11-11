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

	void move(bool* keyDown);

	/*void moveRight(){
		player.x += playerSpeed;
		if (player.x + player.w >= windowWidth) {
			player.x = windowWidth - player.w;
		}
	}*/
	/*void moveLeft() {
		player.x -= playerSpeed;
		if (player.x < 0) {
			player.x = 0;
		}
	}*/
	void moveUp() {
		player.y -= playerSpeed;
		if (player.y < 0) {
			player.y = 0;
		}
	}
	void moveDown() {
		player.y += playerSpeed;
		if (player.y + player.h >= windowHeight) {
			player.y = windowHeight - player.h;
		}
	}

private:
	
	float playerSpeed = 0.1f;

	int windowWidth = 0;
	int windowHeight = 0;

	SDL_Rect player;
	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;

	// creatign a bool for moving
	enum KeyStates {
		LEFT = 0,
		RIGHT,
		UP,
		DOWN,
		KEYSTATES_COUNT
	};

	bool keyStates[KeyStates::KEYSTATES_COUNT];

};

