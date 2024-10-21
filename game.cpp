#include "game.hpp"
#include <iostream>
#include <string>
#include <vector>


using namespace std;

Game::Game()
{
    currentPlayer = 'X';
}

void Game::start()
{
    bool running = true;
    while (running)
    {
        board.display();
        promptMove();
        if (winChecker(currentPlayer))
        {
            board.display();
            cout << "Player " << currentPlayer << " is the winner!" << endl;
            running = playAgain();
            if (running)
            {
                board.reset();
                currentPlayer = 'X';
            }

        }
        else if (board.full())
        {
            board.display();
            cout << "It's a draw!" << endl;
            running = playAgain();
            if (running)
            {
                board.reset();
                currentPlayer = 'X';
            }
        }
        else
        {
            switchPlayer();
        }
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
                return true;
            }
    }
    return false;
}
void Game::switchPlayer()
{
    if (currentPlayer == 'X')
    {
        currentPlayer = 'O';
    }
    else
    {
        currentPlayer = 'X';
    }
}
bool Game::validateInput()
{
    getline(cin, input); 
    if (input.empty())
    {
        return false;
    }

    for (char c : input)
    {
        if (!isdigit(c))
        {
            return false;
        }
    }

    int value = stoi(input); 

    if (value < 1 || value > 9)
    {
        return false;
    }
    validInput = value;
    return true;
}

void Game::promptMove()
{
    cin.clear();
    bool valid = false;
    while (!valid)
    {
        cin.clear();
        cout << "\nPlayer " << currentPlayer << ": Enter the number you would like to make a move: " << endl;
        if (validateInput())
        {
            if (board.move(validInput, currentPlayer))
            {
                //board.display();
                counter++;
                valid = true;
            }
            else
            {
                board.display();
                cout << "Invalid input! The spot is taken! Please choose an OPEN spot!" << endl;
            }
        }
        else if (counter > 0)
        {
            board.display();
            cout << "Invalid input! Please pick an integer between 1 and 9. Remember integers are whole numbers!" << endl;
        }
        else
        {
            board.display();
        }
    }
}
bool Game::playAgain()  
{
    while (true) 
    {
        cin.clear();
        cout << "Do you want to play again? (Y/N): ";
        string input;
        cin >> input;
        if (cin.fail()) {
            cout << "Invalid input! Please enter 'Y' or 'N'.\n";
        }
        char choice = toupper(input[0]);
        if (choice == 'Y') 
        {
            counter = 0;
            return true;
        } 
        else if (choice == 'N') 
        {
            cout << "Thank you for playing!\n";
            return false;
        } 
        else 
        {
            cout << "Invalid input! Please enter 'Y' or 'N'.\n";
        }
    }
}