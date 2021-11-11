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
	
	float playerWidth = 0.1f * (float)windowWidth; // sets chibi carlo size relative to the screen size
	player.w = (int)playerWidth;
	player.h = (int)playerWidth;
	SDL_RenderCopy(renderer, texture, NULL, &player); // renders carlo (texture) base off of the player
}

void Player::move(bool* keyDown)
{
	
	if (keyDown[SDL_SCANCODE_LEFT] || keyDown[SDL_SCANCODE_A]) {
		std::cout << "left" << std::endl;
		player.x -= playerSpeed;
		if (player.x < 0) {
			player.x = 0;
		}
	}
	if (keyDown[SDL_SCANCODE_RIGHT] || keyDown[SDL_SCANCODE_D]) {
		std::cout << "right" << std::endl;
		player.x += 1;
		if (player.x + player.w >= windowWidth) {
			player.x = windowWidth - player.w;
		}
	}
}

void Player::update()
{

}
void Player::clean() 
{

}



