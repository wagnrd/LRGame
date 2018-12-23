//
// Created by frozzen on 12/23/18.
//

#include "AIAvoider.h"
#include <thread>
#include <iostream>
#include <iomanip>

AIAvoider::AIAvoider( std::string name, int n )
        : AIPlayer( std::move( name ), n )
{
}

const char AIAvoider::getPlayerInput()
{
    totalAnswers++;
    std::string_view playerInputHistory = game->getAvoidingPlayerInputHistory();

    if ( playerInputHistory.size() < n + 1 )
        return returnGuess();

    learnFromPreviousGames( playerInputHistory );

    // process current input
    std::string nGrammWithoutGuess = getNGrammWithoutGuess( playerInputHistory );

    int nGrammLValue = 0;
    int nGrammRValue = 0;

    if ( nGrammMap.find( nGrammWithoutGuess + 'L' ) != nGrammMap.end() )
        nGrammLValue = nGrammMap.at( nGrammWithoutGuess + 'L' );

    if ( nGrammMap.find( nGrammWithoutGuess + 'R' ) != nGrammMap.end() )
        nGrammRValue = nGrammMap.at( nGrammWithoutGuess + 'R' );

    // wait 300ms to slow the battle down
    std::this_thread::sleep_for( std::chrono::milliseconds( 1 ) );

    // switched R and L to just take the oposite than AIGuesser would guess
    if ( nGrammLValue > nGrammRValue )
        return 'R';
    else if ( nGrammRValue > nGrammLValue )
        return 'L';
    else
        return returnGuess();
}

const char AIAvoider::returnGuess()
{
    guesses++;
    double guessesPercetage = ( 100.0 / totalAnswers * guesses );
    std::cout << std::endl << "No definit answer: " << guesses << " of " << totalAnswers << " ("
              << std::setprecision( 3 ) << guessesPercetage << "%) guessed";
    return getRandomLR();
}
