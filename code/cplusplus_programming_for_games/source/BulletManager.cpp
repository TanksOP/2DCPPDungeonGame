#include "BulletManager.h"

BulletManager::BulletManager(SDL_Renderer* _renderer, Player* _player, TiledMap* _tiledMap)
{
	renderer = _renderer;
	player = _player;
	tileMap = _tiledMap;
	
}

void BulletManager::init()
{
	SDL_Surface* surface = IMG_Load("Assets/images/enemy.png");
	this->bulletTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
}

void BulletManager::CreateBullets(bool MouseLeftButton)
{
	if (MouseLeftButton)
	{
		if (SDL_GetTicks() - lastShot > shootTimerMS) {
			SDL_GetMouseState(&mouseX, &mouseY);
			float testRotation = atan2f(mouseY - player->GetY(), mouseX - player->GetX());
			std::cout << testRotation << std::endl;
			bullets.push_back(Bullet{ player->GetX() , player->GetY(), testRotation + (0.5f * 3.14159265f) ,0.0f });
			lastShot = SDL_GetTicks();
			//std::cout << "here" << std::endl;
		}
	}
	
}

//SDL_Render
void BulletManager::update()
{
	for (auto& b : bullets) {
		
		if (tileMap->pathIsClear(b.x + sin(b.rotation) * bulletVelocity, b.y - cos(b.rotation) * bulletVelocity, 20, 20))
		{
			b.x += sin(b.rotation) * bulletVelocity;
			b.y -= cos(b.rotation) * bulletVelocity;
			b.distance += bulletVelocity;
		}
		else {
			b.distance = 1001;
		
		}
	}

	auto remove = remove_if(bullets.begin(), bullets.end(),
	[](const Bullet& b) {
			return b.distance > 1000 ||
		b.y < 1 ||
		b.x < 1 ||
		b.y > 579||
		b.x > 779; });

	// if distace > 1000 remove the bullet
	bullets.erase(remove, bullets.end()); // removes etra spce still in the vector
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
