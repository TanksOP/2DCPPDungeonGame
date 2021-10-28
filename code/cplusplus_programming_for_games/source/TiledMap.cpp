#include "TiledMap.h"

TiledMap::TiledMap(SDL_Renderer* sdlRenderer, std::string tiledMapFilename)
{
	renderer = sdlRenderer;
	filename = tiledMapFilename;
}

int TiledMap::init()
{
	SDL_Surface* image = IMG_Load(filename.c_str());
	texture = SDL_CreateTextureFromSurface(renderer, image);
	SDL_FreeSurface(image);
	return 0;

}


void TiledMap::render()
{
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

