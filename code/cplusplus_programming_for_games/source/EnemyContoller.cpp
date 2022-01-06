#include "EnemyContoller.h"

EnemyContoller::EnemyContoller(SDL_Renderer* _renderer, BulletManager* _bulletManager, Player* _player, TiledMap* _tiledMap, SoundController* _soundController, SpikeTrap* _spikeTrap, Particles* _particle)
{
	renderer = _renderer;
	bulletManager = _bulletManager;
	player = _player;
	tiledMap = _tiledMap;
	soundController = _soundController;
	spikeTrap = _spikeTrap;
	particles = _particle;

}

void EnemyContoller::init()
{
	
	SDL_Surface* surface2 = IMG_Load("Assets/red.png");
	this->enemyHealthTexture = SDL_CreateTextureFromSurface(this->renderer, surface2);
	SDL_FreeSurface(surface2);
	
	SDL_Surface* surface3 = IMG_Load("Assets/DungeonTileset/orcAnimation.png");
	enemyTexture = SDL_CreateTextureFromSurface(renderer, surface3);
	SDL_FreeSurface(surface3);

	
}

void EnemyContoller::createEnemy()
{
	
	// creates a random number that will decide what corner to spawn the enimes in
	int enemySpawnLocation = rand() % 4;

	switch (enemySpawnLocation)
	{
	case 0:
		enemys.push_back(Enemy{ 1200 / 20 * 2, 900 / 20 * 4, true, 2, 2 });
		break;
	case 1:
		enemys.push_back(Enemy{ 1200 / 20 * 2, 900 / 20 * 18, true, 2, 2 });
		break;
	case 2:
		enemys.push_back(Enemy{ 1200 / 20 * 18, 900 / 20 * 4, true, 2, 2 });
		break;
	case 3:
		enemys.push_back(Enemy{ 1200 / 20 * 18, 900 / 20 * 18, true, 2, 2 });
		break;
	default:
		break;
	}
}

void EnemyContoller::update(float &level)
{
	// creating animation frames so that every 200 ms is a new frame
	if (SDL_GetTicks() - lastAnimation > animationTimer) {
		animationUpdate();

		lastAnimation = SDL_GetTicks();
	}

	// create anouther enemey when there is less then 10 and if it is still meant to spwn anouther enemy
	if (enemys.size()  < 10 && enemys.size() < enemiesLeft) 
	{
		createEnemy();
	}

	// when th eplayer has killed all of the enemies change the level to 1.5 so that it is between levels.
	if (enemiesLeft <= 0) {
		level = 1.5f;
	}



	for (auto& e : enemys)
	{

		// when the enemy hits a spike they loose health anf play blood splatter particle efect

		if (spikeTrap->ouchSpikes(e.x , e.y , 16, 20)) {
			e.health--;
			particles->createBloodSplatter(e.x + 16, e.y + 20);
		}

		// the code below passes the destiationa and start position of the enemy for the a* pathfing algorithum to use to make a path
		if (!e.EnemyMoving) {		
			
			e.enemy.x = e.x / 1200 * 20 ;
			e.enemy.y = e.y / 900 * 20;
			// creates a node point for where the desired destiation is
			
			// gets the player position
			e.dest.x = (player->x + 0.5*player->playerWidth) / 1200 * 20;
			e.dest.y = (player->y + 0.5*player->playerHeight) /900 * 20 ;
			
			
			// creates the path the ememy will take
			e.path = aStar(tiledMap->MAP_DATA, e.enemy, e.dest);
			if (e.path.size() > 1) {
				e.EnemyMoving = true;
			}
		}

		// this code allows for smooth movement between the points on the path created.
		if (e.EnemyMoving)
		{	

			if (e.y / 900 * 20 < e.path[1].y - e.speed  )
			{
				e.y += e.speed;
			}
			else if (e.y / 900 * 20 > e.path[1].y + e.speed)
			{
				e.y -= e.speed;
			}
			else if (e.x / 1200 * 20 < e.path[1].x - e.speed )
			{
				e.x += e.speed;
			}
			else if (e.x / 1200 * 20  > e.path[1].x + e.speed  )
			{
				e.x -= e.speed;
			}
			else {
					e.EnemyMoving = false;
					e.x = e.path[1].x * 1200 / 20;
					e.y = e.path[1].y * 900 / 20;				
			}
			
		}
		// if an enemies health reaches 0  the score will increase al well as settign its alive condition to flase to it will be deleted
		if (e.health <= 0)
		{
			e.alive = false;
			score++;
			enemiesLeft--;
		}

		// detects collition between bullets and the enemies using circle collition
		for (auto& b : bulletManager->bullets) 
		{
			// circle collision
			int diffX = b.x - e.x;
			int diffY = b.y - e.y;
			int vectorLength = sqrt(diffX * diffX + diffY * diffY);
			if (vectorLength < (20 + 32)) {
				b.distance = 1001;
				e.health -= 1;
				particles->createBloodSplatter(e.x + 16, e.y + 20);
			}
		}

		// detects collition with the player 
		SDL_Rect playerRect = { player->x, player->y, player->playerWidth, player->playerHeight };
		SDL_Rect enemyRect = { e.x, e.y, 32, 32 };
		SDL_Rect nullRect;
		if (SDL_IntersectRect(&playerRect, &enemyRect, &nullRect)) {
			player->health -= 1;
			e.alive = false;
			
			int oof = rand() % 2 + 1;
			std::cout << oof << std::endl;
			soundController->PlaySound(oof);
		}
	}

	
	

	// removes any of the enemies if they have been killed
	auto remove = std::remove_if(enemys.begin(), enemys.end(),
		[](const Enemy& e) {return !e.alive; });
	enemys.erase(remove, enemys.end());

	
}

void EnemyContoller::animationUpdate()
{
	// the code below switches the animation states between idle and running
	
	if (currentPlayerFrame >= 7) {
		currentPlayerFrame = 4;
	}
	else {
		currentPlayerFrame += 1;
	}
	
	
}

int EnemyContoller::getScore()
{
	return score;
}

int EnemyContoller::getEnemiesleft()
{
	return enemiesLeft;
}

void EnemyContoller::render()
{
	for (auto& e : enemys)
	{
		SDL_Rect dest = { e.x, e.y, 32, 40 };	

		SDL_Rect sourceRect;
		sourceRect = { (currentPlayerFrame % 8) * 16 , 0 ,16 , 20};
		
		// 1.25 0.8
		SDL_RenderCopy(renderer, enemyTexture, &sourceRect, &dest);

		// displayes a healthbar above the enemies
		SDL_Rect healthBar = { e.x, e.y - 3, 35/e.maxHealth * e.health , 3 };
		SDL_RenderCopy(renderer, enemyHealthTexture, 0, &healthBar);
	}
}



void EnemyContoller::clean()
{
	SDL_DestroyTexture(enemyTexture);
	SDL_DestroyTexture(enemyHealthTexture);

}
