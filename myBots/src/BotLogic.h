/*
 * BotLogic.h
 *
 *  Created on: 04/12/2013
 *      Author: esr
 */

#ifndef BOTLOGIC_H_
#define BOTLOGIC_H_

#include "bots/bots.h"

// borrar despues
#include "BotsGl.h"

using boost::asio::ip::tcp;

class BotLogic {
private:
	bool conected;
	bool gameOver;
	std::shared_ptr<bots> _bots;
	bot::team_id id;
	boost::thread hilo;
	boost::mutex state_mutex;
	bot::field_size field_h,field_w;

	std::shared_ptr<tcp::socket> sock;

	void send(tcp::socket &socket, const std::string & str);
	void logicThread();
public:
	BotLogic(char* port, char* server, std::shared_ptr<bots> bots);
	void iniThread();
	bool getConnected();
	bool getGamever();
	void finishGame();
	//int initThread();
	bot::field_size getFieldH();
	bot::field_size getFieldW();

	boost::mutex bots_mutex;

	virtual ~BotLogic();
};

#endif /* BOTLOGIC_H_ */
