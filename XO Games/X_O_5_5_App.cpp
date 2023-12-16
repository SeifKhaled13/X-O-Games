// Class definition for XO_App class
// Author:  Mohammad El-Ramly
// Date:    10/10/2022
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "GameManager.cpp"
#include "player.cpp"
#include "X_O_Board.cpp"
#include "RandomPlayer.cpp"
#include "X_O_5_5_Board.cpp"
using namespace std;

/* --- Define Color Codes --- */
#define RESET   "\x1B[0m"
#define RED     "\x1B[31m"
#define GREEN   "\x1B[32m"
#define YELLOW  "\x1B[33m"
#define BLUE    "\x1B[34m"
#define MAGENTA "\x1B[35m"
#define CYAN    "\x1B[36m"
#define WHITE   "\x1B[37m"

int main()
{
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');

    cout << "Welcome to FCAI X-O Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 3);

    GameManager x_o_game(new X_O_5_5_Board(), players);
    x_o_game.run();
    system("pause");
}
