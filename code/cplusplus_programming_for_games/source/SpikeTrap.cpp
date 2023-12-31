#include "SpikeTrap.h"

SpikeTrap::SpikeTrap(TiledMap* _tileMap, int _windowWidth, int _windowHeight)
{
	tiledMap = _tileMap;
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
}

void SpikeTrap::init()
{
	
}

void SpikeTrap::spikeAnimation()
{
	// animates the spike trap
	for (auto& s : spikes) {

		if (SDL_GetTicks() - s.lastTrap == 5000) {
			s.tile = 78;
			s.animation = false;
		}
		else if (SDL_GetTicks() - s.lastTrap == 2000) {
			s.tile = 81;
		}
		else if (SDL_GetTicks() - s.lastTrap  == 100) {
			s.tile = 79;
		}
		
	}
}

void SpikeTrap::update()
{
	// works out wherether the spike trap should be annimated yet or not
	for (auto& s : spikes) {
		tiledMap->tileMap[s.x][s.y] = s.tile;

		if (s.animation) {
			spikeAnimation();
		}
		else {
			if (SDL_GetTicks() - s.lastTrap > s.trapTimer) {
				s.lastTrap = SDL_GetTicks();
				s.animation = true;				
			}
		
		}
	}
}

bool SpikeTrap::ouchSpikes(float x, float y, float _width, float _height)
{
	// works out colition with the spike trap based off of an x, y , width and height input	
	int xx = x / 1200 * 20;
	int yy = y/900 * 20;

		for (auto& s : spikes) {
			//std::cout << "Spike x:" << s.x<<"Spike y: " << s.y <<std::endl;
			if (s.x == xx && s.y == yy && s.tile == 81) {
				std::cout << "onSpiketile" << std::endl;
				s.tile = 78;
				s.animation = false;
				return true;
				//tiledMap->tileMap[xx][yy] = 78;
			}
		}
		
		return false;
	}

void SpikeTrap::createSpikes()
{
	// creates the spike traps bassed off of the tile map data
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (tiledMap->tileMap[j][i] == 78|| tiledMap->tileMap[j][i] == 79|| tiledMap->tileMap[j][i] == 81) {
				spikes.push_back(Spike{ j, i, 78, 10000, -15000, false });
			}
		}
	}
}

void SpikeTrap::clean()
{

}



