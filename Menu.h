#ifndef GUARD_MENU_H
#define GUARD_MENU_H

#include "SFML/Graphics.hpp"
#include "variables.h"
#define MAX_NUMBER_OF_ITEMS 3
class Menu
{
public:
	Menu(float width, float height);
	~Menu();

	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();

private:
		int selectedItemIndex;
		sf::Font font;
		sf::Text menu[MAX_NUMBER_OF_ITEMS];


};

#endif
