#pragma once


#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <math.h>
#include <iostream>
#include <algorithm>

#include "Player.h"

#define PI 3.14159265

class BulletManager
{
	friend class EnemyContoller;
public:
	BulletManager(SDL_Renderer* _renderer, Player* _player, TiledMap* _tiledMap);

	struct Bullet {
		float x, y, rotation, distance;
	};

	void init();

	void CreateBullets(bool MouseLeftButton);

	void update();

	void render();

	void clean();

private:
	SDL_Renderer* renderer;
	Player* player;
	TiledMap* tileMap;
	
	SDL_Texture* bulletTexture;
	std::vector<Bullet> bullets;

	int shootTimerMS = 500.0f;
	float bulletVelocity = .1f;
	unsigned int lastShot = 0;

	int mouseX, mouseY;

};

