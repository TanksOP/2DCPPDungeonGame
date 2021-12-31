#include "GameLoop.h"

const int screenWidth = 1200;
const int screenHeight = 900;



SDL_Window* window = nullptr;
SDL_Surface* screenSurface = nullptr;

int main()
{
	GameLoop gameLoop = GameLoop();
	if (gameLoop.init() < 0) return 1;

	while (gameLoop.processInput())
	{
		gameLoop.update();
		gameLoop.render();
	}

	gameLoop.clean();
	return 0;
}

int GameLoop::init()
{
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "could not initialize SDL2!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	window = SDL_CreateWindow(
		"hello_sdl2",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		screenWidth, screenHeight,
		SDL_WINDOW_SHOWN
	);
	if (window == NULL) { // this si called if the widow could not be created
		std::cout << "could not initialise window!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return 1;
	}
	screenSurface = SDL_GetWindowSurface(window);

	

	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == NULL)
	{
		std::cout << "could not initialise renderer!" << std::endl;
		std::cout << SDL_GetError() << std::endl;
		return -1;
	}

	// sets the game to full screen
	//SDL_SetWindowFullscreen(window, SDL_WINDOW_FULLSCREEN);

	// sets all values in keydown to false so no keys are being pressed
	for (int i = 0; i < 256; i++) {
		keyDown[i] = false;
	}

	soundController = new SoundController();
	soundController->PlaySound(Sounds::BACKGROUND);	
	
	fontRenderer = std::unique_ptr<FontRenderer>(new FontRenderer(renderer));
	fontRenderer->init();

	tiledMap = std::unique_ptr<TiledMap>(new TiledMap(renderer, "Assets/DungeonTileset/DungeonTilesetII.png", screenWidth, screenHeight));
	tiledMap->init();

	spikeTrap = new SpikeTrap(tiledMap.get(), screenWidth ,screenHeight);
	spikeTrap->init();

	player = new Player(renderer, tiledMap.get(), screenWidth, screenHeight);
	player->init();

	bm = new BulletManager(renderer, player, tiledMap.get(), soundController);
	bm->init();

	ec = new EnemyContoller(renderer, bm, player, tiledMap.get(), soundController, spikeTrap);
	ec->init();

	



	return 0;
}

bool GameLoop::processInput()
{

	
	SDL_Event userInput;
	while (SDL_PollEvent(&userInput)) {
		if (userInput.type == SDL_QUIT) {
			return false;
		}
		// checks whhhheather a key is down then makes it equal true
		if (userInput.type == SDL_KEYDOWN) {
			if (userInput.key.keysym.scancode < 512) {
				keyDown[userInput.key.keysym.scancode] = true;
			}

		}
		// checks weather a key is up then makes it equal false
		else if (userInput.type == SDL_KEYUP) {
			if (userInput.key.keysym.scancode < 512) {
				keyDown[userInput.key.keysym.scancode] = false;
			}
		}

		else if (userInput.type == SDL_MOUSEBUTTONDOWN) {
			if (userInput.button.button == SDL_BUTTON_LEFT) {
				MouseLeftButton = true;
				//bm->CreateBullets(MouseLeftButton, userInput.motion.x, userInput.motion.y);
			}
		}
		else if (userInput.type == SDL_MOUSEBUTTONUP) {
			if (userInput.button.button == SDL_BUTTON_LEFT) {
				MouseLeftButton = false;
				//bm->CreateBullets(MouseLeftButton, userInput.motion.x, userInput.motion.y);
			}
		}
	}

	player->processInput(keyDown);
	

	bm->CreateBullets(MouseLeftButton);
	
	

	return true;

}

void GameLoop::update()
{
	//if (score < 200000) {
	//	score++;
	//}

	// call music here
	
	spikeTrap->update();
	tiledMap->update();
	player->update();
	bm->update();
	ec->update();
	
}

void GameLoop::render()
{
	SDL_RenderClear(renderer);	

	tiledMap->render();
	bm->render();
	ec->render();
	
	score = ec->getScore();
	enemiesLeft = ec->getEnemiesleft();
	fontRenderer->render("Lives:", 32, 5, 75, 80 );
	fontRenderer->render("Score:", 325, 5, 75, 75);		
	fontRenderer->render(std::to_string(score), 420, 15, 60, 60); 
	fontRenderer->render("Enemies left:", 785, 5, 75, 140);
	fontRenderer->render(std::to_string(enemiesLeft), 945, 15, 60, 60);

	
	player->render();

	SDL_RenderPresent(renderer);

	//SDL_Delay(16);
}

void GameLoop::clean()
{
	soundController->clean();
	tiledMap->clean();
	fontRenderer->clean();
	player->clean();
	bm->clean();
	ec->clean();
	
	delete player;
	SDL_DestroyWindow(window);
	SDL_Quit();
}


