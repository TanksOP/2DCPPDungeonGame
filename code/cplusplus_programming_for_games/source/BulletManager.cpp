#include "BulletManager.h"

BulletManager::BulletManager(SDL_Renderer* _renderer, Player* _player)
{
	renderer = _renderer;
	player = _player;
	
}

void BulletManager::init()
{
	SDL_Surface* surface = IMG_Load("Assets/images/enemy.png");
	this->bulletTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
}

void BulletManager::CreateBullets() 
{
	
	if (SDL_GetTicks() - lastShot > shootTimerMS) {
		bullets.push_back(Bullet{ player->GetX() , player->GetY(), 0,0.0f });
		lastShot = SDL_GetTicks();
		std::cout << "here" << std::endl;
	}
}

void BulletManager::update()
{
	for (auto& b : bullets) {
		b.x += 0.1;
		b.y -= 0;
		/*b.x += sin(b.rotation * PI / 180.0f) * bulletVelocity;
		b.y -= cos(b.rotation * PI / 180.0f) * bulletVelocity;*/
		b.distance += bulletVelocity;
	}

	auto remove = remove_if(bullets.begin(), bullets.end(),
	//[](const Bullet& b) {return b.distance > 1000; });
	[](const Bullet& b) {return b.distance > 5000; });
	// if distace > 1000 remove the bullet
	bullets.erase(remove, bullets.end()); // removes etra spce still in the vector
}

void BulletManager::render()
{
	
	SDL_Point center = { 5,5 };
	for (auto& b : bullets) {
		SDL_Rect dest = { b.x, b.y, 10, 10 };
		SDL_RenderCopyEx(renderer, bulletTexture, 0, &dest, b.rotation, &center, SDL_FLIP_NONE);

	}
}

void BulletManager::clean()
{
	SDL_DestroyTexture(this->bulletTexture);
}
