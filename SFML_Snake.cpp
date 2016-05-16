/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
///Version 2.0///////////////////////////////////////////
///Game: Snake///////////////////////////////////////////
///Basheer Becerra///////////////////////////////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////
//Bugs To Fix:///////////////////////////////////////////
//--Snake Movement					//PARTIAL////////////
//--Image Memory Leak			   //COMPLETE////////////
//--Tail and Head Texture Loading //COMPELETE////////////
//--sf::Sound Bug				 //COMPLETE//////////////
/////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////

/*Import statements*/
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>
//////////////////////
#include "Snake.h"
#include "variables.h"
#include "Apple.h"
#include "SoundLoader.h"
#include "Audio.h"
//#include "Audio.h"
#include "SFML_Snake.h"
//#include "SoundLoader.h"
//////////////////////
#include <iostream>
#include <vector>
#include <string>
#include <array>
#include <map>
#include <memory>
//////////////////////

/*Game Construct*/
SFML_Snake::SFML_Snake():
	window(sf::VideoMode(windowWidth, windowHeight), "Snake" ),
	snake(Snake()), apple(Apple(0,0)), textCount(sf::Text()), sounds(SoundLoader())
{
	sounds.loadSounds();
	window.setFramerateLimit(FRAMERATE); //Set the game framerate using preprocessor value in "variabls.h"
}
void SFML_Snake::checkApple(Snake& mA, Apple& mB){
	if ((mA.x[0] == mB.x()) && (mA.y[0] == mB.y())){
		//sf::Sound().setBuffer.sf::SoundBuffer(audios.getSound("eating")).play();
		dots += dotInterval;
		points++;
		if(DEBUG)
			std::cout<< points << std::endl;
		textCount.setString(std::string("points: ") + std::to_string(points));
		mB.locateApple();
		sounds.playSound("eating");
		for(int i = mA.draw().size() - 1; i >= 0; i--){
			while (
				((mA.x[i] == mB.x()) && (mA.y[i] == mB.y())) 
				|| (0 == mB.x()) 
				|| (0 == mB.y()) 
				|| (windowWidth - dotSize/2 == mB.x()) 
				|| (windowHeight - dotSize/2 == mB.y())   
				){
					mB.locateApple();
			}
		}
	}
}
bool SFML_Snake::processEvents(){
	sf::Event event;
	while (window.pollEvent(event)){
		//if (event.type == sf::Event::Closed)
		//	window.close();
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Escape)) {
		//return true;
	}
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::P)
		|| sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space)) {
			if(start)
				pause = (pause) ? false : true;
			start = true;
			if(pause)
				textCount.setString("PAUSED");
			else
				textCount.setString(std::string("points: ") + std::to_string(points));
			sf::sleep(sf::Time(sf::milliseconds(200.f))); //PREVENTS DOUBLE CLICKS
	}
	if(!pause)
		snake.input();
	return false;
}
void SFML_Snake::update(){
	snake.checkReals();
	snake.moveUpdate();
	sounds.playSound("moving");
	checkApple(snake, apple);
	snake.checkBoundary();
}
void SFML_Snake::render(std::vector<sf::RectangleShape>& grid){
	window.clear(sf::Color::White);
	if(!pause && start){
		std::vector<sf::Sprite> shapearray = snake.drawImage();
		for (int i = shapearray.size() - 1; i >= 0; i--){
			window.draw(shapearray[i]);
		}
		window.draw(apple.drawImage());
	}
	for(int i = grid.size()-1; i>=0; i--){
		window.draw(grid[i]);
	}
	if(start == false)
		textCount.setString("SPACE-TO-START");
	textCount.setPosition(windowWidth / 2 - (textCount.getString().getSize()*(textCount.getCharacterSize() / 5)), textCount.getCharacterSize() - 10);
	window.draw(textCount);
	window.display();
}
std::vector<sf::RectangleShape> SFML_Snake::loadGrid(){
	std::vector<sf::RectangleShape> grid;
	for(int k= dotSize/2; k<=windowHeight+dotSize/2; k+=dotSize){
		sf::RectangleShape line;
		line.setPosition(0, k-dotSize);
		line.setSize(sf::Vector2f(windowWidth, 1));
		line.setFillColor(sf::Color::Black);
		if(k==dotSize/2 || k == windowHeight + dotSize/2){
			line.setSize(sf::Vector2f(windowWidth, dotSize));
		}
		grid.push_back(line);
	}
	for(int i = dotSize/2; i<=windowWidth+dotSize/2; i+=dotSize){

		sf::RectangleShape line;
		line.setPosition(i-dotSize, 0);
		line.setSize(sf::Vector2f(1, windowHeight));
		line.setFillColor(sf::Color::Black);
		if(i==dotSize/2 || i == windowWidth+dotSize/2){
			line.setSize(sf::Vector2f(dotSize, windowHeight));
		}
		grid.push_back(line);

	}
	return grid;

}
void SFML_Snake::run(){
	Audio &music = Audio();
	std::vector<sf::RectangleShape> grid = loadGrid();
	if(!DEBUG)
		std::cout<<"DEBUG MODE: OFF" <<std::endl;
	//Audio& audios = Audio();

	apple.locateApple();

	music.getMusic("backgroundMusic").setVolume(10);
	music.getMusic("backgroundMusic").setLoop(true);
	music.getMusic("backgroundMusic").setVolume(25);

	/*Load the font*/
	sf::Font font;
	if (!(font.loadFromFile("arial.ttf")))
		if(DEBUG)
			std::cout << "Error loading fonts" << std::endl;

	/*Create the text*/
	textCount.setFont(font);
	textCount.setString(std::string("points: ") + std::to_string(points));
	textCount.setColor(sf::Color::Red);
	textCount.setCharacterSize(20);
	textCount.setPosition(windowWidth / 2 - (textCount.getString().getSize()*(textCount.getCharacterSize() / 5)), textCount.getCharacterSize() - 10);
	textCount.setStyle(sf::Text::Bold);
	window.draw(textCount);
	//sf::Sound(sf::Sound().setBuffer.sf::SoundBuffer(audios.getSound("begin"))).play();
	music.getMusic("backgroundMusic").play();
	sounds.playSound("begin");
	while (inGame)
	{
		std::string counter = std::to_string(counterTick);
		if(DEBUG)
			//std::cout << "Tick: " + counter << std::endl;

				window.clear(sf::Color::White);
		if(processEvents()){
			break;
		}
		if(!pause && start)
			update();
		render(grid);
		snake.secInput = false;
		counterTick++;
		if(pause)
			std::cout<<"PASUUUSE"<<std::endl;
	}
	processEvents();
	sounds.playSound("losing");
	//sf::Sound(sf::Sound().setBuffer.sf::SoundBuffer(audios.getSound("losing"))).play();
	music.getMusic("backgroundMusic").stop();
	std::system("PAUSE");//bad practice, debuggin purposes
}