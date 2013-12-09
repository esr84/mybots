
#include<iostream>
#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/thread/mutex.hpp>

#include "BotLogic.h"

using boost::asio::ip::tcp;

BotLogic::BotLogic(char* port, char* server) {
	// conexion con el server //
		boost::asio::io_service io_services;

		tcp::resolver resolver(io_services);
	    auto end_iter = resolver.resolve({port,server});

	    socket = new std::shared_ptr<tcp::socket>(new tcp::socket(io_services));
	    boost::asio::connect(*socket, end_iter);
}

BotLogic::~BotLogic() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

void BotLogic::logicThread(){

	bot_client ai(bots);
	boost::asio::streambuf buf;

	while(!gameOver){
		 ai.perform(5);

		 for(auto b : bots.team_bots(id)) {
		            std::stringstream stream;
		            stream << "move " << b->get_x() << " " << b->get_y() << " " << b->get_next_direction();
		            send(*socket, stream.str());
		        }
	}
}

