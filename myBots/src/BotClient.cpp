/*
 * BotClient.cpp
 *
 *  Created on: 18/12/2013
 *      Author: jgi
 */

#include "BotClient.h"
#include "bots/bot.h"

BotClient::~BotClient() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

void BotClient::perform(int depth)
{
	if(_team == -1)
		return;

	_bots->for_each_bot([this](bot & my_bot) {
			my_bot.try_to_do(static_cast<bot::direction>(5));

	});
}