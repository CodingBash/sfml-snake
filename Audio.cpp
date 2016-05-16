#include "Audio.h"
#include <iostream>
Audio::Audio(){
	loadAudio();
}
void Audio::addMusic(const std::string &key, std::unique_ptr<sf::Music> value){
	musics.insert(std::pair<std::string, std::unique_ptr<sf::Music> >(key, std::move(value)));
}
sf::Music &Audio::getMusic(std::string key){
	return *musics.at(key);
}
void Audio::loadAudio(){
	auto backgroundMusic = std::unique_ptr<sf::Music>(new sf::Music());

	if (!backgroundMusic->openFromFile("backgroundmusic.wav"))
		if(DEBUG)
			std::cerr << "Error opening \"backgroundmusic.wav\"" << std::endl;

	addMusic(std::string("backgroundMusic"), std::move(backgroundMusic));
}
