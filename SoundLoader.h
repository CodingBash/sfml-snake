#pragma once
#ifndef GUARD_SOUNDLOADER_H
#define GUARD_SOUNDLOADER_H
#include "SFML\Audio.hpp"
#include <map>
#include <vector>
#include <iostream>

class SoundLoader{
public:
	SoundLoader();
	~SoundLoader();
	void loadSounds();
	void loadMusic();
	void playSound(std::string);
	void playMusic(std::string);

	std::map<std::string, sf::SoundBuffer> Sounds;
	//std::map<std::string, sf::Music> Music;
	std::vector<sf::Sound> playingSounds;
};


#endif