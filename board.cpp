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

bool Board::move(int spot)
{
    if (spot < 1 || spot > 9)
    {
        return false;
        //still need to check if the spot is occupied
    }
    else
    {
        grid[spot - 1] = 'x';
    }
    return true;

}
bool Board::full()
{
    for (char c: grid)
    {
        if (c != 'x' && c != 'o')
        {
            cout << "NOT FULL" << endl;
            return false;
        }
    }
    cout << "FULL" << endl;
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