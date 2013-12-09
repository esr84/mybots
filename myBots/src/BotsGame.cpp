/*
 * BotsGame.cpp
 *
 *  Created on: 04/12/2013
 *      Author: esr
 */

#include "BotsGame.h"

BotsGame::BotsGame() {
}

BotsGame BotsGame::getInstance(){
	if(game == NULL)
		game=new BotsGame();

	return game;
}

BotsGame::~BotsGame() {
}

