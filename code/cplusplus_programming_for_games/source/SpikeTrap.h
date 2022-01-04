#pragma once
#include <vector>
#include "TiledMap.h"

class SpikeTrap
{


public:
	SpikeTrap(TiledMap* _tileMap, int _windowWidth, int _windowHeight);

	struct Spike {
		
		int x, y, tile;
		float  trapTimer, lastTrap;
		bool animation;
	};

	void init();

	void spikeAnimation();

	void update();

	bool ouchSpikes(float x, float y, float _width, float _height);

	void createSpikes();

	void reset() {
		spikes.clear();
	}

	void clean();


private:
	TiledMap* tiledMap;
	std::vector<Spike> spikes;
	int windowWidth;
	int windowHeight;
};

