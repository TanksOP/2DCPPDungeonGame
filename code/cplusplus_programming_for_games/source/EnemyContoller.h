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


class EnemyContoller
{
public: 
	EnemyContoller(SDL_Renderer* _renderer, BulletManager* _bulletManager, Player* _player, TiledMap* _tiledMap, SoundController* _soundController, SpikeTrap* _spikeTrap);

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

	void update();

	void animationUpdate();

	int getScore();

	int getEnemiesleft();

	void render();

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
	


	// used to create animation frames for the player
	float animationTimer = 100.0f;
	float lastAnimation = 0.0f;
	// allow for the abity yo filp the texture of the player depending on which direction they are moving in
	
	int currentPlayerFrame = 0;

	int score;
	int enemiesLeft = 20;

};

