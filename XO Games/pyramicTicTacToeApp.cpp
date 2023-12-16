#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include "pyramicTicTacToeBoard.cpp"
#include "Player.cpp"
#include "GameManager.cpp"
#include "RandomPlayer.cpp"

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

    cout << "Welcome to  Pyramic Game. :)\n";
    cout << "Press 1 if you want to play with computer: ";
    cin >> choice;
    if (choice != 1)
        players[1] = new Player(2, 'o');
    else
        // Player pointer points to child
        players[1] = new RandomPlayer('o', 3);

    GameManager pyramic_game(new pyramicTicTacToeBoard(), players);
    pyramic_game.run();
    system("pause");
}