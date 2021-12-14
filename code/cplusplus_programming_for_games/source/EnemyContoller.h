#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include "BulletManager.h"
#include "Player.h"

class EnemyContoller
{
public: 
	EnemyContoller(SDL_Renderer* _renderer, BulletManager* _bulletManager, Player* _player);

	struct Enemy
	{
		float x, y;
		bool alive;
		int health;
		int maxHealth;
	};

	void init();

	void createEnemy();

	void update();

	void render();

	void clean();

private:
	SDL_Texture* enemyTexture;
	SDL_Texture* enemyHealthTexture;
	SDL_Renderer* renderer;
	std::vector<Enemy> enemys;

	BulletManager* bulletManager;
	Player* player;




};

