#pragma once

#include <iostream>
#include <string>
#include "board.hpp"

using namespace std;

class Game {
private:
    Board board;
    char currentPlayer;
    string input;
    int validInput;
    int counter;
    bool isBattleMode;
    string player1Archetype;
    string player2Archetype;
    bool player1UsedSpecial;
    bool player2UsedSpecial;

    void selectArchetypes();
    void handleBattleMove();

public:
    Game(bool battleMode = false);
    void start();
    bool winChecker(char symbol);
    bool validateInput();
    void switchPlayer();
    void promptMove();
    bool playAgain();
};