//
// Created by FrozZenOnE on 12.12.2018.
//

#include "AIPlayer.h"
#include <random>
#include <string_view>
#include <iostream>

AIPlayer::AIPlayer(std::string name, int n)
    : Player(std::move(name)), n(n)
{}

void AIPlayer::learnFromPreviousGames(const std::string_view &playerInputHistory)
{
    std::string previousGameNGramm = static_cast<std::string>(playerInputHistory.substr( playerInputHistory.size() - n, playerInputHistory.size()));

    if ( nGrammMap.find(previousGameNGramm) != nGrammMap.end())
    {
        int previousGameNGrammValue = nGrammMap.at(previousGameNGramm);
        nGrammMap[previousGameNGramm] = ++previousGameNGrammValue;
    }
    else
    {
        nGrammMap[previousGameNGramm] = 1;
    }
}

std::string AIPlayer::getNGrammWithoutGuess(const std::string_view& playerInputHistory) const
{
    return static_cast<std::string>(playerInputHistory.substr( playerInputHistory.size() - ( n - 1), playerInputHistory.size()));
}

const char AIPlayer::getRandomLR() const
{
    std::mt19937_64 rng;
    rng.seed(std::random_device()());
    std::uniform_int_distribution<std::mt19937_64::result_type> dist2(1, 2);

    return dist2(rng) == 1 ? 'R' : 'L';
}
