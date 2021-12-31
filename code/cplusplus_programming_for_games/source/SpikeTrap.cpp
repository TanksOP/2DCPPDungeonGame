#include "SpikeTrap.h"

SpikeTrap::SpikeTrap(TiledMap* _tileMap, int _windowWidth, int _windowHeight)
{
	tiledMap = _tileMap;
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
}

void SpikeTrap::init()
{
	//78
	for (int i = 0; i < 20; ++i)
	{
		for (int j = 0; j < 20; ++j)
		{
			if (tiledMap->tileMap[j][i] == 78) {
				spikes.push_back(Spike{ j, i, 78, 10000, -15000, false });
			}
		}
	}

}

void SpikeTrap::spikeAnimation()
{
	for (auto& s : spikes) {

		if (SDL_GetTicks() - s.lastTrap > 3000) {
			s.tile = 78;
			s.animation = false;
		}
		else if (SDL_GetTicks() - s.lastTrap > 2100) {
			s.tile = 81;
		}
		else if (SDL_GetTicks() - s.lastTrap > 2000) {
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

bool SpikeTrap::ouchSpikes(float x, float y, float _width, float _height)
{
	int xx = x / windowWidth * 20;
	int yy = y/windowHeight * 20;
	//std::cout << "x" << xx<<std::endl;

	if (tiledMap->tileMap[xx][yy] == 80 || tiledMap->tileMap[xx][yy] == 80) {

		for (auto& s : spikes) {
			if (s.x == xx && s.y == yy) {
				s.tile = 78;
				s.animation = false;
				//tiledMap->tileMap[xx][yy] = 78;
			}
		}
		
		return true;
	}

	// same system as is in the tile map cpp file.

	//int X1 = (x) / (windowWidth / 20);
	//int X2 = (x + 0.5 * _width) / (windowWidth / 20);
	//int X3 = (x + _width) / (windowWidth / 20);

	//int Y1 = (y) / (windowHeight / 20);
	//int Y2 = (y + 0.5 * _height) / (windowHeight / 20);
	//int Y3 = (y + _height) / (windowHeight / 20);

	//if (tiledMap->tileMap[Y3][X1] == 80 || tiledMap->tileMap[Y3][X2] == 80 || tiledMap->tileMap[Y3][X3] == 80 ||
	//	tiledMap->tileMap[Y3][X1] == 81 || tiledMap->tileMap[Y3][X2] == 81 || tiledMap->tileMap[Y3][X3] == 81) {
	//	return true;
	//}
	////left side
	//if (tiledMap->tileMap[Y1][X1] == 80 || tiledMap->tileMap[Y1][X2] == 80 || tiledMap->tileMap[Y1][X3] == 80 ||
	//	tiledMap->tileMap[Y1][X1] == 81 || tiledMap->tileMap[Y1][X2] == 81 || tiledMap->tileMap[Y1][X3] == 81) {
	//	return true;
	//}
	////top side
	//if (tiledMap->tileMap[Y1][X1] == 80 || tiledMap->tileMap[Y2][X1] == 80 || tiledMap->tileMap[Y3][X1] == 80 ||
	//	tiledMap->tileMap[Y1][X1] == 81 || tiledMap->tileMap[Y2][X1] == 81 || tiledMap->tileMap[Y3][X1] == 81) {
	//	return true;
	//}
	//// bottom side
	//if (tiledMap->tileMap[Y1][X3] == 80 || tiledMap->tileMap[Y2][X3] == 80 || tiledMap->tileMap[Y3][X3] == 80 ||
	//	tiledMap->tileMap[Y1][X3] == 81 || tiledMap->tileMap[Y2][X3] == 81 || tiledMap->tileMap[Y3][X3] == 81) {
	//	return true;
	//}

	return false;
}
