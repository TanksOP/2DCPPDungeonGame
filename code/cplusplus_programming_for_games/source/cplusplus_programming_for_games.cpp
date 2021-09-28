// cplusplus_programming_for_games.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <string>
#include <vector> 
#define SDL_MAIN_HANDLED
#include <SDL.h>

using namespace std;

//int main()
//{
//    std::cout << "Game Over!" << std::endl;
//    std::cout << "Or is it! ......." << std::endl;
//    return 0;
//}


//int main(int argc, char* argv[])
//{
//
//    // retutns zero on success else non-zero
//    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
//        printf("error initializing SDL: %s\n", SDL_GetError());
//    }
//    SDL_Window* win = SDL_CreateWindow("GAME",
//        SDL_WINDOWPOS_CENTERED,
//        SDL_WINDOWPOS_CENTERED,
//        1000, 1000, 0);
//    while (1)
//        ;
//
//    return 0;
//}

const int screenWidth = 800;
const int screenHeight = 600;



int main()
{

	

	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;

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

	vector<int> colour = {0,255,0};

	screenSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, colour[0], colour[1], colour[2]));
	SDL_UpdateWindowSurface(window);

	SDL_Delay(5000); // adds a delay so the window will stay open for a bit longer
	SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 255, 0, 0));
	SDL_UpdateWindowSurface(window);

	SDL_Delay(5000); // adds a delay so the window will stay open for a bit longer
	SDL_DestroyWindow(window); // closes the window
	SDL_Quit();
	return 0;
}

//void 