cmake_minimum_required (VERSION 2.6)

project (botclient)

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG}")

Find_Package ( SDL REQUIRED )
find_package(OpenGL REQUIRED )
find_package(Boost 1.40.0 REQUIRED COMPONENTS system thread serialization)

include_directories(${Boost_INCLUDE_DIR})



add_definitions(-std=c++11)

include_directories(${SDL_INCLUDE_DIR})

include_directories(bots)

link_directories( ${link_directories} ./bots ) 

add_executable(botclient BotConnect.cpp  BotLogic.cpp  BotMiniMax.cpp  BotsGl.cpp  FacadeNetwork.cpp  main.cpp  MiniMaxState.cpp bots/bots.cpp bots/bot.cpp)

target_link_libraries(botclient ${SDL_LIBRARY})
target_link_libraries(botclient ${OPENGL_LIBRARY})
target_link_libraries(botclient ${Boost_LIBRARIES})