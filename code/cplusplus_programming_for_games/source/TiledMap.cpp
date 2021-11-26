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

	std::ifstream fileIn("Assets/tileMaps/map1.txt"); 
	if (fileIn.is_open())
	{

		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
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

bool TiledMap::pathIsClear(float x, float y, float playerWidth, float playerHeight)
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
	int X2 = (x + 0.5 * playerWidth) / (windowWidth / mapWidth);
	int X3 = (x + playerWidth)/ (windowWidth / mapWidth);
	
	int Y1 = (y ) / (windowHeight / mapHeight);
	int Y2 = (y + 0.5 * playerHeight) / (windowHeight / mapHeight);
	int Y3 = (y + playerHeight) / (windowHeight / mapHeight);

	
	// right side
	if (tileMap[X3][Y1] == 11 || tileMap[X3][Y2] == 11 ||  tileMap[X3][Y3] == 11) {
		return false;
	}
	//left side
	if (tileMap[X1][Y1] == 11 || tileMap[X1][Y2] == 11 || tileMap[X1][Y3] == 11) {
		return false;
	}
	//top side
	if (tileMap[X1][Y1] == 11 || tileMap[X2][Y1] == 11 || tileMap[X3][Y1] == 11) {
		return false;
	}
	// bottom side
	if (tileMap[X1][Y3] == 11 || tileMap[X2][Y3] == 11 || tileMap[X3][Y3] == 11) {
		return false;
	}

	return true;
}

void TiledMap::update()
{

}


void TiledMap::render()
{
	tileWidth = windowWidth / mapWidth;
	tileHeight = windowHeight / mapHeight;

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {

			SDL_Rect sourceRect;
			
			sourceRect.x = (tileMap[j][i] % 6) * sourceTileSizePx;
			sourceRect.y = (tileMap[j][i] / 6) * sourceTileSizePx;
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

