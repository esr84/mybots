/*
 * main.cpp
 *
 *  Created on: 25/11/2013
 *      Author: esr
 */
#include<iostream>
#include<SDL/SDL.h>

#include <boost/thread/mutex.hpp>
#include <stdlib.h>

#include "bots/bots.h"


#include "BotsGl.h"
#include "BotLogic.h"

int main(int argc, char* argv[]) {
	int winWidth = 500;
	int winHeight = 500;

	//BotsGl gl(winWidth, winHeight);

	// comprobacion de que los parametros sean los minimos //
	if (argc < 3) {
		std::cout << argv[0] << " " << "[server] [port]" << std::endl;
		return -1;
	}

	std::shared_ptr<bots> _bots = std::make_shared<bots>();

	BotLogic logic(argv[1], argv[2], _bots,winWidth,winHeight);
	logic.iniThread();

}

