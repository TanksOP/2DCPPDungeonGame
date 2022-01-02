#include "Particles.h"

Particles::Particles(SDL_Renderer* _renderer)
{
	renderer = _renderer;
	particleTexture = NULL;
}

void Particles::init()
{
	SDL_Surface* surface = IMG_Load("Assets/red.png");
	particleTexture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);


	//lastParticleSpawn = 0;
	//nextParticleSpawn = 0;
}

void Particles::createBloodSplatter(float x, float y)
{
	for (int i = 0; i < 20;i++) {
		particlePositions.push_back(Particle{ x, y, float(rand() % 6 + 2), float(rand() % 6 + 2), -0.1f, float(rand() % 201 - 100) / 3300 , 0 });
	}
	
	
}

void Particles::Update()
{
	 /*creaete anew particle*/
	if (SDL_GetTicks() - lastParticleSpawn >= nextParticleSpawn) {
		lastParticleSpawn = SDL_GetTicks();
		nextParticleSpawn = emissionRate + (rand() % emmissionRange);

		// x, y, w, h, vely, velx
		particlePositions.push_back(Particle{ 200.f, 200.f, float(rand() % 6 + 2), float(rand() % 6 + 2), -0.1f, float(rand() % 201 - 100) / 3300 , 0 });
		
	}
	for (auto& particle : particlePositions) {

		//particle.VelX = 0.03;
		//std::cout << << std::endl;

		particle.aliveTime += 1;
		particle.VelY += Gravity;
		particle.x += particle.VelX;
		particle.y += particle.VelY;
		
	}

	auto remove = remove_if(particlePositions.begin(), particlePositions.end(),
		[](const auto& particle) {
			return particle.aliveTime > 2500; });

	particlePositions.erase(remove, particlePositions.end()); // removes etra spce still in the vector
	

}

void Particles::Render()
{
	for (auto& particle : particlePositions) {
		SDL_Rect dest = { particle.x, particle.y, particle.w, particle.h };
		SDL_RenderCopy(renderer, particleTexture, 0, &dest);
	}
}

void Particles::clean()
{
	SDL_DestroyTexture(particleTexture);
}


