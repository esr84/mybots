/*
 * BotLogic.h
 *
 *  Created on: 04/12/2013
 *      Author: esr
 */

#ifndef BOTLOGIC_H_
#define BOTLOGIC_H_

#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>

#include "bots/bots.h"

// borrar despues
#include "BotsGl.h"
#include "BotClient.h"
#include "BotHandler.h"
#include "FacadeNetwork.h"

using boost::asio::ip::tcp;

class BotLogic{
private:
	bool gameOver;
	std::shared_ptr<BotClient<bots>> ai;
	bot::team_id id;
	bot::field_size field_h,field_w;

	char _port[50];
	char _server[128];
	//std::shared_ptr<tcp::socket> sock;
	BotsGl gl;
	FacadeNetwork facade;
	void perform();
	void paint();
public:
	BotLogic(char* port, char* server, std::shared_ptr<bots> bots,int winWidth,int winHeight);
	virtual ~BotLogic(){}

	void iniThread();

	void isSendData();
	void isRecuveData();
};

#endif /* BOTLOGIC_H_ */
