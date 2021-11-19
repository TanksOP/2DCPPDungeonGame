#include "GameLoop.h"

const int screenWidth = 800;
const int screenHeight = 600;

int score = 0;

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

	// sets all values in keydown to false so no keys are being pressed
	for (int i = 0; i < 256; i++) {
		keyDown[i] = false;
	}

	player = new Player(renderer, screenWidth, screenHeight);
	player->init();

	fontRenderer = std::unique_ptr<FontRenderer>(new FontRenderer(renderer));
	fontRenderer->init();

	tiledMap = std::unique_ptr<TiledMap>(new TiledMap(renderer, "assets/tileMap.png", screenWidth, screenHeight));
	tiledMap->init();

	return 0;
}

bool GameLoop::processInput()
{
	SDL_Event userInput;
	while (SDL_PollEvent(&userInput)) {
		if (userInput.type == SDL_QUIT) {
			return false;
		}
		// checks weather a key is down then makes it equal true
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
	}

	player->processInput(keyDown);

	return true;

}

void GameLoop::update()
{
	if (score < 20000) {
		score++;
	}

	player->update();
	
}

void GameLoop::render()
{
	SDL_RenderClear(renderer);	

	tiledMap->render();
	

	fontRenderer->render("Hello", 600, 10, 100, 200 );
	fontRenderer->render("Hi",600, 100, 100, 100);	
	fontRenderer->render(std::to_string(score), 600, 200, 100, 100); 

	
	player->render();

	SDL_RenderPresent(renderer);

	//SDL_Delay(16);
}

void GameLoop::clean()
{
	tiledMap->clean();
	fontRenderer->clean();
	player->clean();
	
	delete player;
	SDL_DestroyWindow(window);
	SDL_Quit();
}


