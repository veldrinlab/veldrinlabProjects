/**
 * File contains declaration of AudioManager class.
 * @file    AudioManager.hpp
 * @author  Szymon Jab�o�ski
 * @date    2010-12-26
 * @version 1.0
 */

#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SDL_mixer.h>

namespace engine
{

/**
 * Class represents Game Engine Audio Manager which is used to load music file and control it. User can play,
 * pause and resume current loaded music files.
 */
class AudioManager
{
private:
	Mix_Music* music;

public:
	AudioManager();
	~AudioManager();

	void loadMusic(const char* musicFileName);
	void playMusic();
	void pauseMusic();
	void resumeMusic();
};

}
#endif
