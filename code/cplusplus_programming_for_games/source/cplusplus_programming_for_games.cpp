// cplusplus_programming_for_games.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL.h>

//int main()
//{
//    std::cout << "Game Over!" << std::endl;
//    std::cout << "Or is it! ......." << std::endl;
//    return 0;
//}


int main(int argc, char* argv[])
{

    // retutns zero on success else non-zero
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        printf("error initializing SDL: %s\n", SDL_GetError());
    }
    SDL_Window* win = SDL_CreateWindow("GAME",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
        1000, 1000, 0);
    while (1)
        ;

    return 0;
}