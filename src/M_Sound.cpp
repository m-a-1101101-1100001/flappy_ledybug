#include "M_Sound.h"
void Sound::load(const char *file){
	FileIO fileIO(file);
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 1024) == -1)
		throw "AUDIO_INIT_ERROR";
	se = Mix_LoadWAV(fileIO.readAssets());
}

void Sound::play(int num){
	Mix_PlayChannel(num, se, 0);
}