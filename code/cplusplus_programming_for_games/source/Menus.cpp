#include "Menus.h"

Menus::Menus(FontRenderer* _fontRenderer, SDL_Renderer* _renderer, Player* _player, EnemyContoller* _enemyController, SpikeTrap* _spikeTrap, Particles* _particles, BulletManager* _bulletManager, TiledMap* _tileMap)
{
	fontRenderer = _fontRenderer;
	renderer = _renderer;
	player = _player;
	enemyController = _enemyController;
	spikeTrap = _spikeTrap;
	particles = _particles;
	bulletManager = _bulletManager;
	tileMap = _tileMap;
}

void Menus::Render(bool& mainMenu, bool& ggScreen, bool& pauseMenu,bool& winScreen)
{
	
	// depending on what menu is active will chaneg what is being displayed
	if (mainMenu) {
		SDL_RenderClear(renderer);
		fontRenderer->render("Danger Dungeon", 400, 180, 200, 300);
		fontRenderer->render("Play!", 475, 400, 150, 150);

	}
	else if (pauseMenu) {
		//SDL_RenderClear(renderer);
		SDL_Rect test = { 0,0,1200,900 };
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 1);
		SDL_RenderFillRect(renderer, &test);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		fontRenderer->render("Paused", 400, 180, 200, 300);
		fontRenderer->render("Resume", 475, 400, 150, 150);
		fontRenderer->render("Main Menu", 450, 550, 150, 200);
	
	}
	else if (winScreen) {
		SDL_RenderClear(renderer);
		fontRenderer->render("You Won", 400, 180, 200, 300);
		fontRenderer->render("Back", 475, 400, 150, 150);

	}
	else if (ggScreen) {
		
		string percentage = std::to_string((50-enemyController->getEnemiesleft())*1000/500);
		SDL_RenderClear(renderer);
		fontRenderer->render("Game Over", 400, 100, 200, 300);
		fontRenderer->render("You completed" , 300, 300, 100, 300);
		fontRenderer->render(percentage +"%", 610, 300, 100, 50);
		
		fontRenderer->render("Back", 475, 400, 150, 150);

	}

}

void Menus::Input(bool& mainMenu, bool& ggScreen, bool& pauseMenu, float&level, bool& winScreen)
{
	SDL_GetMouseState(&mouseX, &mouseY);
	// hget the mouse position and and creates buttons based on what screen the user is currently on
	
	if (mainMenu) {
		// when the start button is pressed the game restes all of its values so that stuff is not allready spawned in the middle of the screen.
		if (mouseX > 475 && mouseX < 625 && mouseY > 400 && mouseY < 550) {
			mainMenu = false;
			ggScreen = false;
			level = 1;
			enemyController->Reset();
			player->ResetHealth();
			player->ResetPlayerPostition();
			spikeTrap->reset();
			spikeTrap->createSpikes();
			bulletManager->Reset();
			particles->Reset();
			// reset the door and colltion for the door
			tileMap->Reset();

		}
	}
	else if (pauseMenu) {
		if (mouseX > 450 && mouseX < 650 && mouseY > 550 && mouseY < 700) {
			ggScreen = false;
			winScreen = false;
			mainMenu = true;
			pauseMenu = false;

		}
		if (mouseX > 475 && mouseX < 625 && mouseY > 400 && mouseY < 550) {
			ggScreen = false;
			winScreen = false;
			mainMenu = false;
			pauseMenu = false;

		}
	}

	else if (ggScreen) {
		if (mouseX > 475 && mouseX < 625 && mouseY > 400 && mouseY < 550) {
			ggScreen = false;
			mainMenu = true;
			winScreen = false;
			
		}
	}
	else if (winScreen) {
		if (mouseX > 475 && mouseX < 625 && mouseY > 400 && mouseY < 550) {
			
			ggScreen = false;
			winScreen = false;
			mainMenu = true;	

		}
	}
	
}
