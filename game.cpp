#include "game.hpp"
#include <iostream>
#include <vector>


using namespace std;

//Game::Game(){}

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
    return true;
}