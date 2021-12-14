#include "EnemyContoller.h"

EnemyContoller::EnemyContoller(SDL_Renderer* _renderer, BulletManager* _bulletManager, Player* _player)
{
	renderer = _renderer;
	bulletManager = _bulletManager;
	player = _player;

}

void EnemyContoller::init()
{
	SDL_Surface* surface = IMG_Load("Assets/DungeonTileset/frames/orc_warrior_idle_anim_f0.png");
	this->enemyTexture = SDL_CreateTextureFromSurface(this->renderer, surface);
	SDL_FreeSurface(surface);
	SDL_Surface* surface2 = IMG_Load("Assets/red.png");
	this->enemyHealthTexture = SDL_CreateTextureFromSurface(this->renderer, surface2);
	SDL_FreeSurface(surface2);

	
}

void EnemyContoller::createEnemy()
{
	// code in here for future will be used to determin what enemy to create

	// this is just a simple line of code for now that will be changed in the future to add more functionality 
	enemys.push_back(Enemy{ float(rand() % 100), float(rand() % 600), true, 3 , 3});
	std::cout << "Spawned an enemy" << std::endl;

}

void EnemyContoller::update()
{
	if (enemys.size() < 5) 
	{
		createEnemy();
	}

	for (auto& e : enemys)
	{
		e.x += 0.02;

		if (e.x > 800) {
			e.alive = false;
		}

		if (e.health <= 0)
		{
			e.alive = false;
		}



		// detects collition between bullets and the enemies
		for (auto& b : bulletManager->bullets) 
		{
			SDL_Rect bulletRect = { b.x, b.y, 20, 20 }; // collision box of bullet
			SDL_Rect enemyRect = { e.x, e.y, 32, 32 }; // collition box of meteor
			SDL_Rect nullRect;
			if (SDL_IntersectRect(&bulletRect, &enemyRect, &nullRect)) {
				b.distance = 1001;
				e.health -= 1;
			}
		}

		// detects collition with the player 
		SDL_Rect playerRect = { player->x, player->y, player->playerWidth, player->playerHeight };
		SDL_Rect enemyRect = { e.x, e.y, 32, 32 };
		SDL_Rect nullRect;
		if (SDL_IntersectRect(&playerRect, &enemyRect, &nullRect)) {
			player->health -= 1;
			e.alive = false;
		}
	}

	
	

	// removes any of the enemies if they have been killed
	auto remove = std::remove_if(enemys.begin(), enemys.end(),
		[](const Enemy& e) {return !e.alive; });
	enemys.erase(remove, enemys.end());

	
}

void EnemyContoller::render()
{
	for (auto& e : enemys)
	{
		SDL_Rect dest = { e.x, e.y, 32, 32 };
		SDL_RenderCopy(renderer, enemyTexture, 0, &dest);


		// enemy health bar displayed above their head
		// uses the x and y position of the enemy for the startign position, 
		// then uses the max health and health values to work out the length of 
		// bar meaning that even if the max health is greater the bar does not get longer.
		SDL_Rect healthBar = { e.x, e.y - 3, 35/e.maxHealth * e.health , 3 };
		SDL_RenderCopy(renderer, enemyHealthTexture, 0, &healthBar);
	}
}

void EnemyContoller::clean()
{
	SDL_DestroyTexture(enemyTexture);
	SDL_DestroyTexture(enemyHealthTexture);

}
