#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <iostream>
#include "TiledMap.h"

class Player
{
public:
	Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight);

	void init();

	void processInput(bool* keyDown);

	void update();

	void render();
	
	void clean();

	

private:
	
	float playerSpeed = 1;
	float x, y;

	int windowWidth = 0;
	int windowHeight = 0;
	float playerWidth = 0;
	float playerHeight = 0;

	//SDL_Rect player;

	SDL_Renderer* renderer = nullptr;
	SDL_Texture* texture = nullptr;

	TiledMap* tileMap;

	
};

