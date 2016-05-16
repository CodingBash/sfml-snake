#include "Coin.h"
#include "SFML\Graphics.hpp"
#include <iostream>
/*Apple shape declaration*/


/*Apple constructor: int coordinate for position*/
Coin::Coin(int x, int y){
	this->coin_x = x;
	this->coin_y = y;
	rect.setPosition(this->coin_x, this->coin_y);
	rect.setSize( sf::Vector2f(dotSize, dotSize ));
	rect.setFillColor(sf::Color::Magenta);
	rect.setOrigin(dotSize / 2.f, dotSize / 2.f);
	if(!texture.loadFromFile("Coin.png"))
		if(DEBUG)
			std::cout<<"Error loading coin.png"<<std::endl;
	playerImage.setTexture(texture);
}

/*Specific call update method*/
void Coin::locateCoin(){
	this->coin_x = std::rand() % 10 * rand_pos / 10 * dotSize;
	this->coin_y = std::rand() % 10 * rand_pos / 10 * dotSize;
	rect.setPosition(this->coin_x, this->coin_y);
}

sf::RectangleShape Coin::draw(){
	sf::RectangleShape appleRec;
	appleRec.setPosition(this->coin_x, this->coin_y);
	appleRec.setSize( sf::Vector2f(dotSize, dotSize) );
	appleRec.setFillColor(sf::Color::Red);
	appleRec.setOrigin(dotSize / 2.f, dotSize / 2.f);
	return appleRec;
}
sf::Sprite& Coin::drawImage(){
	playerImage.setPosition(rect.getPosition());
	playerImage.setOrigin(playerImage.getGlobalBounds().width/2, playerImage.getGlobalBounds().height/2);
	return playerImage;
}
/**Functions recieved from Arkanoid source code**/
int Coin::x() 		{ return this->coin_x; }
int Coin::y() 		{ return this->coin_y; }
sf::Vector2f Coin::pos()      { return rect.getPosition(); }
/**Functions recieved from Arkanoid source code**/
