#pragma once
#ifndef GUARD_APPLE_H
#define GUARD_APPLE_H
#include "variables.h"
#include "SFML\Graphics.hpp"
struct Apple{
public:
	sf::Sprite playerImage;
	sf::Texture texture;
	sf::RectangleShape rect;
	int apple_x;
	int apple_y;

	Apple::Apple(int x, int y);
	void locateApple();
	sf::RectangleShape draw();
	sf::Sprite& drawImage();
	int x();
	int y();
	sf::Vector2f pos();
};
#endif