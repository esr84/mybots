/*
 * BotLogic.h
 *
 *  Created on: 04/12/2013
 *      Author: esr
 */

#ifndef BOTLOGIC_H_
#define BOTLOGIC_H_

#include "bots/bots.h"

class BotLogic {
private:
	bool conected;
	bool gameOver;
	bots bots;
	boost::thread hilo;
	boost::mutex state_mutex;
	bot::field_size field;

	std::shared_ptr<tcp::socket> socket;

	logicThread();
public:
	BotLogic(char* port, char* server);
	virtual ~BotLogic();


};

#endif /* BOTLOGIC_H_ */
