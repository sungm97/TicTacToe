#pragma once

#include <iostream>
#include "board.hpp"

class Game
{
    private:
    public:
        Board board;
        int input;
        Game();
        void start();
        bool winChecker(char symbol);
        bool validateInput();
        char currentPlayer;
        void switchPlayer();
        void promptMove();
        bool playAgain();
        
        
};