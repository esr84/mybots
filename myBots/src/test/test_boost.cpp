
#if !defined( WIN32 )
    #define BOOST_TEST_DYN_LINK
#endif
//  (C) Copyright Gennadiy Rozental 2005.
//  Distributed under the Boost Software License, Version 1.0.
//  (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

//  See http://www.boost.org/libs/test for the library home page.

// Boost.Test

// each test module could contain no more then one 'main' file with init function defined
// alternatively you could define init function yourself
#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>
#include "../MiniMaxState.h"
#include "../bots/bot.h"
#include "../bots/bots.h"
#include "../BotMiniMax.h"


//____________________________________________________________________________//

// most frequently you implement test cases as a free functions with automatic registration
BOOST_AUTO_TEST_CASE( test1 )
{
	MiniMaxState state;
	bot::position pos1;
	pos1.first = 0;
	pos1.second =0;
	bot bot1(1,pos1);
	bot bot2(1,pos1);

    BOOST_CHECK( state.comparateBot(bot1,bot2)  == state.comparateBot(bot2,bot1)  );
}

//____________________________________________________________________________//

// each test file may contain any number of test cases; each test case has to have unique name
BOOST_AUTO_TEST_CASE( test2 )
{
    int i = 0;
    BotMiniMax miniMax((bot::team_id)0);
    miniMax.setSizeField(100);
    MiniMaxState state;
    bots actBots(10,10);
    bot *aux1, *aux2;
    std::vector <bot *>  botV1;
    std::vector <bot *>  botV2;
  //  actBots.generate(1,1);
    actBots.generate(2,1);

    actBots.for_each_bot([&aux1 , &aux2](bot & theBot) {
    		if(theBot.get_team()==0)
    			aux1 = &theBot;
    		else
    			aux2 = &theBot;
    	});
    //std::cout << "pos1: " <<  aux2->get_position().first << ":" << aux2->get_position().second << "\n";

    std::cout << "pos2: " << aux2->get_position().first << ":" << aux2->get_position().second << "\n";
    bot::position newPosition = aux1->get_position();
    std::cout << "pos1: " << aux1->get_position().first << ":" << aux1->get_position().second << "\n";

    while(miniMax.adjacentBot(newPosition,actBots)==bot::direction::NOTHING && i<100){
    	bot::direction new_dir = miniMax.initialStep(actBots,newPosition);
    	aux1->try_to_do(new_dir);
    	actBots.step();
    	newPosition = aux1->get_position();
    	i++;
    	std::cout << "pos1: " << aux1->get_position().first << ":" << aux1->get_position().second << "\n";
    }
    newPosition =bot::new_position(newPosition,miniMax.adjacentBot(newPosition,actBots));
    // reports 'error in "test2": check i == 2 failed [0 != 2]'
    BOOST_CHECK(i<100);
    BOOST_CHECK_EQUAL( newPosition.first,  aux2->get_position().first);
    BOOST_CHECK_EQUAL( newPosition.second,  aux2->get_position().second);
}

//____________________________________________________________________________//

// EOF
