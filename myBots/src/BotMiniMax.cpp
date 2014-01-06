/*
 * BotMiniMax.cpp
 *
 *  Created on: 06/01/2014
 *      Author: esr
 */

#include "BotMiniMax.h"

BotMiniMax::BotMiniMax() {
	// TODO Apéndice de constructor generado automáticamente

}

BotMiniMax::~BotMiniMax() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

bot::direction BotMiniMax::initIa(const bots & actBots,const bot::position & position, int depth)
{

	  bot::position newPosition;
	  for(int i = 0; i < 9; i++) {

		  bot::direction new_dir = static_cast<bot::direction>(i);
		  bots newBots = bots(actBots);
		  bot *botAux = &newBots[position];
		  botAux->try_to_do(new_dir);
		  newBots.step();
		  newPosition = botAux->get_position();
		  functionMin(newBots,newPosition,depth);
	  }
}

int BotMiniMax::functionMax(bots & actBots,const bot::position & position,int depth){
	int max=-10000000;
	int aux;
	bot::position newPosition;
	depth--;
	if(depth<=0)
	{
		// desarrollar el calculate value y salir del bucle recursivo
	}
		  for(int i = 0; i < 9; i++) {

			  bot::direction new_dir = static_cast<bot::direction>(i);
			  bots newBots = bots(actBots);
			  bot *botAux = &newBots[position];
			  botAux->try_to_do(new_dir);
			  newBots.step();
			  newPosition = botAux->get_position();
			  aux =functionMin(newBots,newPosition,depth);
			  if(max<aux)
				  max = aux;
		  }
}

int BotMiniMax::functionMin(bots & actBots,const bot::position & position,int depth){
	int min=100000000;
	actBots.for_each_bot([this,actBots,min,position,depth](bot & my_bot) {
		int aux;
		 if(my_bot.get_team() == _team)
			 return;
		 for(int i = 0; i < 9; i++) {
			 bot::direction new_dir = static_cast<bot::direction>(i);
			 bots newBots = bots(actBots);
			 newBots[my_bot.get_position()].try_to_do(new_dir);
			 newBots.step();
			 if(newBots.find_at(position)== nullptr)
			 {
				 min=-1;
				 return;
			 }
			 aux= this->functionMax(newBots,position,depth);
			 if(min > aux){
				 min = aux;
			 }
		 }
		});
	return min;
}
