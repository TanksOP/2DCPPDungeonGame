#include "SoundController.h"

SoundController::SoundController()
{
	if (Mix_OpenAudio(MIX_DEFAULT_FREQUENCY, MIX_DEFAULT_FORMAT, MIX_DEFAULT_CHANNELS, 4098) == -1) {
		printf("Audio mixer could not be made SDL_Error: %s\n", SDL_GetError());
	}

	Mix_Chunk* sound = Mix_LoadWAV("Assets/music/BackgroundTrack.wav");
	soundFiles.push_back(sound);

	sound = Mix_LoadWAV("Assets/music/grunt1-death-pain.wav");
	soundFiles.push_back(sound);

	sound = Mix_LoadWAV("Assets/music/playerhurt2.wav");
	soundFiles.push_back(sound);

	sound = Mix_LoadWAV("Assets/music/shoot.wav");
	soundFiles.push_back(sound);
	

	Mix_Volume(1, MIX_MAX_VOLUME / 10);
	Mix_Volume(2, MIX_MAX_VOLUME / 10);
	Mix_Volume(3, MIX_MAX_VOLUME / 50);
	

}

void SoundController::PlaySound(int sound)
{
	switch (sound)
	{
	case 0:
		Mix_PlayChannel(1, soundFiles[sound], -1);
		break;
	case 1:
	case 2:
		Mix_PlayChannel(2, soundFiles[sound], 0);
	case 3:
		Mix_PlayChannel(3, soundFiles[sound], 0);
	default:
		break;
	}
	
	/*if (sound == 0) {
		Mix_PlayChannel(1, soundFiles[sound], -1);
	}else {
		Mix_PlayChannel(-1, soundFiles[sound], 0);
	}*/
	
}

void SoundController::clean()
{
	for (auto& sound : soundFiles) {
		Mix_FreeChunk(sound);
	}
	Mix_FreeMusic(musicPlayer);
}
