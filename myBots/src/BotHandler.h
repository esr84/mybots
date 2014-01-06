/*
 * BotHandler.h
 *
 *  Created on: 04/01/2014
 *      Author: esr
 */

#ifndef BOTHANDLER_H_
#define BOTHANDLER_H_

class BotHandler {
public:
	virtual void isConnected()=0;
	virtual void isSendData()=0;
	virtual void isRecuveData(boost::asio::streambuf *buf)=0;
};

#endif /* BOTHANDLER_H_ */
