//
// Created by frozzen on 12/15/18.
//

#ifndef LRGAME_PLAYER_H
#define LRGAME_PLAYER_H

#include <string>
#include "../Game.h"

class Player {
protected:
    Game* game;
    std::string name;

public:
    virtual ~Player() = default;
    virtual const char getPlayerInput() = 0;

    explicit Player( std::string name )
            : name( std::move( name ) )
    {
    }

    std::string_view getName()
    {
        return name;
    }

    void setGame( Game* game )
    {
        this->game = game;
    }
};

#endif //LRGAME_PLAYER_H
