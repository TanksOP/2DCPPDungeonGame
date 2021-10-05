#include "GameLoop.h"

const int screenWidth = 800;
const int screenHeight = 600;

SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;

int GameLoop::init()
{
	

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "could not initialize SDL2!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	window = SDL_CreateWindow(
		"hello_sdl2",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) { // this si called if the widow could not be created
		std::cout << "could not initialise window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	screenSurface = SDL_GetWindowSurface(window);
	return 0;
}

void GameLoop::update()
{

}

void GameLoop::render()
{

}

void GameLoop::clean()
{
	SDL_DestroyWindow(window);
	SDL_Quit();
}

bool GameLoop::keepAlive()
{
	SDL_Event userInput;
	while (SDL_PollEvent(&userInput))
	{

	}

}

