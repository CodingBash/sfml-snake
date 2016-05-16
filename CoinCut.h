#pragma once
#ifndef GUARD_COINCUT_H
#define GUARD_COINCUT_H
#include "Coin.h"
#include "variables.h"
#include "SFML\Graphics.hpp"
struct CoinCut : Coin{
public:
	void doPower();
};
#endif
