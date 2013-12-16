/*
 * main.cpp
 *
 *  Created on: 25/11/2013
 *      Author: esr
 */
#include<iostream>
#include<SDL/SDL.h>
#include<GL/gl.h>
#include<GL/glu.h>
#include<boost/asio.hpp>
#include <boost/thread/thread.hpp>

#include <boost/archive/text_iarchive.hpp>
#include <boost/archive/text_oarchive.hpp>
#include <boost/thread/mutex.hpp>
#include <stdlib.h>


#include "bots/bots.h"
#include "botclient.h"

#include "BotsGl.h"
#include "BotLogic.h"


using boost::asio::ip::tcp;

void send(tcp::socket &socket, const std::string & str) {
    boost::asio::write(socket, boost::asio::buffer(str + "\n"), boost::asio::transfer_all());
}

void setScreen(int w, int h, int fw = 0, int fh = 0) {

    SDL_SetVideoMode(w, h, 0, SDL_OPENGL | SDL_RESIZABLE);
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, fw, 0, fh);
    glClearColor(0.0, 0.0 ,0.0, 0);
}

void gameThread(std::shared_ptr<tcp::socket> socket, bool &gameover, bots & bots, bot::team_id &id,
		boost::mutex & state_mutex, bot::field_size &field_width, bot::field_size &field_height,
        int &win_width, int &win_height, bool &connected)
{
	bot_client ai(bots);

	    boost::asio::streambuf buf;
	    while(!gameover) {

	        ai.perform(5);

	        for(auto b : bots.team_bots(id)) {
	            std::stringstream stream;
	            stream << "move " << b->get_x() << " " << b->get_y() << " " << b->get_next_direction();
	            send(*socket, stream.str());
	        }

	        read_until(*socket, buf, "\n");

	        std::string data;
	        std::istream is(&buf);
	        std::getline(is, data);


	        std::istringstream stream(data);

	        std::string command;
	        stream >> command;

	        if(command == "welcome") {
	            stream >> id;
	            std::cout << "team id: " << id << std::endl;
	            ai.set_team(id);

	            stream >> field_width;
	            stream >> field_height;
	            //bots.set_size(field_width, field_height);
	            //std::cout << "setting field: " << field_width << " x " << field_height << std::endl;
	            //std::cout << "setting " << win_width << ", " << win_height << std::endl;
	            setScreen(win_width, win_height, field_width, field_height);
	            connected = true;
	        }
	        else if(command == "state") {

	            std::stringstream state;
	            while(!stream.eof()) {
	                std::string a;
	                stream >> a;
	                state << a << " ";
	            }

	            boost::archive::text_iarchive ia(state);
	            {
	                // mutex:
	                // segfaults if it draws during a state update (drawing +
	                // incomplete state is fatal)
	                boost::mutex::scoped_lock lock(state_mutex);
	                ia >> bots;
	            }
	        }
	    }
}

int main(int argc, char* argv[])
{
    	int winWidth = 500;
    	int winHeight = 500;

    	BotsGl gl(winWidth,winHeight);

    	// comprobacion de que los parametros sean los minimos //
    			if(argc<3){
    				std::cout << argv[0] << " " << "[server] [port]" << std::endl;
    				return -1;
    			}

    	std::shared_ptr<bots>  _bots = std::make_shared<bots>();;
    	BotLogic logic(argv[1],argv[2],_bots);
    	logic.iniThread();

    	while(!logic.getGamever()){
    		if(gl.eventControler() == SDLK_ESCAPE)
    			logic.finishGame();

    		gl.clearScreen();

    		{
    			boost::mutex::scoped_lock(logic.bots_mutex);
    			_bots->for_each_bot([&_bots,&gl](const bot & the_bot){
    				gl.paintBots(the_bot);
    			});
    		}
    	}

}

/*
int obsoleted(int argc, char*^argv[]){
	int winWidth = 500;
		int winHeight = 500;

		bot::field_size field

		bool gameOver=false;
		bool connected = false;

		bots bots;
		boost::mutex state_mutex;

		// comprobacion de que los parametros sean los minimos //
		if(argc<3){
			std::cout << argv[0] << " " << "[server] [port]" << std::endl;
			return -1;
		}

		// conexion con el server //
		boost::asio::io_service io_services;
	    tcp::resolver resolver(io_services);
	    auto end_iter = resolver.resolve({argv[1],argv[2]});

	    std::shared_ptr<tcp::socket> socket(new tcp::socket(io_services));
	    boost::asio::connect(*socket, end_iter);

	    // iniciamos el SDL //
	    SDL_Init(SDL_INIT_VIDEO);
	    atexit(SDL_Quit);

	    SDL_WM_SetCaption("bots", "bots");

	    SDL_GL_SetAttribute( SDL_GL_RED_SIZE, 5 );
	    SDL_GL_SetAttribute( SDL_GL_GREEN_SIZE, 5 );
	    SDL_GL_SetAttribute( SDL_GL_BLUE_SIZE, 5 );
	    SDL_GL_SetAttribute( SDL_GL_DEPTH_SIZE, 16 );
	    SDL_GL_SetAttribute( SDL_GL_DOUBLEBUFFER, 1 );

	    setScreen(winWidth,winHeight);

	    SDL_Event event;

	    while(!gameOver){
	    	// Gestionamos los eventos de SDL //
	    	if(SDL_PollEvent(&event)){
	    		switch(event.type){
	    		case SDL_QUIT:
	    			gameOver=true;
	    			break;
	    		case SDL_KEYDOWN:
	    			switch(event.key.keysym.sym)
	    			{
	    			case SDLK_ESCAPE:
	    			case SDLK_q:
	    				gameOver = true;
	    				break;
	    			}

	    			break;
	    		case SDL_VIDEORESIZE:
	    			winWidth = event.resize.w;
	    			winHeight= event.resize.h;
	    			break;
	    		}
	    	}

	    	// Limpiamos la pantalla //
	    	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	    	glMatrixMode(GL_MODELVIEW);

	    	// Comprobamos que este conectado //
	    	// si no esta conectado no seguimos y continuamos con el siguiente paso del bucle //
	    	// hasta que no este conectado no ejecutara la siguiente parte del codigo
	    	if(connected)
	    	{
	    		// Metemos un scope //
	    		{
	                {
	                     // mutex de los bots //
	                     boost::mutex::scoped_lock lock(state_mutex);
	                     // recorremos todos los bots que hay para pintarlos //
	                     bots.for_each_bot([&bots] (const bot & the_bot) {
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
	                             });
	                 }
	    		}
	    	}

	    	SDL_GL_SwapBuffers();

}

*/
