/*
 * BotClient.cpp
 *
 *  Created on: 18/12/2013
 *      Author: jgi
 */

#include "BotClient.h"
#include "BotMiniMax.h"
#include "bots/bot.h"

BotClient::~BotClient() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

void BotClient::perform(int depth)
{
	if(_team == -1)
		return;

	//std::cout << "entra en perform\n";
	_bots->for_each_bot([this,depth](bot & my_bot) {
			BotMiniMax minmax(_team);
			bot::direction newDir=static_cast<bot::direction>(3);;
			if(my_bot.get_team() == _team){
				newDir = minmax.initIa(*_bots,my_bot.get_position(),depth);
				my_bot.try_to_do(newDir);
				//_bots->step();
				//if(_bots->can_move(my_bot, newDir) || _bots->attacks(my_bot, newDir)) {
					//my_bot.try_to_do(newDir);
				//}
			}
	});
	//std::cout << "sale de perform\n";
}
