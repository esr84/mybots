/*
 * BotsGl.h
 *
 *  Created on: 04/12/2013
 *      Author: esr
 */

#ifndef BOTSGL_H_
#define BOTSGL_H_

#include "bots/bot.h"

class BotsGl {
	int winWidth;
	int winHeight;
public:
	BotsGl(int w, int h);
	virtual ~BotsGl();

	// incializa la pantalla con los parametros pasados //
	void setScreen(int w, int h, int fw = 0, int fh = 0);
	int eventControler();
	void clearScreen();
	void paintBots(const bot & the_bot);
	void swapBuffers();
};

#endif /* BOTSGL_H_ */
