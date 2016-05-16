#pragma once
#ifndef GUARD_SFML_SNAKE
#define GUARD_SFML_SNAKE

#include "SFML/Audio.hpp"
#include "SFML/Graphics.hpp"
#include "Snake.h"
#include "Apple.h"
#include "SoundLoader.h"
//#include "Audio.h"
#include <iostream>

class SFML_Snake{
public:
	SFML_Snake();
	void run();
private:
	void checkApple(Snake&, Apple&);
	std::vector<sf::RectangleShape> loadGrid();
private:
	bool processEvents();
	void update();
	void render(std::vector<sf::RectangleShape>&);

public:
	sf::RenderWindow window;
	sf::Text textCount;
	SoundLoader sounds;
	Snake snake;
	Apple apple;
};

int main(){
	SFML_Snake start;
	start.run();
}
#endif