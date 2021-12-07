#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer, TiledMap* _tiledMap, int _windowWidth, int _windowHeight)
{
	tileMap = _tiledMap;
	renderer = sdlRenderer;
	windowHeight = _windowHeight;
	windowWidth = _windowWidth;
	playerWidth = 0.05f * (float)windowWidth;
	playerHeight = 0.08f * (float)windowWidth;
}

void Player::init()
{
	SDL_Surface* image = IMG_Load("Assets/DungeonTileset/frames/knight_f_idle_anim_f0.png");
	if (image == nullptr)
	{
		std::cout << "Could not load image" << std::endl;
		return;
	}
	texture = SDL_CreateTextureFromSurface(renderer, image);

	SDL_Surface* image = IMG_Load("Assets/DungeonTileset/DungeonTilesetII.png");
	if (image == nullptr)
	{
		std::cout << "Could not load image" << std::endl;
		return;
	}
	texture2 = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	
}

void Player::processInput(bool* keyDown)
{
	if (keyDown[SDL_SCANCODE_LEFT]) {		
		if ((x - 0.2f) > 0
			&& tileMap->pathIsClear(x -0.2f, y, playerWidth, playerHeight)
			) {
			x -= 0.2f * playerSpeed;
		}
	}
	if (keyDown[SDL_SCANCODE_RIGHT]) {		
		if ((x + 0.2f) < (windowWidth - playerWidth) 
			&& tileMap->pathIsClear(x + 0.2f , y, playerWidth, playerHeight)
			) {
			x += 0.2f * playerSpeed;
		}		
	}
	if (keyDown[SDL_SCANCODE_UP]) {		
		if ((y - 0.2f) > 0
			&& tileMap->pathIsClear(x, y - 0.2f, playerWidth, playerHeight)
			) {
			y -= 0.2f * playerSpeed;
		}
	}
	if (keyDown[SDL_SCANCODE_DOWN]) {
		if ((y + 0.2f) < (windowHeight - playerHeight)
			&& tileMap->pathIsClear(x, y + 0.2f, playerWidth, playerHeight)
			) {
			y += 0.2f * playerSpeed;
		}
	}
}

void Player::update()
{

	if (SDL_GetTicks() - lastAnimation > animationTimer) {
		animationUpdate();

		lastAnimation = SDL_GetTicks();
	}
}

void Player::animationUpdate()
{
	std::cout << "hello" << std::endl;

	// add in stuff from tile map scripts and read the values for the player idle animation
	// create  avariable that after settign the texture to the animation picture it set the new animation frame
	// so that it can be used when it goes back through and chanegs the texture 
}

void Player::render()
{
	SDL_Rect r = { x , y, (int)playerWidth, (int)playerHeight };
	
	SDL_RenderCopy(renderer, texture, NULL, &r); // renders the player based off of rect r
}

void Player::clean() 
{
	SDL_DestroyTexture(texture);
}



