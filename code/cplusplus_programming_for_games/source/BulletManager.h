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
public:
	BulletManager(SDL_Renderer* _renderer, Player* _player);

	struct Bullet {
		float x, y, rotation, distance;
	};

	void init();

	void CreateBullets();

	void update();

	void render();

	void clean();

private:
	SDL_Renderer* renderer;
	Player* player;
	
	SDL_Texture* bulletTexture;
	std::vector<Bullet> bullets;

	int shootTimerMS = 300;
	int bulletVelocity = 1;
	unsigned int lastShot = 0;

};

