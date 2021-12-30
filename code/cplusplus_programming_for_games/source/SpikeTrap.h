#pragma once
#include <vector>
#include "TiledMap.h"

class SpikeTrap
{
public:
	SpikeTrap(TiledMap* _tileMap);

	struct Spike {
		
		int x, y, tile;
		float  trapTimer, lastTrap;
		bool animation;
	};

	void init();

	void spikeAnimation();

	void update();


private:
	TiledMap* tiledMap;
	std::vector<Spike> spikes;
};

