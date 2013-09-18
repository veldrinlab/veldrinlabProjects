/**
 * File contains declaration of AudioManager class.
 * @file    AudioManager.hpp
 * @author  Szymon Jab³oñski
 * @date    2010-12-26
 * @version 1.0
 */

#ifndef AUDIOMANAGER_HPP
#define AUDIOMANAGER_HPP

#include <SDL/SDL_mixer.h>
#include <vector>

namespace Engine
{

/**
 * Class represents Game Engine Audio Manager which is used to load music file and control it. User can play,
 * pause and resume current loaded music files.
 */
class AudioManager
{
private:
	Mix_Music* music;
	std::vector<Mix_Chunk*> effects;

public:
	AudioManager();
	~AudioManager();

	void loadMusic(const char* musicFileName);
	void loadEffect(const char* effectFileName);
	void playMusic();
	void pauseMusic();
	void resumeMusic();

	void playEffect(const int id);
};

}
#endif
