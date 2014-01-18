/*
 * BotConnect.h
 *
 *  Created on: 18/12/2013
 *      Author: esr
 */

#ifndef BOTCONNECT_H_
#define BOTCONNECT_H_

#include "BotHandler.h"

using boost::asio::ip::tcp;
class BotConnect {
public:
	BotConnect() ;
	virtual ~BotConnect();

	void addHandler(BotHandler *logic){
		_logic.push_back(logic);
	}

	void connect(char* port, char* server, boost::asio::io_service *io_services);
	void send(const std::string & str);
	void read();

private:

	void handle_resolve(const boost::system::error_code& err,tcp::resolver::iterator endpoint_iterator);
	void handle_connect(const boost::system::error_code& err);
	void handle_write(const boost::system::error_code& err);
	void handle_read(const boost::system::error_code& err);
	std::shared_ptr<tcp::socket> sock;
	std::vector<BotHandler *> _logic;
	boost::asio::streambuf _response;
	char _port[32];
	char _server[256];
	boost::asio::io_service *_io_service;
};

#endif /* BOTCONNECT_H_ */
