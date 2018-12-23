#include <iostream>
#include "Game.h"
#include "players/Player.hpp"

Game::Game( std::unique_ptr<Player> avoidingPlayer, std::unique_ptr<Player> guessingPlayer )
    : avoidingPlayer(std::move(avoidingPlayer)), guessingPlayer(std::move(guessingPlayer))
{
    this->avoidingPlayer->setGame(this);
    this->guessingPlayer->setGame(this);
}

void Game::start()
{
    char avoidingPlayerInput, guessingPlayerInput;


    while (true)
    {
        avoidingPlayerInput = avoidingPlayer->getPlayerInput();
        guessingPlayerInput = guessingPlayer->getPlayerInput();

        if (avoidingPlayerInput == 'q' || guessingPlayerInput == 'q')
            break;

        avoidingPlayerInputHistory += avoidingPlayerInput;
        guessingPlayerInputHistory += guessingPlayerInput;
        std::string_view avoidingPlayerName = avoidingPlayer->getName();
        std::string_view guessingPlayerName = guessingPlayer->getName();

        std::cout << std::endl
                  << avoidingPlayerName << ": " << avoidingPlayerInput << std::endl
                  << guessingPlayerName << ": " << guessingPlayerInput << " (guess)" << std::endl;

        if (guessingPlayerInput == avoidingPlayerInput)
        {
            guessingPlayerScore++;
            std::cout << "=== " << guessingPlayerName << " wins! ===" << std::endl;
        }
        else
        {
            avoidingPlayerScore++;
            std::cout << "=== " << avoidingPlayerName << " wins! ===" << std::endl;
        }

        std::cout << avoidingPlayerName << ": " << avoidingPlayerScore << " - " << guessingPlayerName << ": " << guessingPlayerScore << std::endl;
    }
}

std::string_view Game::getAvoidingPlayerInputHistory()
{
    return avoidingPlayerInputHistory;
}

std::string_view Game::getGuessingPlayerInputHistory()
{
    return guessingPlayerInputHistory;
}

void Game::setAvoidingPlayer(std::unique_ptr<Player>&& avoidingPlayer)
{
    avoidingPlayer = std::move(avoidingPlayer);
}

void Game::setGuessingPlayer(std::unique_ptr<Player>&& guessingPlayer)
{
    guessingPlayer = std::move(guessingPlayer);
}
