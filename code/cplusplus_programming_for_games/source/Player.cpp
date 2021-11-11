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
		//std::cout << "left" << std::endl;
		//std::cout << player.x << std::endl;
		player.x -= playerSpeed * 0.5;
		if (player.x < 0) {
			player.x = 0;
		}
	}
	if (keyDown[SDL_SCANCODE_RIGHT] || keyDown[SDL_SCANCODE_D]) {
		//std::cout << "right" << std::endl;


		std::cout << playerSpeed << std::endl;
		player.x += playerSpeed ;
		std::cout << player.x << std::endl;


		if (player.x + player.w >= windowWidth) {
			player.x = windowWidth - player.w;
		}
	}
	if (keyDown[SDL_SCANCODE_UP] || keyDown[SDL_SCANCODE_W]) {
		//std::cout << "up" << std::endl;
		player.y -= playerSpeed * 0.5;
		if (player.y < 0) {
			player.y = 0;
		}
	}
	if (keyDown[SDL_SCANCODE_DOWN] || keyDown[SDL_SCANCODE_S]) {
		//std::cout << "down" << std::endl;
		player.y += playerSpeed * 0.5;
		if (player.y + player.h >= windowHeight) {
			player.y = windowHeight - player.h;
		}
	}
}

void Player::update()
{

}
void Player::clean() 
{

}



