#pragma once
#include <SDL.h>
#include<SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
#include <array>
#include <sstream>
#include <fstream>

class TiledMap
{
public: 
	TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename, int _windowWidth, int _windowHeight);

	int init();

	bool pathIsClear(float x, float y, float playerWidth, float playerHeight);

	void update();

	void render();

	void clean();

private:
	int windowWidth = 0;
	int windowHeight = 0;
	const int sourceTileSizePx = 70;

	int tileWidth = 100; // change this to screen width 
	int tileHeight = 100; // chaneg this to screen width

	std::string filename;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	int locationX = 0;
	int locationY = 0;

	const int mapWidth = 10;
	const int mapHeight = 10;

	 
	std::array< std::array<int, 10>, 10 > tileMap;
};



