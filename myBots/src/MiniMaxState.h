/*
 * MiniMaxState.h
 *
 *  Created on: 07/01/2014
 *      Author: jgi
 */

#ifndef MINIMAXSTATE_H_
#define MINIMAXSTATE_H_

#include "bots/bot.h"
#include "BotResume.h"

class MiniMaxState {
public:
	MiniMaxState();
	virtual ~MiniMaxState();

	inline void setLow(bot::position position,bot::field_size dist, int damage, int bloked){
		lowBot.posicion = position;
		lowBot.distancia = dist;
		lowBot.blokedDam = bloked;
		lowBot.damage = damage;
		isSetInit = true;
	}

	inline void setUp(bot::position position,bot::field_size dist,int damage, int bloked){

		upBot.posicion = position;
		upBot.distancia = dist;
		upBot.blokedDam = bloked;
		upBot.damage = damage;
		isSetInit = true;
	}

	inline const BotResume & getLow()
	{
		return lowBot;
	}

	inline const BotResume &  getup()
	{
			return upBot;
	}

	inline bool comparate()
	{
		return upBot == lowBot;
	}

	bool getIsSetInit(){
		return isSetInit;
	}

	int comparateBot(bot &oneBot, bot &twoBot);
	void reset();
private:
	bool isSetInit;

	BotResume lowBot;
	BotResume upBot;
};

#endif /* MINIMAXSTATE_H_ */
