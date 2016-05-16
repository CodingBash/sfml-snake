#include "SoundLoader.h"
#include <iostream>
SoundLoader::SoundLoader(){}
SoundLoader::~SoundLoader(){}

void SoundLoader::loadSounds(){
	Sounds["moving"].loadFromFile("movingsfx.wav");
	Sounds["eating"].loadFromFile("eatingsfx.wav");
	Sounds["losing"].loadFromFile("losingsfx.wav");
	Sounds["begin"].loadFromFile("beginsfx.wav");

}
void SoundLoader::loadMusic(){
	//Music["backgroundmusic"].openFromFile("backgroundmusic.wav");
}

void SoundLoader::playSound(std::string soundName){
	if (playingSounds.size() == 0)
	{
		playingSounds.push_back(sf::Sound());
		playingSounds.at(0).setBuffer(Sounds[soundName]);
		if(soundName == "moving")
			playingSounds.at(0).setVolume(15);
		playingSounds.at(0).play();
	}
	else
	{
		int location = -1;
		for (int i = 0; i < playingSounds.size(); i++)
		{
			if (playingSounds.at(i).getStatus() != sf::Sound::Playing && location == -1)
			{
				location = i;
			}
		}

		if (location != -1)
		{
			playingSounds.at(location).setBuffer(Sounds[soundName]);
			if(soundName == "moving")
				playingSounds.at(location).setVolume(15);
			playingSounds.at(location).play();
		}
		else
		{
			playingSounds.push_back(sf::Sound());
			playingSounds.at(playingSounds.size()-1).setBuffer(Sounds[soundName]);
			if(soundName == "moving")
				playingSounds.at(playingSounds.size() - 1).setVolume(15);
			playingSounds.at(playingSounds.size() - 1).play();
		}

	}
}
