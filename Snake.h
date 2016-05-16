#pragma once
#ifndef GUARD_SNAKE_H
#define GUARD_SNAKE_H

#include "variables.h"
#include "SFML/Graphics.hpp"

struct Snake
{
public:
	Snake::Snake();
	sf::Texture headTexture;
	sf::Texture bodyStraightTexture;
	sf::Texture bodyCornerTexture;
	sf::Texture tailTexture;
	sf::RectangleShape rect;
	sf::Image head;
	bool goingUp;
	bool goingDown;
	bool goingLeft;
	bool goingRight;
	//
	bool realUp;
	bool realDown;
	bool realLeft;
	bool realRight;
	//
	bool secInput;
	bool secUp;
	bool secDown;
	bool secLeft;
	bool secRight;

	int x[1000];
	int y[1000];
	void changeDirections(int dir);
	void input();
	void moveUpdate();
	void checkReals();
	std::vector<sf::RectangleShape> draw();
	std::vector<sf::Sprite> drawImage();
	void checkBoundary();
	bool goingHorizontal();
	bool goingVertical();
};

#endif