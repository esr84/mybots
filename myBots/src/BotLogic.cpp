
#include<iostream>
#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/thread/mutex.hpp>

#include<string.h>

#include "BotLogic.h"
#include "BotClient.h"

using boost::asio::ip::tcp;

BotLogic::BotLogic(char* server, char* port,std::shared_ptr<bots> bots) {
	// conexion con el server //
/*	boost::asio::io_service io_services;


	tcp::resolver resolver(io_services);
//	try
//	{

		auto end_iter = resolver.resolve({port,server});

		sock = std::make_shared<tcp::socket>(io_services);
		boost::asio::connect(*sock, end_iter);

	//}catch(std::exception &ex){
		//std::cout << ex.what();
	//}
*/
	ai= std::make_shared<BotClient>(bots);
	strcpy(_port,port);
	strcpy(_server,server);
	sock.addHandler(this);
	gameOver = false;
	conected = false;
}

BotLogic::~BotLogic() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}


void BotLogic::send(tcp::socket &socket, const std::string & str) {
	boost::asio::write(socket, boost::asio::buffer(str + "\n"), boost::asio::transfer_all());
	//boost::asio::write(socket, boost::asio::buffer(str + "\n"), boost::asio::transfer_all());
	/*boost::asio::async_write(socket, boost::asio::buffer(str + "\n"),boost::asio::transfer_all(),
						     [this](boost::system::error_code ec, std::size_t length)
						     {
								std::cout << "entro";
						     });*/
}

void BotLogic::readData(){

}


void BotLogic::logicThread(){

	boost::asio::io_service io_service;
	sock.connect(_port,_server,&io_service);
	io_service.run();

/*	bool end;

	boost::asio::streambuf buf;
	{
		boost::mutex::scoped_lock lock(state_mutex);
		end=gameOver;
	}

	while(!end){
		ai.perform(5);

		for(auto b : _bots->team_bots(id)){
			std::stringstream stream;
			stream << "move " << b->get_x() << " " << b->get_y() << " " << b->get_next_direction();
			std::cout << "move " << b->get_x() << " " << b->get_y() << " " << b->get_next_direction();
			send(*sock, stream.str());
		}
		//read_until(*sock, buf,"\n");
		boost::asio::async_read(*sock, buf,
				[this](boost::system::error_code ec, std::size_t length)
			     {
					std::cout << "entro" << length;
			     });

		std::string data;
		std::istream is(&buf);
		std::getline(is,data);

		std::istringstream stream(data);

		std::string command;
		stream >> command;

		if(command == "welcome"){
			stream >> id;
			std::cout << "team id: " << id << std::endl;
			ai.set_team(id);

			stream >> field_w;
			stream >> field_h;
			{
				boost::mutex::scoped_lock lock(state_mutex);
				conected = true;
			}
		}else if(command == "state")
		{
			std::stringstream state;
			while(!stream.eof()){
				std::string a;
				stream >> a;
				state << a << " ";
			}

			boost::archive::text_iarchive ia(state);
			{
				boost::mutex::scoped_lock(bots_mutex);
				ia >> *_bots;
			}
		}
		{
			boost::mutex::scoped_lock lock(state_mutex);
			end=gameOver;
		}

	}*/
}

void BotLogic::iniThread(){
	 boost::thread t = boost::thread(    [this]() { logicThread(); } );
}

bool BotLogic::getConnected(){
	boost::mutex::scoped_lock lock(state_mutex);
	return conected;
}

bool BotLogic::getGamever(){
	boost::mutex::scoped_lock lock(state_mutex);
	return gameOver;
}

void BotLogic::finishGame(){
	boost::mutex::scoped_lock lock(state_mutex);
	gameOver = false;
}

bot::field_size BotLogic::getFieldH()
{
	return field_h;
}

bot::field_size BotLogic::getFieldW()
{
	return field_w;
}

void BotLogic::perform(){
	ai->perform(5);

		for(auto b : ai->getBots()->team_bots(id)){
			std::stringstream stream;
			stream << "move " << b->get_x() << " " << b->get_y() << " " << b->get_next_direction();
			std::cout << "move " << b->get_x() << " " << b->get_y() << " " << b->get_next_direction();
			sock.send(stream.str());
		}

		sock.read();
}

void BotLogic::isConnected(){
	perform();
}
void BotLogic::isSendData(){

}
void BotLogic::isRecuveData(boost::asio::streambuf *buf){
	bool end;
	std::string data;
			std::istream is(buf);
			std::getline(is,data);

			std::istringstream stream(data);

			std::string command;
			stream >> command;

			if(command == "welcome"){
				stream >> id;
				std::cout << "team id: " << id << std::endl;
				ai->set_team(id);

				stream >> field_w;
				stream >> field_h;
				{
					boost::mutex::scoped_lock lock(state_mutex);
					conected = true;
				}
			}else if(command == "state")
			{
				std::stringstream state;
				while(!stream.eof()){
					std::string a;
					stream >> a;
					state << a << " ";
				}

				boost::archive::text_iarchive ia(state);
				{
					boost::mutex::scoped_lock(bots_mutex);
					ai->setBots(ia);
				}
			}
			{
				boost::mutex::scoped_lock lock(state_mutex);
				end = gameOver;
			}

			if(!end)
				perform();
}
