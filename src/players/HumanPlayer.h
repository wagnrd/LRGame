//
// Created by FrozZenOnE on 12.12.2018.
//

#ifndef LRGAME_HUMANPLAYER_H
#define LRGAME_HUMANPLAYER_H

#include "Player.hpp"
#include <set>

class HumanPlayer : public Player {
    std::set<char> acceptedInput = { 'L', 'R', 'q' };

public:
    explicit HumanPlayer( std::string name );
    const char getPlayerInput() override;
};

#endif //LRGAME_HUMANPLAYER_H
