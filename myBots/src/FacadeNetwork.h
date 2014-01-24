/*
 * FacadeNetwork.h
 *
 *  Created on: 18/01/2014
 *      Author: esr
 */

#ifndef FACADENETWORK_H_
#define FACADENETWORK_H_

#include <boost/thread/thread.hpp>
#include <boost/thread/mutex.hpp>

#include "BotConnect.h"

class FacadeNetwork: BotHandler {
private:
	BotConnect _sock;
	BotHandler *_handler;
	bool desconected;

	std::vector<std::string> _bufferSend;
	std::string _bufferRecuve;
	bool _newSend;
	bool _newRecuve;

	// Mutex para el sincronismo //
	boost::mutex _sendMutex;
	boost::mutex _recuveMutex;

	void initConnection(char* port, char* server);
	void sendVector();
public:
	FacadeNetwork();
	virtual ~FacadeNetwork();

	void connect(char* port, char* server);
	void send(const std::string & str);
	bool readBuffer(std::string&  buffer);
	bool isDisconnected();

	void isConnected();
	void isSendData();
	void isRecuveData(boost::asio::streambuf *buf);
	void isCloseConnect();
};

#endif /* FACADENETWORK_H_ */
