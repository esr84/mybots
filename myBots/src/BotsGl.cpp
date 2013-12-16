/*
 * BotsGl.cpp
 *
 *  Created on: 04/12/2013
 *      Author: esr
 */

#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>

#include "BotsGl.h"

BotsGl::BotsGl(int h, int w) {
	winWidth = w;
	winHeight = h;
	SDL_Init(SDL_INIT_VIDEO);
	atexit(SDL_Quit);

	SDL_WM_SetCaption("bots", "bots");

	SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
	SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
	SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );
	setScreen(h,w);
}

BotsGl::~BotsGl() {
	// TODO !CodeTemplates.destructorstub.tododesc!
}


void BotsGl::setScreen(int w, int h, int fw, int fh) {

	SDL_SetVideoMode(w, h, 0, SDL_OPENGL | SDL_RESIZABLE);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, fw, 0, fh);
	glClearColor(0.0, 0.0 ,0.0, 0);
}

int BotsGl::eventControler(){
	SDL_Event event;

	if(SDL_PollEvent(&event)){
		switch(event.type){
		case SDL_QUIT:
			return SDLK_ESCAPE;
			break;
		case SDL_KEYDOWN:
			return (int)event.key.keysym.sym;

			break;
		case SDL_VIDEORESIZE:
			winWidth = event.resize.w;
			winHeight= event.resize.h;
			break;
		}
	}
	return -1;
}

void BotsGl::clearScreen(){
	 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	 glMatrixMode(GL_MODELVIEW);
}

void BotsGl::paintBots(const bot & the_bot){
	auto t = the_bot.get_team() + 1;

	glColor3f(t * 0.2, t * 0.3, t * 0.7);

	const bot::position & pos = the_bot.get_position();

	// WARNING deprecated OpenGL!
	glLoadIdentity();
	glTranslatef(pos.first, pos.second, 0);

	glBegin(GL_QUADS);
	glVertex3f(0.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 0.0f, 0.0f);
	glVertex3f(1.0f, 1.0f, 0.0f);
	glVertex3f(0.0f, 1.0f, 0.0f);
	glEnd();
}

void  BotsGl::swapBuffers(){
	SDL_GL_SwapBuffers();
}
