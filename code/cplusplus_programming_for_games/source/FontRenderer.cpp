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
	font = TTF_OpenFont("assets/fonts/orangeJuice.ttf",200);
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

	// creates an image representing the text inputed 
	SDL_Surface* textImage = TTF_RenderText_Solid(font, text.c_str(), colour);
	//now to render it
	SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, textImage);
	SDL_RenderCopy(renderer, texture, NULL, NULL);

	// now we have used the texture and image we can get rid of them
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(textImage);
}

void FontRenderer::clean()
{
	//free all reasiurces use to render
	TTF_CloseFont(font);
}
