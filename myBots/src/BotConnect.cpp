/*
 * BotConnect.cpp
 *
 *  Created on: 18/12/2013
 *      Author: esr
 */

#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/thread/mutex.hpp>

#include "BotLogic.h"
#include "BotConnect.h"

//using boost::asio::ip::tcp;

BotConnect::BotConnect() {

}

BotConnect::~BotConnect() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

void BotConnect::connect(char* port, char* server, boost::asio::io_service *io_service){
	strcpy(_port,port);
	strcpy(_server,server);
	_io_service = io_service;
	tcp::resolver resolver(*io_service);
	sock = std::make_shared<tcp::socket>(*io_service);
	tcp::resolver::query query(server, port);
	resolver.async_resolve(query,
		          boost::bind(&BotConnect::handle_resolve, this,
		          boost::asio::placeholders::error,
		          boost::asio::placeholders::iterator));
}

void BotConnect::handle_resolve(const boost::system::error_code& err,
     tcp::resolver::iterator endpoint_iterator)
 {
   if (!err)
   {
     // Attempt a connection to each endpoint in the list until we
     // successfully establish a connection.
     boost::asio::async_connect(*sock, endpoint_iterator,
         boost::bind(&BotConnect::handle_connect,
        		 this,
        		 boost::asio::placeholders::error));
   }
   else
   {
	 if(err.value()==125)
		 connect(_port, _server, _io_service);
	 else
		 std::cout << "Error: " << err.message() << "\n";
   }
 }


void BotConnect::handle_connect(const boost::system::error_code& err)
{
  if (!err)
  {
	  for(auto aux : _logic)
		  aux->isConnected();
  }
  else
  {
    std::cout << "Error: " << err.message() << "\n";
  }
}

void BotConnect::send(const std::string & str){
	 // The connection was successful. Send the request.
	      boost::asio::async_write(*sock, boost::asio::buffer(str + "\n"),
	          boost::bind(&BotConnect::handle_write, this,
	            boost::asio::placeholders::error));
}
void BotConnect::handle_write(const boost::system::error_code& err){
	// se ignora //
	if(err){
		std::cout << "Error: " << err.message() << "\n";
	}
}

void BotConnect::read()
{
	boost::asio::async_read_until(*sock, _response, "\n",
	          boost::bind(&BotConnect::handle_read, this,
	            boost::asio::placeholders::error));
}

void BotConnect::handle_read(const boost::system::error_code& err)
{
	if (!err)
	  {
		for(auto aux : _logic)
			aux->isRecuveData(&_response);
	  }
	  else
	  {
	    std::cout << "Error: " << err.message() << "\n";
	  }
}
