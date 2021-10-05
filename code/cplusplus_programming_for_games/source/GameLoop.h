#pragma once

#include <iostream>
#include <string>
#include <vector> 
#define SDL_MAIN_HANDLED
#include <SDL.h>

class GameLoop
{
public:
	int init();

	void update();
	void render();
	bool keepAlive();

	void clean();

private:

};

