/*
 * BotMiniMax.h
 *
 *  Created on: 06/01/2014
 *      Author: esr
 */

#ifndef BOTMINIMAX_H_
#define BOTMINIMAX_H_

#include "bots/bots.h"
#include "bots/bot.h"
#include "MiniMaxState.h"

class BotMiniMax {
public:
	BotMiniMax();
	virtual ~BotMiniMax();

	bot::direction initIa(const bots & actBots, const bot::position & position,int depth);
	int functionMax(bots & actBots,const bot::position & position,int depth);
	int functionMin(bots & actBots,const bot::position & position,int depth);

private:
	bot::team_id _team;

	int calculateNumBots(const std::map<bot::team_id, size_t> & numBots);
	int calculateMiniMax(bots & actBots,const bot::position & position);

	MiniMaxState state;
	int sizeField;
};

#endif /* BOTMINIMAX_H_ */
