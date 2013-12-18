/*
 * BotClient.h
 *
 *  Created on: 18/12/2013
 *      Author: jgi
 */

#ifndef BOTCLIENT_H_
#define BOTCLIENT_H_

#include "bots/bots.h"

class BotClient {
public:
	/**
	 * @param bots a reference to an instance of bots
	 */
	BotClient(bots & bots) :
			_bots(bots) // in this way I can have a reference as a class attribute
	{
		_team = -1; // this unreliably avoids problems when _team hasn't been initialized
	}
	;

	virtual ~BotClient();

	void perform(int depth);

	inline void set_team(bot::team_id team) {
		_team = team;
	}

private:
	bots & _bots;
	//bots & _bots;
	bot::team_id _team;
};

#endif /* BOTCLIENT_H_ */
