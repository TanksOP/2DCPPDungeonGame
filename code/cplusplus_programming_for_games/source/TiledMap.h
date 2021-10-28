#pragma once
#include <SDL.h>
#include<SDL_image.h>
#include <string>
#include <iostream>

class TiledMap
{
public: 
	TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename);

	int init();
	void clean();
	void render();

private:
	const int sourceTileSizePx = 70;
	const int tileWidth = 180; // change this to screen width 
	const int tileHeight = 180; // chaneg this to screen width

	std::string filename;
	SDL_Renderer* renderer;
	SDL_Texture* texture;
};

const int mapWidth = 4;
const int mapHeight = 4;
const int map[mapHeight][mapWidth] = {
	{1, 1, 1, 1},
	{7, 7, 7, 7},
	{13, 13, 13, 13},
	{0, 0, 0, 0}
};

