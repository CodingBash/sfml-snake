#include "Snake.h"
#include "variables.h"
#include "SFML/Graphics.hpp"
#include <iostream>
#include <array>


//Snake Constructor: int coordinates for position
Snake::Snake(){
	if(!headTexture.loadFromFile("head.png"))
		if(DEBUG)
			std::cout<<"Error loading head.png yo"<<std::endl;
	if(!tailTexture.loadFromFile("tail.png"))
		if(DEBUG)
			std::cout<<"Error loading tail.png yo"<<std::endl;
	if(!bodyStraightTexture.loadFromFile("body_straight.png"))
		if(DEBUG)
			std::cout<<"Error loading body_straight.png yo"<<std::endl;
	if(!bodyCornerTexture.loadFromFile("body_corner.png"))
		if(DEBUG)
			std::cout<<"Error loading body_corner.png yo"<<std::endl;
	for (int z = 0; z < dots; z++){
		this->x[z] = windowWidth / 2 - z * dotSize;
		this->y[z] = windowHeight / 2;
	}
	if(!head.loadFromFile("SnakeHead.png"))
		if(DEBUG)
			std::cerr<<"Error load \"SnakeHead.png\""<<std::endl;
	//Default direction
	goingUp = false;
	goingDown = false;
	goingLeft = false;
	goingRight = true;

	realUp = false;
	realDown = false;
	realLeft = false;
	realRight = false;

	secUp = false;
	secDown = false;
	secLeft = false;
	secRight = false;

	secInput = false; //Variable indicating first input has changed and able to declare to second input variables.
}

/*Changing direction member function*/
void Snake::changeDirections(int dir){

	if(secInput == false){
		if(secUp) {
			goingLeft = false;
			goingRight = false;
			goingDown=false;
			goingUp = true;
			secUp=false;
		}
		else if(secDown) {
			goingLeft = false;
			goingRight = false;
			goingDown=true;
			goingUp = false;
			secDown=false;
		}
		else if (secLeft) {
			goingLeft = true;
			goingRight = false;
			goingDown=false;
			goingUp = false;
			secLeft = false;
		}
		else if (secRight) {
			goingLeft = false;
			goingRight = true;
			goingDown=false;
			goingUp = false;
			secRight=false;
		} else {
			switch (dir){
			case 1:
				goingUp = true;
				goingDown = false;
				goingLeft = false;
				goingRight = false;
				break;
			case 2:
				goingUp = false;
				goingDown = true;
				goingLeft = false;
				goingRight = false;
				break;
			case 3:
				goingUp = false;
				goingDown = false;
				goingLeft = true;
				goingRight = false;
				break;
			case 4:
				goingUp = false;
				goingDown = false;
				goingLeft = false;
				goingRight = true;
				break;
			}
		}
		secInput = true;
	} else {
		switch (dir){
		case 1:
			secUp = true;
			secDown = false;
			secLeft = false;
			secRight = false;
			break;
		case 2:
			secUp = false;
			secDown = true;
			secLeft = false;
			secRight = false;
			break;
		case 3:
			secUp = false;
			secDown = false;
			secLeft = true;
			secRight = false;
			break;
		case 4:
			secUp = false;
			secDown = false;
			secLeft = false;
			secRight = true;
			break;
		}
	}
}
void Snake::input(){
	//std::cout<<"Keyboard Input Called" <<std::endl;
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Up))&& !realDown)
		changeDirections(1);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Down))&& !realUp)
		changeDirections(2);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))&& !realRight)
		changeDirections(3);
	if ((sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
		sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))&& !realLeft)
		changeDirections(4);

}
/*Frame by frame update*/

void Snake::moveUpdate(){

	for (int z = dots; z > 0; z--){
		x[z] = x[(z - 1)];
		y[z] = y[(z - 1)];
	}

	/*Movement actions*/
	if (goingUp)
		y[0] -= dotSize;

	else  if (goingDown)
		y[0] += dotSize;

	else if (goingLeft)
		x[0] -= dotSize;

	else if (goingRight)
		x[0] += dotSize;
}

void Snake::checkReals(){
	if (x[0] < x[1]){
		realLeft = true;
		realRight = false;
		realUp = false;
		realDown = false;
	}
	if (x[0] > x[1]){
		realRight = true;
		realLeft = false;
		realUp = false;
		realDown = false;
	}
	if (y[0] < y[1]){
		realUp = true;
		realDown = false;
		realRight = false;
		realLeft = false;
	}
	if (y[0] > y[1]){
		realDown = true;
		realUp = false;
		realLeft = false;
		realRight = false;
	}
	else
		std::cerr << "";//"Error Mismatch" << std::endl;

	//Debug Output
	if(DEBUG){
		if(goingUp)
			std::cout<< "First Direction: goingUp" << std::endl;
		if(goingDown)
			std::cout<< "First Direction: goingDown" << std::endl;
		if(goingLeft)
			std::cout<< "First Direction: goingLeft" << std::endl;
		if(goingRight)
			std::cout<< "First Direction: goingRight" << std::endl;
		if(secUp)
			std::cout<< "First Direction: secUp" << std::endl;
		if(secDown)
			std::cout<< "First Direction: secDown" << std::endl;
		if(secLeft)
			std::cout<< "First Direction: secLeft" << std::endl;
		if(secRight)
			std::cout<< "First Direction: secRight" << std::endl;
	}
}

