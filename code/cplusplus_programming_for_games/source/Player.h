#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TiledMap.h"

class Player
{
	friend class EnemyContoller;
public:
	Player(SDL_Renderer* sdlRenderer, TiledMap* _tileMap, int _windowWidth, int _windowHeight);

	void init();

	void processInput(bool* keyDown);

	void update();

	void animationUpdate();

	void render();

	

	float GetX() {
		return x + (playerWidth/2);
	}

	float GetY() {
		return y + (playerHeight/2);
	}
	
	void clean();

	

private:
	
	float playerSpeed = 0.1;
	float x = 300;
	float y = 300;
	int health = 6;

	int windowWidth = 0;
	int windowHeight = 0;
	float playerWidth = 0;
	float playerHeight = 0;

	int playerSourceHeightPx = 32;
	int playerSourceWidthPx = 16;

	// used to create animation frames for the player
	float animationTimer = 200.0f;
	float lastAnimation = 0.0f;
	// allow for the abity yo filp the texture of the player depending on which direction they are moving in
	bool flipPlayer = false;
	

	// the current animations for the player 42-45: idle animation and 46-49: running animation
	int currentPlayerFrame = 42;

	//SDL_Rect player;

	SDL_Renderer* renderer = nullptr;
	SDL_Texture* heartFullTexture = nullptr;
	SDL_Texture* heartHalfTexture = nullptr;
	SDL_Texture* heartEmptyTexture = nullptr;
	SDL_Texture* playerTexture = nullptr;

	TiledMap* tileMap;

	
};

