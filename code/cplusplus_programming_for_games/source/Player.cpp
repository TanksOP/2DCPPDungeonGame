#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer, TiledMap* _tiledMap, int _windowWidth, int _windowHeight)
{
	tileMap = _tiledMap;
	renderer = sdlRenderer;
	windowHeight = _windowHeight;
	windowWidth = _windowWidth;
	playerWidth = 0.05f * (float)windowWidth;
	playerHeight = 0.1f * (float)windowHeight;
	
	
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
	SDL_FreeSurface(image);
	SDL_Surface* image2 = IMG_Load("Assets/DungeonTileset/DungeonTilesetII.png");
	if (image2 == nullptr)
	{
		std::cout << "Could not load image" << std::endl;
		return;
	}
	texture2 = SDL_CreateTextureFromSurface(renderer, image2);
	SDL_FreeSurface(image2);
	
}

void Player::processInput(bool* keyDown)
{
	if (keyDown[SDL_SCANCODE_LEFT]) {		
		if ((x - 0.2f) > 0
			&& tileMap->pathIsClear(x -0.2f, y, playerWidth, playerHeight)
			) {
			x -= 0.2f * playerSpeed;

			// below changes the animations from idle animations to runnign animations
			if (currentPlayerFrame >= 42 && currentPlayerFrame <= 45) {
				currentPlayerFrame = 46;
			}
			// makes the player face the diretion of movment
			flipPlayer = true;
		}
	}
	if (keyDown[SDL_SCANCODE_RIGHT]) {		
		if ((x + 0.2f) < (windowWidth - playerWidth) 
			&& tileMap->pathIsClear(x + 0.2f , y, playerWidth, playerHeight)
			) {
			x += 0.2f * playerSpeed;

			// below changes the animations from idle animations to runnign animations
			if (currentPlayerFrame >= 42 && currentPlayerFrame <= 45) {
				currentPlayerFrame = 46;
			}
			// makes the player face the diretion of movment
			flipPlayer = false;
			
		}		
	}
	if (keyDown[SDL_SCANCODE_UP]) {		
		if ((y - 0.2f) > 0
			&& tileMap->pathIsClear(x, y - 0.2f, playerWidth, playerHeight)
			) {
			y -= 0.2f * playerSpeed;

			// below changes the animations from idle animations to runnign animations
			if (currentPlayerFrame >= 42 && currentPlayerFrame <= 45) {
				currentPlayerFrame = 46;
			}
		}
	}
	if (keyDown[SDL_SCANCODE_DOWN]) {
		if ((y + 0.2f) < (windowHeight - playerHeight)
			&& tileMap->pathIsClear(x, y + 0.2f, playerWidth, playerHeight)
			) {
			y += 0.2f * playerSpeed;

			// below changes the animations from idle animations to runnign animations
			if (currentPlayerFrame >= 42 && currentPlayerFrame <= 45) {
				currentPlayerFrame = 46;
			}
		}
	}

	if (!keyDown[SDL_SCANCODE_LEFT] && !keyDown[SDL_SCANCODE_DOWN] && !keyDown[SDL_SCANCODE_RIGHT] && !keyDown[SDL_SCANCODE_UP] 
		&& currentPlayerFrame >= 46 && currentPlayerFrame <= 49)
	{
		currentPlayerFrame = 42;
	}
}

void Player::update()
{
	// creating animation frames so that every 200 ms is a new frame
	if (SDL_GetTicks() - lastAnimation > animationTimer) {
		animationUpdate();

		lastAnimation = SDL_GetTicks();
	}
}

void Player::animationUpdate()
{
	


	// the code below switches the animation states between idle and running
	if (currentPlayerFrame == 45) {
		currentPlayerFrame = 42;
	}
	else if (currentPlayerFrame == 49) {
		currentPlayerFrame = 46;
	}
	else {
		currentPlayerFrame += 1;
	}
	
}

void Player::render()
{
	SDL_Rect r = { x , y, (int)playerWidth, (int)playerHeight };

	SDL_Rect sourceRect;
	sourceRect.x = (currentPlayerFrame % 17) * playerSourceWidthPx;
	sourceRect.y = (currentPlayerFrame / 17) * playerSourceHeightPx;
	sourceRect.h = playerSourceHeightPx;
	sourceRect.w = playerSourceWidthPx;


	SDL_Rect renderRect;
	renderRect.x = x;
	renderRect.y = y;
	renderRect.h = (int)playerHeight;
	renderRect.w = (int)playerWidth;

	
	
	if (flipPlayer) {
		SDL_RenderCopyEx(renderer, texture2, &sourceRect, &renderRect, 0, NULL, SDL_FLIP_HORIZONTAL);
	}
	else {
		SDL_RenderCopy(renderer, texture2, &sourceRect, &renderRect);
	}
	
	
	//SDL_RenderCopy(renderer, texture, NULL, &r); // renders the player based off of rect r
}

void Player::clean() 
{
	SDL_DestroyTexture(texture);
}



