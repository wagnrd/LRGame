//
// Created by frozzen on 12/23/18.
//

#include "AIGuesser.h"

AIGuesser::AIGuesser(std::string name, int n)
    : AIPlayer(std::move(name), n)
{}

const char AIGuesser::getPlayerInput()
{
    std::string_view playerInputHistory = game->getAvoidingPlayerInputHistory();

    if (playerInputHistory.size() < n + 1)
        return getRandomLR();

    learnFromPreviousGames(playerInputHistory);

    // process current input
    std::string nGrammWithoutGuess = getNGrammWithoutGuess(playerInputHistory);

    int nGrammLValue = 0;
    int nGrammRValue = 0;

    if (nGrammMap.find(nGrammWithoutGuess + 'L') != nGrammMap.end())
        nGrammLValue = nGrammMap.at(nGrammWithoutGuess + 'L');

    if (nGrammMap.find(nGrammWithoutGuess + 'R') != nGrammMap.end())
        nGrammRValue = nGrammMap.at(nGrammWithoutGuess + 'R');

    if (nGrammLValue > nGrammRValue)
        return 'L';
    else if (nGrammRValue > nGrammLValue)
        return 'R';
    else
        return getRandomLR();
}
