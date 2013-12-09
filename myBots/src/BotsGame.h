/*
 * BotsGame.h
 *
 *  Created on: 04/12/2013
 *      Author: esr
 */

#ifndef BOTSGAME_H_
#define BOTSGAME_H_

#include <iostream>

class BotsGame {
private:
	static BotsGame game=NULL;
	BotsGl graphics;
	bool init;
	BotsGame();
public:

	static BotsGame getInstance();
	virtual ~BotsGame();
};

#endif /* BOTSGAME_H_ */
