#pragma once
#include <SDL_mixer.h>
#include <sstream>
#include <vector>



enum Sounds
{
	BACKGROUND = 0,
	GRUNT1,
	GRUNT2,
	SHOOT,
	TOTAL_SOUNDS,
};

class SoundController {
public:
	SoundController();

	void PlaySound(int sound);

	void clean();

private:
	Mix_Music* musicPlayer;
	std::vector<Mix_Chunk*> soundFiles;

};