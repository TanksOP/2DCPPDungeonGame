#pragma once
#include "FontRenderer.h"
#include"Player.h"
#include"EnemyContoller.h"
#include "SpikeTrap.h"
class Menus
{
public:

	Menus(FontRenderer* _fontRenderer, SDL_Renderer* _renderer, Player* _player, EnemyContoller* _enemyController, SpikeTrap* _spikeTrap);

	void Render(bool &mainMenu, bool &ggScreen, bool &pauseMenu);

	void Input(bool& mainMenu, bool& ggScreen, bool& pauseMenu, float& level);


private:
	FontRenderer* fontRenderer;
	SDL_Renderer* renderer;
	Player* player;
	EnemyContoller* enemyController;
	SpikeTrap* spikeTrap;

	int mouseX, mouseY;
	

};

