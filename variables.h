#pragma once
#ifndef GUARD_VARIABLES_H
#define GUARD_VARIABLES_H
/////////////////////
#define DEBUG false//
///////////////////
#define FRAMERATE 15//fps
#include "SFML/Graphics.hpp"
#include <array>

extern const int windowWidth, windowHeight; //800x600
extern const int allDots;//((windowWidth*windowHeight) / (dotSize*dotSize));
extern int dotSize;//20
extern int rand_pos; //= windowHeight / dotSize;
extern int dotInterval; //5
extern int dots;//1
extern int counterTick;
extern int points;//0
extern bool inGame;//true
extern bool pause;
extern bool start;

#endif 