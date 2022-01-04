#pragma once
#include "FontRenderer.h"
#include"Player.h"
#include"EnemyContoller.h"
#include "SpikeTrap.h"
class Menus
{
public:

	Menus(FontRenderer* _fontRenderer, SDL_Renderer* _renderer, Player* _player, EnemyContoller* _enemyController, SpikeTrap* _spikeTrap, Particles* _particles, BulletManager* _bulletManager);

	void Render(bool &mainMenu, bool &ggScreen, bool &pauseMenu, bool& winScreen);

	void Input(bool& mainMenu, bool& ggScreen, bool& pauseMenu, float& level, bool& winScreen);


private:
	FontRenderer* fontRenderer;
	SDL_Renderer* renderer;
	Player* player;
	EnemyContoller* enemyController;
	SpikeTrap* spikeTrap;
	Particles* particles;
	BulletManager* bulletManager;

	int mouseX, mouseY;
	

};

