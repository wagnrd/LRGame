//
// Created by FrozZenOnE on 12.12.2018.
//

#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer( std::string name )
        : Player( std::move( name ) )
{
}

const char HumanPlayer::getPlayerInput()
{
    char input;

    do
    {
        std::cin >> input;
    } while ( acceptedInput.find( input ) == acceptedInput.end() );

    return input;
}
