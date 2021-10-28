#pragma once

#include <iostream>
#include <string>
#include <vector> 
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Player.h"
#include "FontRenderer.h"
#include "TiledMap.h"


class GameLoop
{
public:
	int init();

	void update();
	void render();
	bool keepAlive();
	void handleInput(SDL_Scancode& keyScanCode);

	void clean();

private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;
	std::unique_ptr<FontRenderer> fontRenderer;
	std::unique_ptr<TiledMap> tiledMap;

	Player* player = nullptr;

};

