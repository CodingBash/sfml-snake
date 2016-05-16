#include "Apple.h"
#include "SFML\Graphics.hpp"
#include <iostream>
/*Apple shape declaration*/


/*Apple constructor: int coordinate for position*/
Apple::Apple(int x, int y){
	this->apple_x = x;
	this->apple_y = y;
	rect.setPosition(this->apple_x, this->apple_y);
	rect.setSize( sf::Vector2f(dotSize, dotSize ));
	rect.setFillColor(sf::Color::Magenta);
	rect.setOrigin(dotSize / 2.f, dotSize / 2.f);
	if(!texture.loadFromFile("Apple.png"))
		if(DEBUG)
			std::cout<<"Error loading apple.png yo"<<std::endl;
	playerImage.setTexture(texture);
}

/*Specific call update method*/
void Apple::locateApple(){
	this->apple_x = std::rand() % 10 * rand_pos / 10 * dotSize;
	this->apple_y = std::rand() % 10 * rand_pos / 10 * dotSize;
	rect.setPosition(this->apple_x, this->apple_y);
}

sf::RectangleShape Apple::draw(){
	sf::RectangleShape appleRec;
	appleRec.setPosition(this->apple_x, this->apple_y);
	appleRec.setSize( sf::Vector2f(dotSize, dotSize) );
	appleRec.setFillColor(sf::Color::Red);
	appleRec.setOrigin(dotSize / 2.f, dotSize / 2.f);
	return appleRec;
}
sf::Sprite& Apple::drawImage(){
	playerImage.setPosition(rect.getPosition());
	playerImage.setOrigin(playerImage.getGlobalBounds().width/2, playerImage.getGlobalBounds().height/2);
	return playerImage;
}
/**Functions recieved from Arkanoid source code**/
int Apple::x() 		{ return this->apple_x; }
int Apple::y() 		{ return this->apple_y; }
sf::Vector2f Apple::pos()      { return rect.getPosition(); }
/**Functions recieved from Arkanoid source code**/
