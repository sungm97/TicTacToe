#include <iostream>
#include "game.hpp"

using namespace std;

int main() {
    bool running = true;

    while (running) {
        cout << "Welcome to Tic Tac Toe!" << endl;
        cout << "Choose your game mode:" << endl;
        cout << "1. Regular Tic Tac Toe" << endl;
        cout << "2. Battle Tic Tac Toe" << endl;
        cout << "3. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1) {
            Game game;
            game.start();  // Regular mode (as in portfolio one)
        } else if (choice == 2) {
            Game battleGame(true);  // Battle mode
            battleGame.start();
        } else if (choice == 3) {
            cout << "Thank you for playing Tic Tac Toe!" << endl;
            running = false;
        } else {
            cout << "Invalid choice. Please select a valid option." << endl;
        }
    }

    return 0;
}