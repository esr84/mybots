#include<iostream>
#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/thread/mutex.hpp>

#include<string.h>
#include<SDL/SDL.h>

#include "BotLogic.h"
#include "BotClient.h"

using boost::asio::ip::tcp;

BotLogic::BotLogic(char* server, char* port, std::shared_ptr<bots> actBots,
		int winWidth, int winHeight) :
		gl(winWidth, winHeight) {
	ai = std::make_shared<BotClient<bots>>(actBots);
	strcpy(_port, port);
	strcpy(_server, server);

}

BotLogic::~BotLogic() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}

void BotLogic::paint() {
	if (gl.eventControler() == SDLK_ESCAPE)
		facade.isCloseConnect();

	gl.clearScreen();

	ai->getBots()->for_each_bot([this](const bot & the_bot) {
		gl.paintBots(the_bot.get_position(),the_bot.get_team());
	});
	gl.swapBuffers();

}

void BotLogic::iniThread() {
	//boost::thread t = boost::thread(    [this]() { logicThread(); } );
	facade.connect(_port, _server);
	while (!facade.isDisconnected()) {
		isRecuveData();
		perform();
	}
}

bot::field_size BotLogic::getFieldH() {
	return field_h;
}

bot::field_size BotLogic::getFieldW() {
	return field_w;
}

void BotLogic::perform() {

	(ai)->perform(1);

	for (auto b : ai->getBots()->team_bots(id)) {
		std::stringstream stream;
		stream << "move " << b->get_x() << " " << b->get_y() << " "
				<< b->get_next_direction();
		//std::cout << "move " << b->get_x() << " " << b->get_y() << " "
			//	<< b->get_next_direction() << "\n";
		facade.send(stream.str());
	}

	paint();
}

void BotLogic::isConnected() {
	perform();
}
void BotLogic::isSendData() {

}
void BotLogic::isRecuveData(boost::asio::streambuf *buf) {
}
void BotLogic::isRecuveData() {
	bool end;
	std::string data;
	if (!facade.readBuffer(data))
		return;

	std::istringstream stream(data);

	std::string command;
	stream >> command;

	if (command == "welcome") {
		stream >> id;
		//std::cout << "team id: " << id << std::endl;
		ai->set_team(id);

		stream >> field_w;
		stream >> field_h;

	} else if (command == "state") {
		std::stringstream state;
		while (!stream.eof()) {
			std::string a;
			stream >> a;
			state << a << " ";
		}

		boost::archive::text_iarchive ia(state);
		{
			boost::mutex::scoped_lock(bots_mutex);
			ai->setBots(ia);
		}
		ai->getBots()->for_each_bot(
				[this](bot & my_bot) {
				//	std::cout << "\n" << my_bot.get_team() << " exp: " << my_bot.get_experience() << " kill: " << my_bot.get_kills() << " ener: " << my_bot.get_energy() <<"\n";
				});
	}
}
