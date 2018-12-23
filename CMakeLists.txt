cmake_minimum_required(VERSION 3.12)
project(LRGame)

set(CMAKE_CXX_STANDARD 17)

add_executable(LRGame src/main.cpp src/Game.cpp src/Game.h src/players/AIPlayer.cpp src/players/AIPlayer.h src/players/HumanPlayer.cpp src/players/HumanPlayer.h src/players/Player.hpp src/players/AIGuesser.cpp src/players/AIGuesser.h src/players/AIAvoider.cpp src/players/AIAvoider.h)
