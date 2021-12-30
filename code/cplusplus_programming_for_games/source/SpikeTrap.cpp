#include "SpikeTrap.h"

SpikeTrap::SpikeTrap(TiledMap* _tileMap)
{
	tiledMap = _tileMap;
}

void SpikeTrap::init()
{
	//78
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (tiledMap->tileMap[j][i] == 78) {
				spikes.push_back(Spike{ j, i, 78, 20000, 0, false });
			}
		}
	}

}

void SpikeTrap::spikeAnimation()
{
	for (auto& s : spikes) {

		if (SDL_GetTicks() - s.lastTrap > 10000) {
			s.tile = 78;
			s.animation = false;
		}
		else if (SDL_GetTicks() - s.lastTrap > 9000) {
			s.tile = 80;
		}
		else if (SDL_GetTicks() - s.lastTrap > 6000) {
			s.tile = 80;
		}
		else if (SDL_GetTicks() - s.lastTrap > -1) {
			s.tile = 79;
		}
		
	}
}

void SpikeTrap::update()
{
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
