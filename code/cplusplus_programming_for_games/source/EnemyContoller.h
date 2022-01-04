#pragma once
#include <SDL.h>
#include <SDL_image.h>
#include <vector>
#include <iostream>
#include <string>
#include "BulletManager.h"
#include "Player.h"
#include "AStarAlgorithum.h"
#include "TiledMap.h"
#include "SoundController.h"
#include "SpikeTrap.h"
#include "Particles.h"


class EnemyContoller
{
	friend class TiledMap;
public: 
	EnemyContoller(SDL_Renderer* _renderer, BulletManager* _bulletManager, Player* _player, TiledMap* _tiledMap, SoundController* _soundController, SpikeTrap* _spikeTrap, Particles* _particle);

	struct Enemy
	{
		float x, y;
		bool alive;
		int health;
		int maxHealth;
		std::vector<Node> path;
		bool EnemyMoving = false;
		float speed = 1.f / 40.f;
		Node enemy;
		Node dest;
	};

	void init();

	void createEnemy();

	void update(float& level);

	void animationUpdate();

	int getScore();

	int getEnemiesleft();

	void render();

	void Reset() {
		score = 0;
		enemiesLeft = 20;
		for (auto& e : enemys)
		{
			e.alive = false;
		}
	}

	void clean();

private:
	SDL_Texture* enemyTexture;
	SDL_Texture* enemyHealthTexture;
	SDL_Renderer* renderer;
	std::vector<Enemy> enemys;

	BulletManager* bulletManager;
	Player* player;
	TiledMap* tiledMap;
	SoundController* soundController;
	SpikeTrap* spikeTrap;
	Particles* particles;
	


	// used to create animation frames for the player
	float animationTimer = 100.0f;
	float lastAnimation = 0.0f;
	// allow for the abity yo filp the texture of the player depending on which direction they are moving in
	
	int currentPlayerFrame = 0;

	int score;
	int enemiesLeft = 20;

};

