#include "game.hpp"
#include <iostream>
#include <vector>


using namespace std;

Game::Game(){}

void Game::start()
{
    bool running = true;
    while (running)
    {
        cout << "Welcome to Tic Tac Toe!" << "\n" << "Player 1 will go first and will be 'X'" << endl;
        board.display();
        running = false;
        
    }
}
bool Game::winChecker(char symbol)
{
    int winCombo[8][3] = 
    {
        {0,1,2},
        {3,4,5},
        {6,7,8},
        {0,3,6},
        {1,4,7},
        {2,5,8},
        {0,4,8},
        {2,4,6}
    };
    for (auto combo : winCombo)
    {
        if (board.grid[combo[0]] == symbol &&
            board.grid[combo[1]] == symbol &&
            board.grid[combo[2]] == symbol)
            {
                cout << symbol << " is the winner!" << endl;
                return true;
            }
    }
    cout << symbol << " is NOT the winner!" << endl;
    return false;
}