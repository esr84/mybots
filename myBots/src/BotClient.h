/*
 * BotClient.h
 *
 *  Created on: 18/12/2013
 *      Author: jgi
 */

#ifndef BOTCLIENT_H_
#define BOTCLIENT_H_

#include "BotMiniMax.h"
#include "bots/bots.h"

template <class T>
class BotClient {
public:
	/**
	 * @param bots a reference to an instance of bots
	 */
	BotClient(std::shared_ptr<T> bots) :
			_bots(bots) // in this way I can have a reference as a class attribute
	{
		_team = -1; // this unreliably avoids problems when _team hasn't been initialized
	}
	;

	~BotClient() {
		// TODO !CodeTemplates.destructorstub.tododesc!
	}

//	virtual ~BotClient();

	void perform(int depth)
	{
		if(_team == -1)
			return;

		//std::cout << "entra en perform\n";
		_bots->for_each_bot([this,depth](bot & my_bot) {
				BotMiniMax minmax(_team);
				bot::direction newDir=static_cast<bot::direction>(3);;
				if(my_bot.get_team() == _team){
					newDir = minmax.initIa(*_bots,my_bot.get_position(),depth);
					my_bot.try_to_do(newDir);
					//_bots->step();
					//if(_bots->can_move(my_bot, newDir) || _bots->attacks(my_bot, newDir)) {
						//my_bot.try_to_do(newDir);
					//}
				}
		});
		//std::cout << "sale de perform\n";
	}



	inline void set_team(bot::team_id team) {
		_team = team;
	}
	inline const std::shared_ptr<T> getBots(){
		return _bots;
	}

	inline void setBots(boost::archive::text_iarchive  & ia)
	{
		ia >> *_bots;
	}

private:
	//bots & _bots;
	// template <bots> <- si no son bots o una clase hererada no funciona //
	std::shared_ptr<T> _bots;
	//bots & _bots;
	bot::team_id _team;
	bool _initializated;
};

#endif /* BOTCLIENT_H_ */
