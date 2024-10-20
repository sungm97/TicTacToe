#include "board.hpp"
#include <iostream>
#include <vector>

using namespace std;

Board::Board()
{
    reset();
}

void Board::display()
{
    cout << "\n";
    for (int i = 0; i < 9; i=i+3)
    {
        cout << " " << grid[i] << " | " << grid[i+1] << " | " << grid[i+2] << "\n";
        if (i < 6)
        {
            cout << "-----------" << "\n";
        }
    }
}

bool Board::move(int spot, char symbol)
{
    if (grid[spot-1] == 'X' || grid[spot-1] == 'O')
    {
        return false;
        //validatorInput checks if the user input is 1~9
    }
    else
    {
        grid[spot - 1] = symbol;
    }
    return true;

}
bool Board::full()
{
    for (char c: grid)
    {
        if (c != 'X' && c != 'O')
        {
            return false;
        }
    }
    return true;
}
void Board::reset()
{
    cout << "Clearing Board!" << endl;
    grid.clear();
    for (int i = 0; i < 9; ++i)
    {
        grid.push_back(i + '1');
    }
}