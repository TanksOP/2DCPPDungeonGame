#pragma once

#include <iostream>
#include <string>
#include <vector> 
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Player.h"

class GameLoop
{
public:
	int init();

	void update();
	void render();
	bool keepAlive();

	void clean();

private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	Player* player = nullptr;

};

