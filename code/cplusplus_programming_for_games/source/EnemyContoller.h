#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include "BulletManager.h"

class EnemyContoller
{
public: 
	EnemyContoller(SDL_Renderer* _renderer, BulletManager* _bulletManager);

	struct Enemy
	{
		float x, y;
		bool alive;
	};

	void init();

	void createEnemy();

	void update();

	void render();

	void clean();

private:
	SDL_Texture* enemyTexture;
	SDL_Renderer* renderer;
	std::vector<Enemy> enemys;

	BulletManager* bulletManager;




};

