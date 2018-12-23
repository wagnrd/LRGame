//
// Created by frozzen on 12/23/18.
//

#ifndef LRGAME_AIAVOIDER_H
#define LRGAME_AIAVOIDER_H


#include "AIPlayer.h"

class AIAvoider : public AIPlayer
{
    int guesses;
    int totalAnswers;

public:
    explicit AIAvoider(std::string name, int n = 4);
    const char getPlayerInput() override;
    const char returnGuess();
};


#endif //LRGAME_AIAVOIDER_H
