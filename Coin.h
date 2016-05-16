#pragma once
#ifndef GUARD_COIN_H
#define GUARD_COIN_H
#include "variables.h"
#include "SFML\Graphics.hpp"
struct Coin{
public:
	sf::Sprite playerImage;
	sf::Texture texture;
	sf::RectangleShape rect;
	int coin_x;
	int coin_y;

	Coin::Coin(int x, int y);
	void locateCoin();
	sf::RectangleShape draw();
	sf::Sprite& drawImage();
	int x();
	int y();
	sf::Vector2f pos();
};
#endif