/**
 * File contains definition of SceneManager class.
 * @file    SceneManager.cpp
 * @author  Szymon Jab³oñski
 * @date    2010-10-29
 * @version 1.0
 */

#include "AudioManager.hpp"

namespace Engine
{
/**
 * Default constrcutor, initialize audio context.
 */
AudioManager::AudioManager()
{
	if(Mix_OpenAudio(22050 * 2, AUDIO_S16, 2, 4096) == -1)
	{
		printf("Audio manager initialize error!\n");
        exit(0);
	}
}

/**
 * Default destructor, free allocated memory.
 */
AudioManager::~AudioManager()
{
	Mix_FreeMusic(music);
    Mix_CloseAudio();
}

/**
 * Method is used to load music from file.
 * @param	musicFileName is music resource path
 */
void AudioManager::loadMusic(const char* musicFileName)
{
	music = Mix_LoadMUS(musicFileName);

	if(!music)
	{
		printf("AudioManager: music file loading error!", Mix_GetError());
		exit(0);
	}
}

/**
 * Method is used to play current loaded music sample.
 */
void AudioManager::playMusic()
{
	Mix_PlayMusic(music,-1);
}

/**
 * Method is used to stop playing current loaded music sample.
 */
void AudioManager::pauseMusic()
{
	Mix_PauseMusic(); 
}

/**
 * Method is used to resume current loaded music sample.
 */
void AudioManager::resumeMusic()
{
	if(Mix_PausedMusic() == 1)
		Mix_ResumeMusic();
}

}