#pragma once
#include <SDL.h>
#include<SDL_image.h>
#include <vector>
#include<iostream>


using namespace std;

class Particles {
public:
	struct Particle {
		float x, y, w, h, VelY, VelX, aliveTime;
	};
	
	Particles(SDL_Renderer* _renderer);

	void init();

	void createBloodSplatter(float x, float y);

	void Update();

	void Render();

	void clean();

private:
	SDL_Texture* particleTexture;
	SDL_Renderer* renderer;
	std::vector<Particle>particlePositions;


	int emissionRate = 100;
	int emmissionRange = 90;

	
	float Gravity = 0.0001;

	int lastParticleSpawn = 0;
	int nextParticleSpawn = 0;

};