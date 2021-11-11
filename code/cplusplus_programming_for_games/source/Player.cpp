#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer, int _windowWidth, int _windowHeight)
{
	renderer = sdlRenderer;
	windowHeight = _windowHeight;
	windowWidth = _windowWidth;
	playerWidth = 0.1f * (float)windowWidth;
}

void Player::init()
{
	SDL_Surface* image = IMG_Load("assets/chibiCarlo.png");
	if (image == nullptr)
	{
		std::cout << "Could not load image" << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
}

void Player::processInput(bool* keyDown)
{
	if (keyDown[SDL_SCANCODE_LEFT]) {		
		if ((x - 0.2f) > 0) {
			x -= 0.2f;
		}
	}
	if (keyDown[SDL_SCANCODE_RIGHT]) {		
		if ((x + 0.2f) < (windowWidth - playerWidth) 
			&& tileMap->pathIsClear(x + 0.2f, y, playerWidth)
			) {
			x += 0.2f;
		}		
	}
	if (keyDown[SDL_SCANCODE_UP]) {		
		if ((y - 0.2f) > 0) {
			y -= 0.2f;
		}
	}
	if (keyDown[SDL_SCANCODE_DOWN]) {
		if ((y + 0.2f) < (windowHeight - playerWidth)) {
			y += 0.2f;
		}
	}
}

void Player::update()
{

}

void Player::render()
{
	SDL_Rect r = { x , y, (int)playerWidth, (int)playerWidth };
	
	SDL_RenderCopy(renderer, texture, NULL, &r); // renders the player based off of rect r
}

void Player::clean() 
{
	SDL_DestroyTexture(texture);
}



