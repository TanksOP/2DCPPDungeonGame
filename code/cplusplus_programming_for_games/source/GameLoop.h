#pragma once

#include <iostream>
#include <string>
#include <vector> 
#define SDL_MAIN_HANDLED
#include <SDL.h>
#include "Player.h"
#include "FontRenderer.h"
#include "TiledMap.h"
#include "BulletManager.h"
#include "EnemyContoller.h"
#include "SoundController.h"
#include "SpikeTrap.h"
#include "Particles.h"
#include "Menus.h"



class GameLoop
{
public:

	int init();

	bool processInput();

	void update();

	void render();	

	void clean();

private:
	SDL_Window* window = nullptr;
	SDL_Surface* screenSurface = nullptr;
	SDL_Renderer* renderer = nullptr;

	// creates a why to turn on and off key presses
	bool keyDown[512];
	bool MouseLeftButton = false;

	bool mainMenu = true, ggScreen = false, pauseMenu = false;


	std::unique_ptr<FontRenderer> fontRenderer;
	std::unique_ptr<TiledMap> tiledMap;

	BulletManager* bm = nullptr;
	EnemyContoller* ec = nullptr;
	Player* player = nullptr;
	SoundController* soundController;
	SpikeTrap* spikeTrap;
	Particles* particle;
	Menus* menus;

	int score = 0;
	int enemiesLeft;
	float level = 1;
	
	
};

