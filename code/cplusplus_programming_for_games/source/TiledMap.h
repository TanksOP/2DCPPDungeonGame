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
	 const int MAP_DATA[20][20] = {
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1 },
		{ 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1 },
		};

	TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename, int _windowWidth, int _windowHeight);

	int init();

	// player
	bool pathIsClear(float x, float y, float _width, float _height);

	void update(float &level);

	void render();

	void clean();

	std::array< std::array<int, 20>, 20 > tileMap;

	int collitionMap [20][20];
	
private:
	
	
	int windowWidth = 0;
	int windowHeight = 0;
	const int sourceTileSizePx = 16;

	int tileWidth = 100; // change this to screen width 
	int tileHeight = 100; // chaneg this to screen width

	std::string filename;
	SDL_Renderer* renderer;
	SDL_Texture* texture;

	int locationX = 0;
	int locationY = 0;

	int mapWidth = 20;
	int mapHeight = 20;	 
	

};



