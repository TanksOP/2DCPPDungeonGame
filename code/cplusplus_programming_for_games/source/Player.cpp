#include "Player.h"

Player::Player(SDL_Renderer* sdlRenderer, TiledMap* _tiledMap, int _windowWidth, int _windowHeight, SpikeTrap* _spikeTrap, SoundController* _sound)
{
	tileMap = _tiledMap;
	renderer = sdlRenderer;
	windowHeight = _windowHeight;
	windowWidth = _windowWidth;
	spikeTrap = _spikeTrap;
	sound = _sound;
	/*playerWidth = 0.03f * (float)windowWidth;
	playerHeight = 0.049f * (float)windowHeight;	*/
	playerWidth = 45;
	playerHeight = 45;
}

void Player::init()
{
	//importing the lives        might change later to just use the tile map to get these idk
	// importing the tile map
	SDL_Surface* image1 = IMG_Load("Assets/DungeonTileset/frames/ui_heart_full.png");
	if (image1 == nullptr) {
		std::cout << "Could not load image" << std::endl;
		return;
	}
	heartFullTexture = SDL_CreateTextureFromSurface(renderer, image1);
	SDL_FreeSurface(image1);

	SDL_Surface* image2 = IMG_Load("Assets/DungeonTileset/frames/ui_heart_half.png");
	if (image2 == nullptr) {
		std::cout << "Could not load image" << std::endl;
		return;
	}
	heartHalfTexture = SDL_CreateTextureFromSurface(renderer, image2);
	SDL_FreeSurface(image2);

	SDL_Surface* image3 = IMG_Load("Assets/DungeonTileset/frames/ui_heart_empty.png");
	if (image3 == nullptr) {
		std::cout << "Could not load image" << std::endl;
		return;
	}
	heartEmptyTexture = SDL_CreateTextureFromSurface(renderer, image3);
	SDL_FreeSurface(image3);

	// importing the tile map
	SDL_Surface* image = IMG_Load("Assets/DungeonTileset/playerKnightAnimation.png");
	if (image == nullptr){
		std::cout << "Could not load image" << std::endl;
		return;
	}
	playerTexture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	
}

void Player::processInput(bool* keyDown)
{
	if (keyDown[SDL_SCANCODE_LEFT] || keyDown[SDL_SCANCODE_A]) {
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
	if (keyDown[SDL_SCANCODE_RIGHT] || keyDown[SDL_SCANCODE_D]) {
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
	if (keyDown[SDL_SCANCODE_UP] || keyDown[SDL_SCANCODE_W]) {
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
	if (keyDown[SDL_SCANCODE_DOWN] || keyDown[SDL_SCANCODE_S]) {
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
		&& !keyDown[SDL_SCANCODE_A] && !keyDown[SDL_SCANCODE_S] && !keyDown[SDL_SCANCODE_D] && !keyDown[SDL_SCANCODE_W]
		&& currentPlayerFrame >= 46 && currentPlayerFrame <= 49)
	{
		currentPlayerFrame = 42;
	}
}

void Player::update()
{
	if (spikeTrap->ouchSpikes(x + 8, y + 11, 16, 20)) {
		health--;
		int oof = rand() % 2 + 1;
		sound->PlaySound(oof);
				
	}
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

	// render player
	SDL_Rect r = { x , y, (int)playerWidth, (int)playerHeight };

	SDL_Rect sourceRect;
	sourceRect.x = (currentPlayerFrame % 8) * playerSourceWidthPx;
	sourceRect.y = 0;
	sourceRect.h = 22;
	sourceRect.w = 16;

	SDL_Rect renderRect;
	renderRect.x = x;
	renderRect.y = y;
	renderRect.h = (int)playerHeight;
	renderRect.w = (int)playerWidth;
	
	if (flipPlayer) {
		SDL_RenderCopyEx(renderer, playerTexture, &sourceRect, &renderRect, 0, NULL, SDL_FLIP_HORIZONTAL);
	}
	else {
		SDL_RenderCopy(renderer, playerTexture, &sourceRect, &renderRect);
	}

	// render player lives

	SDL_Rect renderLife1 = { 125, 25, 45, 45 };
	SDL_Rect renderLife2 = { 175, 25, 45, 45 };
	SDL_Rect renderLife3 = { 225, 25, 45, 45 };

	switch (health)
	{
	case 0:
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife1);
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife2);
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife3);
		break;
	case 1:
		SDL_RenderCopy(renderer, heartHalfTexture, 0, &renderLife1);
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife2);
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife3);
		break;
	case 2:
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife1);
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife2);
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife3);
		break;
	case 3:
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife1);
		SDL_RenderCopy(renderer, heartHalfTexture, 0, &renderLife2);
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife3);
		break;
	case 4:
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife1);
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife2);
		SDL_RenderCopy(renderer, heartEmptyTexture, 0, &renderLife3);
		break;
	case 5:
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife1);
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife2);
		SDL_RenderCopy(renderer, heartHalfTexture, 0, &renderLife3);
		break;
	case 6 :
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife1);
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife2);
		SDL_RenderCopy(renderer, heartFullTexture, 0, &renderLife3);
		break;
	default:
		break;
	}
}

void Player::clean() 
{
	SDL_DestroyTexture(playerTexture);
	SDL_DestroyTexture(heartFullTexture);
	SDL_DestroyTexture(heartHalfTexture);
	SDL_DestroyTexture(heartEmptyTexture);
}



