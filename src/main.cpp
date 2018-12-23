#include <iostream>
#include "Game.h"
#include "players/HumanPlayer.h"
#include "players/AIGuesser.h"
#include "players/AIAvoider.h"

int main()
{
    // Available Players: AIAvoider, AIGuesser, HumanPlayer
    // Alternatively use setters for avoider and guesser Player
    Game game(std::make_unique<AIAvoider>("AIAvoider", 5), std::make_unique<AIGuesser>("AIGuesser", 5));

    game.start();
}