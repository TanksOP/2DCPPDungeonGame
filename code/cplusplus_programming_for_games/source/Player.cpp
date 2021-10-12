#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer)
{
	renderer = sdlRenderer;
}

void Player::init()
{
	SDL_Surface* image = IMG_Load("assets/chibiCarlo.png");
	if (image == nullptr)
	{
		std::cout << "Could no tload image" << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);
}
void Player::render()
{
	SDL_Rect portion = SDL_Rect();
	portion.x = PlayerX;
	portion.y = PlayerY;
	portion.w = 50;
	portion.h = 50;
	SDL_RenderCopy(renderer, texture, NULL, &portion);
}
void Player::update()
{

}
void Player::clean() 
{

}