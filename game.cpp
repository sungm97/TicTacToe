#include "game.hpp"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

Game::Game(bool battleMode)
    : isBattleMode(battleMode), currentPlayer('X'), counter(0),
      player1UsedSpecial(false), player2UsedSpecial(false),
      totalGamesPlayed(0), player1Wins(0), player2Wins(0), ties(0) {}

void Game::start() {
    cout << "Welcome to Tic Tac Toe!" << endl;
    cout << "Player 1 will go first and will use marker 'X'." << endl;
    cout << "Player 2 will use marker 'O'." << endl;

    if (isBattleMode) {
        selectArchetypes();
    }

    bool running = true;
    while (running) {
        board.display();
        if (isBattleMode) {
            handleBattleMove();
        } else {
            promptMove();
        }

        if (winChecker(currentPlayer)) {
            board.display();
            cout << "Player " << (currentPlayer == 'X' ? "1" : "2") << " is the winner!" << endl;

            if (currentPlayer == 'X') {
                player1Wins++;
            } else {
                player2Wins++;
            }
            totalGamesPlayed++;

            running = playAgain();
            if (running) {
                board.reset();
                currentPlayer = 'X';
            }
        } else if (board.full()) {
            board.display();
            cout << "It's a draw!" << endl;

            ties++;
            totalGamesPlayed++;

            running = playAgain();
            if (running) {
                board.reset();
                currentPlayer = 'X';
            }
        } else {
            switchPlayer();
        }
    }

    
    generateReport();
}

void Game::selectArchetypes() {
    cout << "Player 1, choose your archetype (Swarm/Pyromancer): ";
    while (true) {
        cin >> player1Archetype;
        if (player1Archetype == "Swarm" || player1Archetype == "Pyromancer") break;
        cout << "Invalid archetype. Please choose 'Swarm' or 'Pyromancer': ";
    }

    cout << "Player 2, choose your archetype (Swarm/Pyromancer): ";
    while (true) {
        cin >> player2Archetype;
        if (player2Archetype == "Swarm" || player2Archetype == "Pyromancer") break;
        cout << "Invalid archetype. Please choose 'Swarm' or 'Pyromancer': ";
    }
}

void Game::handleBattleMove() {
    string archetype = (currentPlayer == 'X') ? player1Archetype : player2Archetype;
    bool& usedSpecial = (currentPlayer == 'X') ? player1UsedSpecial : player2UsedSpecial;

    if (archetype == "Pyromancer" && !usedSpecial) {
        cout << "Do you want to use your special move? (Y/N): ";
        char choice;
        cin >> choice;
        if (toupper(choice) == 'Y') {
            board.reset();  // Clear the board
            usedSpecial = true;
            cout << "The board has been cleared!" << endl;
            return;
        }
    }

    promptMove();
}

bool Game::winChecker(char symbol) {
    int winCombo[8][3] = {
        {0, 1, 2},
        {3, 4, 5},
        {6, 7, 8},
        {0, 3, 6},
        {1, 4, 7},
        {2, 5, 8},
        {0, 4, 8},
        {2, 4, 6}
    };

    for (auto combo : winCombo) {
        if (board.grid[combo[0]] == symbol &&
            board.grid[combo[1]] == symbol &&
            board.grid[combo[2]] == symbol) {
            return true;
        }
    }

    if (isBattleMode) {
        string archetype = (currentPlayer == 'X') ? player1Archetype : player2Archetype;

        if (archetype == "Swarm") {
            if (board.grid[0] == symbol && board.grid[2] == symbol &&
                board.grid[6] == symbol && board.grid[8] == symbol) {
                return true;  
            }
        }
    }

    return false;
}

void Game::switchPlayer() {
    currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
}

bool Game::validateInput() {
    int value;
    cout << "Enter a number between 1 and 9: ";
    
    if (!(cin >> value)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
        return false;
    }

    if (value < 1 || value > 9) {
        return false;
    }

    validInput = value; 
    return true;
}

void Game::promptMove() {
    cin.clear();
    bool valid = false;

    while (!valid) {
        cout << "\nPlayer " << (currentPlayer == 'X' ? "1" : "2") 
             << ": Enter the number you would like to make a move: ";
        
        if (validateInput()) {
            if (board.move(validInput, currentPlayer)) {
                valid = true;
            } else {
                board.display();
                cout << "Invalid input! The spot is taken! Please choose an OPEN spot!" << endl;
            }
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please pick an integer between 1 and 9. Remember integers are whole numbers!" << endl;
        }
    }
}

bool Game::playAgain() {
    while (true) {
        cin.clear();
        cout << "Do you want to play again? (Y/N): ";
        string input;
        cin >> input;
        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter 'Y' or 'N'.\n";
            continue;
        }

        char choice = toupper(input[0]);
        if (choice == 'Y') {
            counter = 0;
            player1UsedSpecial = false;
            player2UsedSpecial = false;
            return true; 
        } else if (choice == 'N') {
            cout << "Thank you for playing!\n";
            return false;  
        } else {
            cout << "Invalid input! Please enter 'Y' or 'N'.\n";
        }
    }
}

void Game::generateReport() {
    ofstream reportFile("GameReport.txt");
    if (!reportFile) {
        cerr << "Error: Could not create game report file." << endl;
        return;
    }

    reportFile << "Tic Tac Toe Game Report\n";
    reportFile << "========================\n";
    reportFile << "Total Games Played: " << totalGamesPlayed << "\n";
    reportFile << "Player 1 (X) Wins: " << player1Wins << "\n";
    reportFile << "Player 2 (O) Wins: " << player2Wins << "\n";
    reportFile << "Number of Ties: " << ties << "\n";

    reportFile.close();
    cout << "Game report has been saved to 'GameReport.txt'. Thank you for playing!" << endl;
}
