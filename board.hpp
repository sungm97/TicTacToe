#pragma once

#include <iostream>
#include <vector>

class Board 
{
private:
   //std::vector<char> grid;
public:
    Board();
    std::vector<char> grid;
    void display();
    bool move(int spot, char symbol);
    bool full();
    void reset();
};
