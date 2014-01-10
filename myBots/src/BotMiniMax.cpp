/*
 * BotMiniMax.cpp
 *
 *  Created on: 06/01/2014
 *      Author: esr
 */

#include "BotMiniMax.h"

BotMiniMax::BotMiniMax(bot::team_id team): _team(team) {
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
	  bot::position newPosition=position;
	  bots newBots = bots(actBots);
	  prov = initialStep(newBots,newPosition);

	  if(prov != bot::direction::NOTHING)
		  return prov;

	  newPosition=position;
	  adjacentBot(newPosition, actBots);
	  if(prov != bot::direction::NOTHING)
	 		  return prov;

	  for(int i = 0; i < 9; i++) {

		  bot::direction new_dir = static_cast<bot::direction>(i);
		  newBots = bots(actBots);
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
		  botAux->try_to_do(bot::direction::NOTHING);
		  aux = functionMin(newBots,newPosition,depth);
		  if(aux > max)
		  {
			max = aux;
			prov = new_dir;
		  }
		  std::cout << new_dir << " " << aux << " -- ";;
	  }

	  std::cout << "\n";
	  return prov;
}

bot::direction BotMiniMax::adjacentBot(bot::position & position, const bots & actBots)
{
	std::vector<bot *> adj;
	int min = 10000;


	bot  *nearBot = nullptr;
	bots newBots;
	bot *botAux;

	for(int i = 0; i < 3; i++)
	{
		bot::position & newPosition = position;
		for(int j = 0; j < 3; j++){
			actBots.find_at(position);
			/*if(it->get_energy()<min){
				min = it->get_energy();
				nearBot = it;
			}*/
		}
	}

	if( nearBot == nullptr)
			return bot::direction::NOTHING;

	return calculateDirection(actBots[position],*nearBot);
}

bot::direction BotMiniMax::initialStep(bots & actBots, const bot::position & position)
{
	bot  *nearBot = nullptr;
	bool equals = true;
	int distMin = sizeField;
	actBots.for_each_bot([this,actBots,position,&equals,&distMin,&nearBot](bot & theBot) {
		bot myBot = actBots[position];
		int aux;

		if(theBot.get_team() == _team)
			return;
		 aux = actBots.distance_x(theBot,myBot) + actBots.distance_y(theBot,myBot);
		 if(state.comparateBot(myBot,theBot) != state.comparateBot(theBot,myBot)){
			 equals=false;
			 return;
		 }
		 if(aux < distMin){
			 distMin = aux;
			 nearBot = &theBot;
		 }

	});

	if(!equals || nearBot == nullptr)
		return bot::direction::NOTHING;

	return calculateDirection(actBots[position],*nearBot);
}

bot::direction BotMiniMax::calculateDirection(const bot & BotSource, const bot & BotDesti)
{
	bot::direction new_dir;
	int x,y;
	x = BotSource.get_x() - BotDesti.get_x();
	y = BotSource.get_y() - BotDesti.get_y();

	if(y == 0){
		if(x<0)
			return bot::direction::E;
		else
			return bot::direction::W;
	}
	if(x==0){
		if(y<0)
			return bot::direction::N;
		else
			return bot::direction::S;
	}

	if(x<0)
	{
		if(y<0)
			return bot::direction::NE;
		else
			return bot::direction::SE;
	}

	if(x>0)
	{
		if(y<0)
			return bot::direction::NW;
		else
			return bot::direction::SW;
	}
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
			  botAux->try_to_do(bot::direction::NOTHING);
			  // llamamos a la funcion min con este movimiento //
			  aux =functionMin(newBots,newPosition,depth);
			  // si el maximo actual es menor que el maximo devuelto por la funcion lo actualizamos //
			  if(max<aux)
				  max = aux;
		  }
		  return max;
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
			 /*if(newBots.find_at(position)== nullptr)
			 {
				 min=sizeField*(-1);
				 return;
			 }*/
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
	int distM ;
	int aux;
	int c;
	for(c=0;c<2;c++){
	state.reset();
	int dismComp=-100;
	actBots.for_each_bot([this,actBots,position,&dismComp](bot & theBot) {
			unsigned int aux;

			int tiene,tengo;
			bot myBot = actBots[position];
			 if(theBot.get_team() == _team){

				 aux = actBots.distance_x(theBot,myBot) + actBots.distance_y(theBot,myBot);
				 if(aux == 0)
					 return;
				 if(dismComp>aux && aux != 0)
					 dismComp = aux;
				 return;
			 }

			 aux = actBots.distance_x(theBot,myBot) + actBots.distance_y(theBot,myBot);
			 tengo = state.comparateBot(myBot,theBot);
			 tiene = state.comparateBot(theBot,myBot);

			 if(!state.getIsSetInit())
			 {
				 state.setLow(theBot.get_position(),aux,tengo,tiene);
				 state.setUp(theBot.get_position(),aux,tengo,tiene);
				 return;
			 }

			 if(state.getLow().damage > tiene && tengo > 0){
				 state.setLow(theBot.get_position(),aux,tengo,tiene);
				 return;
			 }

			 if(state.getup().damage < tiene && tengo > 0){
				 state.setUp(theBot.get_position(),aux,tengo,tiene);
				 return;
			 }

			 if(state.comparate())
			 {
				 if(tengo > 0)
					 state.setLow(theBot.get_position(),aux,tengo,tiene);
				 else
					 state.setUp(theBot.get_position(),aux,tengo,tiene);
			 }
	});



	aux =  dismComp;
	int energyM =(state.getLow().blokedDam+state.getup().damage) - (state.getLow().damage+state.getup().blokedDam);
	distM = 1000 - (state.getLow().distancia*(state.getLow().blokedDam+state.getup().damage)) - (state.getup().distancia*(state.getLow().damage+state.getup().blokedDam));

	if(distM + aux == 0)
			std::cout << "";
	}
	return  distM + aux;
}

