//
// Created by FrozZenOnE on 12.12.2018.
//

#ifndef LRGAME_AIPLAYER_H
#define LRGAME_AIPLAYER_H

#include <map>
#include "Player.hpp"

class AIPlayer : public Player {
protected:
    std::map<std::string, int> nGrammMap;
    int n;

    const char getRandomLR() const;
    std::string getNGrammWithoutGuess(const std::string_view &playerInputHistory) const;
    void learnFromPreviousGames(const std::string_view &playerInputHistory);

public:
    explicit AIPlayer(std::string name, int n = 4);
    virtual const char getPlayerInput() = 0;
};


#endif //LRGAME_AIPLAYER_H
