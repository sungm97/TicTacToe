#include <iostream>
#include <vector>
#include "board.hpp"
#include "game.hpp"
//#include "validator.hpp"

using namespace std;
int main()
{
    Game game;
    //game.board.move(1);
    //game.board.move(5);
    //game.board.move(8);
    //game.board.display();
    //game.promptMove();
    cout << "Welcome to Tic Tac Toe!" << "\n" << "Player 1 will go first and will be 'X'" << "\n";
    game.start();
    return 0;
}
