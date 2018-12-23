#ifndef LRGAME_GAME_H
#define LRGAME_GAME_H

#include <string>
#include <memory>

class Player;

class Game {
    std::unique_ptr<Player> avoidingPlayer;
    std::unique_ptr<Player> guessingPlayer;
    int avoidingPlayerScore = 0;
    int guessingPlayerScore = 0;
    std::string avoidingPlayerInputHistory;
    std::string guessingPlayerInputHistory;

public:
    Game() = default;
    Game(std::unique_ptr<Player> avoidingPlayer, std::unique_ptr<Player> guessingPlayer);
    void start();
    void setAvoidingPlayer(std::unique_ptr<Player>&& avoidingPlayer);
    void setGuessingPlayer(std::unique_ptr<Player>&& guessingPlayer);
    std::string_view getAvoidingPlayerInputHistory();
    std::string_view getGuessingPlayerInputHistory();
};


#endif //LRGAME_GAME_H
