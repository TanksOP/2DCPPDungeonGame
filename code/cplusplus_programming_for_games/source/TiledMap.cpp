#include "TiledMap.h"

TiledMap::TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename, int _windowWidth, int _windowHeight)
{
	renderer = sdlRenderer;
	filename = tiledMapFilename;
	windowWidth = _windowWidth;
	windowHeight = _windowHeight;
}

int TiledMap::init()
{
	SDL_Surface* image = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);

	/*std::ifstream fileIn1("Assets/tileMaps/map2.txt"); 
	if (fileIn1.is_open())
	{

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				std::string tile;
				fileIn1 >> tile;
				tileMap[j][i] = std::stoi(tile);
			}
		}
	}
	fileIn1.close();

	std::ifstream fileIn2("Assets/tileMaps/collisionMap1.txt");
	if (fileIn2.is_open())
	{

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				std::string tile;
				fileIn2 >> tile;
				collitionMap[j][i] = std::stoi(tile);
			}
		}
	}
	fileIn2.close();*/
	return 0;

}

bool TiledMap::pathIsClear(float x, float y, float _width, float _height)
{
	
	/*
	Below is a small grid showing where the differrnt collition points are on the player 

	   |   X1  |   X2  |   X3
	---|-------|-------|--------
	Y1 | X1 Y1 | X2 Y1 | X3 Y1 
	---|-------|-------|--------
	Y2 | X1 Y2 | X2 Y2 | X3 Y3
	---|-------|-------|--------
	Y3 | X1 Y3 | X2 Y3 | X3 Y3
	
	*/
	
	
	
	int X1 = (x) / (windowWidth/mapWidth);
	int X2 = (x + 0.5 * _width) / (windowWidth / mapWidth);
	int X3 = (x + _width)/ (windowWidth / mapWidth);
	
	int Y1 = (y ) / (windowHeight / mapHeight);
	int Y2 = (y + 0.5 * _height) / (windowHeight / mapHeight);
	int Y3 = (y + _height) / (windowHeight / mapHeight);


	// right side
	if (collitionMap[X1][Y3] == 1 || collitionMap[X2][Y3] == 1 || collitionMap[X3][Y3] == 1) {
		return false;
	}
	//left side
	if (collitionMap[X1][Y1] == 1 || collitionMap[X2][Y1] == 1 || collitionMap[X3][Y1] == 1) {
		return false;
	}
	//top side
	if (collitionMap[X1][Y1] == 1 || collitionMap[X1][Y2] == 1 || collitionMap[X1][Y3] == 1) {
		return false;
	}
	// bottom side
	if (collitionMap[X3][Y1] == 1 || collitionMap[X3][Y2] == 1 || collitionMap[X3][Y3] == 1) {
		return false;
	}

	return true;
}

void TiledMap::changeMap(int level)
{
	if (level == 1) {	
		
		std::ifstream fileIn1("Assets/tileMaps/map2.txt");
		if (fileIn1.is_open())
		{

			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					std::string tile;
					fileIn1 >> tile;
					tileMap[j][i] = std::stoi(tile);
				}
			}
		}
		fileIn1.close();

		std::ifstream fileIn2("Assets/tileMaps/collisionMap1.txt");
		if (fileIn2.is_open())
		{
			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					std::string tile;
					fileIn2 >> tile;
					collitionMap[j][i] = std::stoi(tile);
				}
			}
		}
		fileIn2.close();
	}

	else if (level == 2) {

		std::ifstream fileIn3("Assets/tileMaps/level2map.txt");
		if (fileIn3.is_open())
		{

			for (int i = 0; i < 20; ++i)
			{
				for (int j = 0; j < 20; ++j)
				{
					std::string tile;
					fileIn3 >> tile;
					tileMap[j][i] = std::stoi(tile);
				}
			}
		}
		fileIn3.close();
	}
}

void TiledMap::update(float& level)
{
	if (level == 1.5f) {
		tileMap[9][2] = 103;
		tileMap[10][2] = 104;
		tileMap[9][3] = 110;
		tileMap[10][3] = 111;

		collitionMap[9][2] = 0;
		collitionMap[10][2] = 0;
		collitionMap[9][3] = 0;
		collitionMap[10][3] = 0;
	}
}


void TiledMap::render()
{
	tileWidth = windowWidth / mapWidth;
	tileHeight = windowHeight / mapHeight;

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {

			SDL_Rect sourceRect;
			
			sourceRect.x = (tileMap[j][i] % 7) * sourceTileSizePx;
			sourceRect.y = (tileMap[j][i] / 7) * sourceTileSizePx;
			sourceRect.h = sourceTileSizePx;
			sourceRect.w = sourceTileSizePx;
			

			SDL_Rect renderRect;
			renderRect.x = j * tileWidth;
			renderRect.y = i * tileHeight;
			renderRect.h = tileHeight;
			renderRect.w = tileWidth;

			SDL_RenderCopy(renderer, texture, &sourceRect, &renderRect);
		}
		
	}
}

void TiledMap::clean()
{

}

