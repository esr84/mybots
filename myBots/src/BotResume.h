/*
 * BotResume.h
 *
 *  Created on: 07/01/2014
 *      Author: jgi
 */

#ifndef BOTRESUME_H_
#define BOTRESUME_H_

#include "bots/bot.h"

class BotResume {
public:
	BotResume() = default;
	virtual ~BotResume(){}

	bot::position posicion;
	bot::field_size distancia;
	int damage;
	int blokedDam;

	void reset()
	{
		posicion.first = 0;
		posicion.second = 0;
		damage = 0;
		blokedDam = 0;
	}

};

#endif /* BOTRESUME_H_ */
