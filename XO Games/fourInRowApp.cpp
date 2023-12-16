// Four-In-A-Row Game
// Author:  Seif Khaled
// Date:    15/12/2023
// Version: 1

#include <iostream>
#include"../include/BoardGame_Classes.hpp"
#include"GameManager.cpp"
#include"Player.cpp"
#include"fourInRowBoard.cpp"
#include"RandomPlayer.cpp"
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

int main() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << RED << " _  _        __  .__   __.         ___     \n"
                "| || |      |  | |  \\ |  |        /   \\    \n"
                "| || |_     |  | |   \\|  |       /  ^  \\   \n"
                "|__   _|    |  | |  . `  |      /  /_\\  \\  \n"
                "   | |      |  | |  |\\   |     /  _____  \\ \n"
                "   |_|      |__| |__| \\__|    /__/     \\__\\\n" RESET;
    cout << BLUE << "                                           \n"
                ".______        ______    ____    __    ____ \n"
                "|   _  \\      /  __  \\   \\   \\  /  \\  /   / \n"
                "|  |_)  |    |  |  |  |   \\   \\/    \\/   /  \n"
                "|      /     |  |  |  |    \\            /   \n"
                "|  |\\  \\----.|  `--'  |     \\    /\\    /    \n"
                "| _| `._____| \\______/       \\__/  \\__/     \n" << RESET;


    cout << MAGENTA << "Welcome to Four-In-A-Row Game. :)\n";
    cout << GREEN << "[+]" RESET; cout << YELLOW <<"[1] Play with computer\n" RESET;
    cout << GREEN << "[+]" RESET; cout << YELLOW <<"[2] Play with your friend\n" RESET;
    cout << CYAN << "> " RESET;
    cin >> choice;
    if (choice != 1)
        players[1] = new Player (2, 'o');
    else
        //Player pointer points to child
        players[1] = new RandomPlayer ('o', 3);

    GameManager x_o_game (new fourInRowBoard(), players);
    x_o_game.run();
    system ("pause");
}
