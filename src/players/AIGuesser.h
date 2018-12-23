//
// Created by frozzen on 12/23/18.
//

#ifndef LRGAME_AIGUESSER_H
#define LRGAME_AIGUESSER_H

#include "AIPlayer.h"

class AIGuesser : public AIPlayer {
public:
    explicit AIGuesser( std::string name, int n = 4 );
    const char getPlayerInput() override;
};

#endif //LRGAME_AIGUESSER_H
