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
	  int max = -100000;
	  int aux;
	  bot::direction prov;
	  int  numBot;
	  sizeField = actBots.get_size().first * actBots.get_size().first;
	  bot::position newPosition;
	  for(int i = 0; i < 9; i++) {

		  bot::direction new_dir = static_cast<bot::direction>(i);
		  bots newBots = bots(actBots);
		  bot *botAux = &newBots[position];
		  // copiamos el numero de bots que hay en el momento actual en el campo //
		 numBot = calculateNumBots(newBots.bot_count());
		 // realizamos el movimiento //
		 botAux->try_to_do(new_dir);
		 newBots.step();
		 // comprobamos que el numero de bots no haya cambiado //
		 // si ha cambiado es que nuestro bot a matado a 1 por lo que devolvemos 100 //
		  if(numBot>calculateNumBots(newBots.bot_count()))
			  return new_dir;

		  newPosition = botAux->get_position();
		  aux = functionMin(newBots,newPosition,depth);
		  if(aux > max)
		  {
			max = aux;
			prov = new_dir;
		  }
	  }

	  return prov;
}

int BotMiniMax::functionMax(bots & actBots,const bot::position & position,int depth){
	int max=-10000000;
	int aux;
	int  numBot;
	bot::position newPosition;
	depth--;
	if(depth<=0)
	{
		return calculateMiniMax(actBots,position);
	}
		  for(int i = 0; i < 9; i++) {

			  // hayamos la nueva direccion a la que probar //
			  bot::direction new_dir = static_cast<bot::direction>(i);
			  // copiamos la clase bots para no machacar lo anterior//
			  bots newBots = bots(actBots);
			  // hayamos el bot que estamos inspeccionando //
			  bot *botAux = &newBots[position];
			  // copiamos el numero de bots que hay en el momento actual en el campo //
			  numBot = calculateNumBots(newBots.bot_count());
			  // realizamos el movimiento //
			  botAux->try_to_do(new_dir);
			  newBots.step();
			  // comprobamos que el numero de bots no haya cambiado //
			  // si ha cambiado es que nuestro bot a matado a 1 por lo que devolvemos 100 //
			  if(numBot>calculateNumBots(newBots.bot_count()))
				  return sizeField;
			  // pedimos la nueva posicion de nuestro bot //
			  newPosition = botAux->get_position();
			  // llamamos a la funcion min con este movimiento //
			  aux =functionMin(newBots,newPosition,depth);
			  // si el maximo actual es menor que el maximo devuelto por la funcion lo actualizamos //
			  if(max<aux)
				  max = aux;
		  }
}

int BotMiniMax::functionMin(bots & actBots,const bot::position & position,int depth){
	int min=100000000;
	actBots.for_each_bot([this,actBots,position,depth,&min](bot & my_bot) {
		int aux;
		int actualMin;
		 if(my_bot.get_team() == _team)
			 return;
		 for(int i = 0; i < 9; i++) {
			 bot::direction new_dir = static_cast<bot::direction>(i);
			 bots newBots = bots(actBots);
			 newBots[my_bot.get_position()].try_to_do(new_dir);
			 newBots.step();
			 if(newBots.find_at(position)== nullptr)
			 {
				 min=sizeField*(-1);
				 return;
			 }
			 actualMin = min;
			 aux= this->functionMax(newBots,position,depth);
			 min = actualMin;
			 if(min > aux){
				 min = aux;
			 }
		 }
		});
	return min;
}

int BotMiniMax::calculateNumBots(const std::map<bot::team_id, size_t> & numBots){
	int num=0;

	for(auto it : numBots)
	{
		num +=it.second;
	}

	return num;
}

int BotMiniMax::calculateMiniMax(bots & actBots,const bot::position & position)
{
	state.reset();
	actBots.for_each_bot([this,actBots,position](bot & theBot) {
			unsigned int aux;
			int damage,bloked;
			bot myBot = actBots[position];
			 if(theBot.get_team() == _team)
				 return;

			 aux = actBots.distance_x(theBot,myBot) + actBots.distance_y(theBot,myBot);
			 bloked = state.comparateBot(myBot,theBot);
			 damage = state.comparateBot(theBot,myBot);

			 if(!state.getIsSetInit())
			 {
				 state.setLow(theBot.get_position(),aux,bloked,damage);
				 state.setUp(theBot.get_position(),aux,bloked,damage);
				 return;
			 }

			 if(state.getLow().damage > damage && bloked > 0){
				 state.setLow(theBot.get_position(),aux,bloked,damage);
			 }

			 if(state.getup().blokedDam > bloked){
				 state.setUp(theBot.get_position(),aux,bloked,damage);
			 }
	});

	return state.getLow().distancia - state.getup().distancia;
}
