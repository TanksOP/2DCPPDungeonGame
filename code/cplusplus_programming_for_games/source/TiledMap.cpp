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

	std::ifstream fileIn("Assets/tileMaps/map2.txt"); 
	if (fileIn.is_open())
	{

		for (int i = 0; i < 20; ++i)
		{
			for (int j = 0; j < 20; ++j)
			{
				std::string tile;
				fileIn >> tile;
				tileMap[j][i] = std::stoi(tile);
			}
		}
	}

	fileIn.close();

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

	
	//// right side
	//if (tileMap[X3][Y1] == 56 || tileMap[X3][Y2] == 56 ||  tileMap[X3][Y3] == 56) {
	//	return false;
	//}
	////left side
	//if (tileMap[X1][Y1] == 56 || tileMap[X1][Y2] == 56 || tileMap[X1][Y3] == 56) {
	//	return false;
	//}
	////top side
	//if (tileMap[X1][Y1] == 56 || tileMap[X2][Y1] == 56 || tileMap[X3][Y1] == 56) {
	//	return false;
	//}
	//// bottom side
	//if (tileMap[X1][Y3] == 56 || tileMap[X2][Y3] == 56 || tileMap[X3][Y3] == 56) {
	//	return false;
	//}

	// right side
	if (MAP_DATA[Y3][X1] == 1 || MAP_DATA[Y3][X2] == 1 || MAP_DATA[Y3][X3] == 1) {
		return false;
	}
	//left side
	if (MAP_DATA[Y1][X1] == 1 || MAP_DATA[Y1][X2] == 1 || MAP_DATA[Y1][X3] == 1) {
		return false;
	}
	//top side
	if (MAP_DATA[Y1][X1] == 1 || MAP_DATA[Y2][X1] == 1 || MAP_DATA[Y3][X1] == 1) {
		return false;
	}
	// bottom side
	if (MAP_DATA[Y1][X3] == 1 || MAP_DATA[Y2][X3] == 1 || MAP_DATA[Y3][X3] == 1) {
		return false;
	}

	return true;
}

void TiledMap::update()
{
	
	tileMap[10][10] += 1;

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

