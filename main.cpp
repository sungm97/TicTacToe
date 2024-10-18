#include <iostream>
#include <vector>
#include "board.hpp"
#include "game.hpp"

using namespace std;
int main()
{
    Game game;
    game.board.move(1);
    game.board.move(5);
    game.board.move(8);
    game.winChecker('x');
    game.start();
    return 0;
}