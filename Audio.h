#pragma once
#ifndef GUARD_AUDIO_H
#define GUARD_AUDIO_H
#include "variables.h"
#include "SFML\Graphics.hpp"
#include "SFML\Audio.hpp"
#include <memory>

struct Audio{
	std::map<std::string, std::unique_ptr<sf::Music>> musics;
	//std::map<std::string, sf::Sound> sounds;
	//std::map<std::string, sf::Music> musics;

	Audio();


	void Audio::addMusic(const std::string&, std::unique_ptr<sf::Music> );

	sf::Music &Audio::getMusic(std::string);

	void Audio::loadAudio();
};

#endif//GUARD_AUDIO_H