std::vector<sf::RectangleShape> Snake::draw(){
	std::vector<sf::RectangleShape> recvec;
	for (int z = dots; z >= 0; z--){
		sf::RectangleShape r;
		r.setPosition(x[z], y[z]);
		r.setSize(sf::Vector2f( dotSize, dotSize ));
		r.setFillColor(sf::Color::Green);
		if (z == 0)
			r.setFillColor(sf::Color::Yellow);
		r.setOrigin(dotSize / 2.f, dotSize / 2.f);
		recvec.push_back(r);
	}
	return recvec;
}
std::vector<sf::Sprite> Snake::drawImage(){
	std::vector<sf::Sprite> recvec; //Vector that contains images of all body parts of snake
	for (int z = dots; z >= 0; z--){ //We are iterating through each body part to assign its image
		sf::Sprite playerImage; 
		playerImage.setTexture(bodyStraightTexture); //Default is the 'straight' image
		playerImage.setPosition(x[z], y[z]); //Position of image = position of body part
		playerImage.setOrigin(dotSize / 2.f, dotSize / 2.f); //Origin = center
		if(z!= dots && z!= 0){ //If the head or the tail is NOT selected (the middle)
			/* z+1 refers to body part behind...z-1 refers to in front) */
			if(x[z] == x[z+1] && x[z] == x[z-1]){/*nothing */} //EXAMPLE: if selected and front and behind is verticle (same x val), default straight (up and down)
			else if(y[z] == y[z+1] && y[z] == y[z-1]){playerImage.rotate(90);} //EXAMPLE: if horizontal, rotate 90 (left and right)
			else{
				/*If the adjacent is not straight, it must be a corner*/
				playerImage.setTexture(bodyCornerTexture); //Set corner image
				/*TOP AND LEFT*///Corner
				if     (y[z] == y[z+1] && x[z] > x[z+1]     &&     y[z] > y[z-1]&& x[z] == x[z-1])    {/*nothing*/}
				else if(y[z] == y[z-1] && x[z] > x[z-1]     &&     y[z] > y[z+1] && x[z] == x[z+1])   {/*nothing*/}

				/*TOP AND RIGHT*///Corner
				else if(y[z] == y[z+1] && x[z] < x[z+1]     &&     y[z] > y[z-1]&& x[z] == x[z-1])    {playerImage.rotate(90);}
				else if(y[z] == y[z-1] && x[z] < x[z-1]     &&     y[z] > y[z+1]&& x[z] == x[z+1])    {playerImage.rotate(90);}

				/*BOTTOM AND RIGHT*///Corner
				else if(y[z] == y[z+1] && x[z] < x[z+1]     &&     y[z] < y[z-1]&& x[z] == x[z-1])    {playerImage.rotate(180);}
				else if(y[z] == y[z-1] && x[z] < x[z-1]     &&     y[z] < y[z+1]&& x[z] == x[z+1])    {playerImage.rotate(180);}

				/*BOTTOM AND LEFT*///Corner
				else if(y[z] == y[z+1] && x[z] > x[z+1]     &&     y[z] < y[z-1]&& x[z] == x[z-1])    {playerImage.rotate(270);}
				else if(y[z] == y[z-1] && x[z] > x[z-1]     &&     y[z] < y[z+1]&& x[z] == x[z+1])    {playerImage.rotate(270);}
			}
		}
		//If Head
		if(z==0){ 
			/*Head is based off direction*/
			playerImage.setTexture(headTexture); //Default face UP 90
			if(goingRight)
				playerImage.rotate(90);
			else if (goingDown)
				playerImage.rotate(180);
			else if(goingLeft)
				playerImage.rotate(270);

		}

		/*The loop finds the last dot THAT IS DRAWN ON BOARD*/
		int maxDots = dots;
		for(int i = 0; i <=allDots; i++){
			if(x[i]<0) //if not drawn, x will be substantially negative
				break; 
			maxDots = i;

		}
		//

		/*Now we use the last drawn dot to draw the tail image*/
		if(z==maxDots){
			playerImage.setTexture(tailTexture); //Default face down
			if(x[maxDots] == x[maxDots-1] && y[maxDots] > y[maxDots-1]){/*nothing*/}
			else if(x[maxDots] < x[maxDots-1] && y[maxDots] == y[maxDots-1]){playerImage.rotate(90);}
			else if(x[maxDots] == x[maxDots-1] && y[maxDots] < y[maxDots-1]){playerImage.rotate(180);}
			else if(x[maxDots] > x[maxDots-1] && y[maxDots] == y[maxDots-1]){playerImage.rotate(270);}
		}
		recvec.push_back(playerImage); //Add it to the list and traverse if able
	}
	return recvec;
}

void Snake::checkBoundary(){
	for (int z = dots; z > 0; z--){
		if ((x[0] == x[z]) && (y[0] == y[z]))
			inGame = false;
	}
	if (y[0] >= windowHeight)
		inGame = false;
	if (y[0] < dotSize)
		inGame = false;
	if (x[0] >= windowWidth)
		inGame = false;
	if (x[0] < dotSize)
		inGame = false;
}
bool Snake::goingHorizontal(){ return goingLeft || goingRight; }
bool Snake::goingVertical(){ return goingDown || goingUp; }
