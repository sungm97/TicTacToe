#pragma once

#include <iostream>
#include "board.hpp"

class Game
{
    private:
        Board board;
    public:
        //Game();
        void start();
        bool winChecker(char symbol);
        char currentPlayer();
        void switchPlayer();
        void promptMove();
        bool playAgain();
        
        
};