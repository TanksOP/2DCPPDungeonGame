#include "BulletManager.h"

BulletManager::BulletManager(SDL_Renderer* _renderer, Player* _player, TiledMap* _tiledMap, SoundController* _soundController)
{
	renderer = _renderer;
	player = _player;
	tileMap = _tiledMap;
	soundController = _soundController;
	
}

void BulletManager::init()
{
	// loads the bullet texture
	SDL_Surface* surface = IMG_Load("Assets/throwingSword.png");
	this->bulletTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
}

void BulletManager::CreateBullets(bool MouseLeftButton)
{
	// when the left mouse button pressed down and the shootTimerMS () has passed create a new bullet addding it to the bullet vector
	if (MouseLeftButton)
	{
		if (SDL_GetTicks() - lastShot > shootTimerMS) {
			SDL_GetMouseState(&mouseX, &mouseY);
			float testRotation = atan2f(mouseY - player->GetY(), mouseX - player->GetX());
			std::cout << testRotation << std::endl;

			bullets.push_back(Bullet{ player->GetX() , player->GetY(), testRotation + (0.5f * 3.14159265f) ,0.0f });

			lastShot = SDL_GetTicks();
			soundController->PlaySound(Sounds::SHOOT);
			
		}
	}
	
}

void BulletManager::update()
{
	for (auto& b : bullets) {

		// moves the bullet using it's speed and starting rotation
		b.x += sin(b.rotation) * bulletVelocity;
		b.y -= cos(b.rotation) * bulletVelocity;
		b.distance += bulletVelocity;
	
	}

	//deletes the bullets from the bullet vector when they go off of the screen or it's distace is > 1000
	auto remove = remove_if(bullets.begin(), bullets.end(),
	[](const Bullet& b) {
			return b.distance > 1000 ||
		b.y < 120 ||
		b.x < 60 ||
		b.y > 900 - 45||
		b.x > 1200 - 60; });
	// removes extra space still in the vector
	bullets.erase(remove, bullets.end());
}

void BulletManager::Reset()
{
	//empties the bullet vector to clear the screen of all bullets
	bullets.clear();
}


void BulletManager::render()
{
	
	SDL_Point center = { 5,5 };
	for (auto& b : bullets) {
		SDL_Rect dest = { b.x, b.y, 20, 20 };
		SDL_RenderCopyEx(renderer, bulletTexture, 0, &dest, b.rotation / PI * 180.0f, &center, SDL_FLIP_NONE);

	}
}

void BulletManager::clean()
{
	SDL_DestroyTexture(this->bulletTexture);
}
