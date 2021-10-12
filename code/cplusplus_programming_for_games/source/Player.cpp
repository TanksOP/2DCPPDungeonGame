#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight)
{
	renderer = sdlRenderer;
	windowHeight = _windowHeight;
	windowWidth = _windowWidth;
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
	SDL_Rect portion = SDL_Rect(); // creates a rectangle to base carlos size off of
	portion.x = PlayerX;
	portion.y = PlayerY;
	portion.w = 50;
	portion.h = 50;

	float playerWidth = 0.1f * (float)windowWidth; // sets chibi carlo size relative to the screen size
	portion.w = (int)playerWidth;
	portion.h = (int)playerWidth;
	SDL_RenderCopy(renderer, texture, NULL, &portion); // renders carlo (texture) base off of the portion
}
void Player::update()
{

}
void Player::clean() 
{

}