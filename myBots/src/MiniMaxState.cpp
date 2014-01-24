/*
 * MiniMaxState.cpp
 *
 *  Created on: 07/01/2014
 *      Author: jgi
 */


#include "MiniMaxState.h"

MiniMaxState::MiniMaxState() {
	reset();
}

MiniMaxState::~MiniMaxState() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

int MiniMaxState::comparateBot(bot &oneBot, bot &twoBot)
{
	return oneBot.get_energy() - std::max(0,twoBot.get_attack () - oneBot.get_defense());
}

void MiniMaxState::reset()
{
	lowBot.reset();
	upBot.reset();

	isSetInit = false;
}
