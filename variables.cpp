#include "variables.h";
#include "SFML/Graphics.hpp"
const int windowWidth =800;
const int windowHeight = 600;
int dotSize=20;//20
const int allDots=((windowWidth*windowHeight) / (dotSize*dotSize)); 
int rand_pos= windowHeight / dotSize;
int dotInterval=5;
int dots=1;
int counterTick=0;
int points=0;
bool inGame=true;
bool pause = false;
bool start = false;
