#include "Menus.h"

Menus::Menus(FontRenderer* _fontRenderer, SDL_Renderer* _renderer, Player* _player, EnemyContoller* _enemyController, SpikeTrap* _spikeTrap)
{
	fontRenderer = _fontRenderer;
	renderer = _renderer;
	player = _player;
	enemyController = _enemyController;
	spikeTrap = _spikeTrap;
}

void Menus::Render(bool& mainMenu, bool& ggScreen, bool& pauseMenu)
{
	

	if (mainMenu) {
		SDL_RenderClear(renderer);
		fontRenderer->render("Game Name", 400, 180, 200, 300);
		fontRenderer->render("Play!", 475, 400, 150, 150);
		//fontRenderer->render("Main Menu:", 32, 5, 75, 80);
		SDL_Rect test = { 475,400,150,150 };
		SDL_SetRenderDrawColor(renderer, 32, 32, 0, 100);
		SDL_RenderFillRect(renderer, &test);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}
	if (ggScreen) {
		SDL_RenderClear(renderer);
		fontRenderer->render("Game Over", 400, 180, 200, 300);
		fontRenderer->render("Back", 475, 400, 150, 150);
		SDL_Rect test = { 475,400,150,150 };
		SDL_SetRenderDrawColor(renderer, 32, 32, 0, 100);
		SDL_RenderFillRect(renderer, &test);
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	}

}

void Menus::Input(bool& mainMenu, bool& ggScreen, bool& pauseMenu, float&level)
{
	SDL_GetMouseState(&mouseX, &mouseY);
	// mouse is over main menu button
	
	if (mainMenu) {
		if (mouseX > 475 && mouseX < 625 && mouseY > 400 && mouseY < 550) {
			mainMenu = false;
			ggScreen = false;
			level = 1;
			enemyController->Reset();
			player->ResetHealth();
			player->ResetPlayerPostition();
			spikeTrap->reset();
			spikeTrap->createSpikes();

		}
	}

	if (ggScreen) {
		if (mouseX > 475 && mouseX < 625 && mouseY > 400 && mouseY < 550) {
			ggScreen = false;
			mainMenu = true;
			
		}
	}
	
}
