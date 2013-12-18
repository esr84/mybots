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

BotConnect::BotConnect(char* port, char* server, BotLogic *logic):_logic(logic) {

	boost::asio::io_service io_services;
	tcp::resolver resolver(io_services);
	sock = std::make_shared<tcp::socket>(io_services);
	tcp::resolver::query query(server, port);
	resolver.async_resolve(query,
	          boost::bind(&BotConnect::handle_resolve, this,
	          boost::asio::placeholders::error,
	          boost::asio::placeholders::iterator));

}

BotConnect::~BotConnect() {
	// TODO !CodeTemplates.destructorstub.tododesc!
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
     std::cout << "Error: " << err.message() << "\n";
   }
 }


void BotConnect::handle_connect(const boost::system::error_code& err)
{
  if (!err)
  {
    // The connection was successful. Send the request.
    boost::asio::async_write(socket_, request_,
        boost::bind(&client::handle_write_request, this,
          boost::asio::placeholders::error));
  }
  else
  {
    std::cout << "Error: " << err.message() << "\n";
  }
}
