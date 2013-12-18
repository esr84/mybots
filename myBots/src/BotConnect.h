/*
 * BotConnect.h
 *
 *  Created on: 18/12/2013
 *      Author: esr
 */

#ifndef BOTCONNECT_H_
#define BOTCONNECT_H_

using boost::asio::ip::tcp;
class BotConnect {
public:
	BotConnect(char* port, char* server, BotLogic *logic);
	virtual ~BotConnect();

	void handle_resolve(const boost::system::error_code& err,tcp::resolver::iterator endpoint_iterator);
	void handle_connect(const boost::system::error_code& err);
private:
	std::shared_ptr<tcp::socket> sock;
	BotLogic *_logic;
};

#endif /* BOTCONNECT_H_ */
