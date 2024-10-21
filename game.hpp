#pragma once

#include <iostream>
#include "board.hpp"

using namespace std;

class Game
{
    private:
    public:
        Board board;
        string input;
        int validInput;
        int counter;
        Game();
        void start();
        bool winChecker(char symbol);
        bool validateInput();
        char currentPlayer;
        void switchPlayer();
        void promptMove();
        bool playAgain();
        
        
};