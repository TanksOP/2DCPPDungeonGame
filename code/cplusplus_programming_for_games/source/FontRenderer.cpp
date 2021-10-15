#include "FontRenderer.h"

FontRenderer::FontRenderer(SDL_Renderer* sdlRenderer)
{
	renderer = sdlRenderer;
}

void FontRenderer::init()
{
	int init = TTF_Init();
	if (init != 0)
	{
		std::cout << SDL_GetError() << std::endl;
	}
	font = TTF_OpenFont("assets/fonts/orangeJuice.ttf",12);
	if (font == NULL)
	{
		std::cout << SDL_GetError() << std::endl;
	}
}

void FontRenderer::render(std::string text)
{
	SDL_Color colour = SDL_Colour();
	colour.r = 120;
	colour.g = 0;
	colour.b = 60;
	colour.a = 255;
}

void FontRenderer::clean()
{
	//free all reasiurces use to render
	TTF_CloseFont(font);
}
