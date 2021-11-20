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
	int X1 = (x) / 80;
	int X2 = (x + 0.5 * playerWidth) / 80;
	int X3 = (x + playerWidth)/80;
	
	int Y1 = (y ) / 60;
	int Y2 = (y + 0.5 * playerHeight) / 60;
	int Y3 = (y + playerHeight) / 60;
	
	// right side
	if (map[Y1][X3] == 11 || map[Y2][X3] == 11 ||  map[Y3][X3] == 11) {
		return false;
	}
	//left side
	if (map[Y1][X1] == 11 || map[Y2][X1] == 11 || map[Y3][X1] == 11) {
		return false;
	}
	//top side
	if (map[Y1][X1] == 11 || map[Y1][X2] == 11 || map[Y1][X3] == 11) {
		return false;
	}
	// bottom side
	if (map[Y3][X1] == 11 || map[Y3][X2] == 11 || map[Y3][X3] == 11) {
		return false;
	}
	

	return true;
}

void TiledMap::update()
{
	std::ifstream fileIn("textFile/text.txt");
	if (fileIn.is_open())
	{
		for (int i = 0; i < 10; ++i)
		{
			for (int j = 0; j < 10; ++j)
				fileIn >> tileMap[j][i];
		}
	}
	fileIn.close();
}


void TiledMap::render()
{
	tileWidth = windowWidth / mapWidth;
	tileHeight = windowHeight / mapHeight;

	for (int i = 0; i < mapHeight; i++) {
		for (int j = 0; j < mapWidth; j++) {

			SDL_Rect sourceRect;
			sourceRect.x = (map[i][j] % 6) * sourceTileSizePx;
			sourceRect.y = (map[i][j] / 6) * sourceTileSizePx;
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

