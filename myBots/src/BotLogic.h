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

class BotLogic : public BotHandler{
private:
	bool conected;
	bool gameOver;
	std::shared_ptr<BotClient<bots>> ai;
	bot::team_id id;
	boost::thread hilo;
	boost::mutex state_mutex;
	bot::field_size field_h,field_w;

	//std::shared_ptr<tcp::socket> sock;
	BotsGl gl;
	FacadeNetwork facade;

	char _port[32];
	char _server[256];

	void send(tcp::socket &socket, const std::string & str);
	void readData();
	void logicThread();
	void perform();
	void paint();
public:
	BotLogic(char* port, char* server, std::shared_ptr<bots> bots,int winWidth,int winHeight);
	void iniThread();
	bool getConnected();
	bool getGamever();
	void finishGame();
	//int initThread();
	bot::field_size getFieldH();
	bot::field_size getFieldW();

	boost::mutex bots_mutex;

	virtual ~BotLogic();

	void isConnected();
	void isSendData();
	void isRecuveData();
	void isRecuveData(boost::asio::streambuf *buf);
};

#endif /* BOTLOGIC_H_ */
