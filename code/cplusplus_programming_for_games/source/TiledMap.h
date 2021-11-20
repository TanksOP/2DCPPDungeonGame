#pragma once
#include <SDL.h>
#include<SDL_image.h>
#include <string>
#include <iostream>
#include <vector>
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

	std::string tileMap[10][10];
	
};



 const int mapWidth = 10;
 const int mapHeight = 10;
const int map[mapHeight][mapWidth] = {
	{29, 22, 22, 22, 22, 22, 22, 22, 22, 26},
	{8, 30, 30, 30, 30, 30, 30, 30, 30, 2},
	{8, 30, 30, 30, 30, 30, 30, 30, 30, 2},
	{8, 30, 30, 30, 30, 30, 30, 30, 30, 2},
	{8, 30, 30, 30, 30, 30, 30, 30, 30, 2},
	{8, 30, 11, 30, 11, 11, 11, 30, 30, 2},
	{8, 30, 30, 30, 30, 30, 30, 30, 30, 2},
	{8, 30, 30, 30, 30, 11, 30, 30, 30, 2},
	{8, 30, 30, 30, 30, 30, 30, 30, 30, 2},
	{19, 36, 36, 36, 36, 36, 36, 36, 36, 13 }
};

