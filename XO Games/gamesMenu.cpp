#include <iostream>
#include "../include/BoardGame_Classes.hpp"
#include "pyramicTicTacToeBoard.cpp"
#include "Player.cpp"
#include "GameManager.cpp"
#include "RandomPlayer.cpp"
#include "X_O_5_5_Board.cpp"
#include "fourInRowBoard.cpp"
#include <thread>
#include <chrono>
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

//------------------------------------- First Game -----------------------------------------
void pyramicTicTacToeMenu()
{
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');
cout << YELLOW
    <<  "               .\n"
        "              /=\\\n"
        "             /===\\ \\\n"
        "            /=====\\' \\\n"
        "           /=======\\'' \\\n"
        "          /=========\\ ' '\\\n"
        "         /===========\\''   \\\n"
        "        /=============\\ ' '  \\\n"
        "       /===============\\   ''  \\\n"
        "      /=================\\ ' ' ' \\\n"
        "     /===================\\' ' '  ' \\\n"
        "    /=====================\\' '   ' ' \\\n"
        "   /=======================\\  '   ' /\n"
        "  /=========================\\   ' /\n"
        " /===========================\\'  /\n"
        "/=============================\\/ \n" RESET;

    cout << MAGENTA << "Welcome to Pyramic Tic Tac Toe Game. :)\n";
    cout << GREEN << "[+]" RESET; cout << YELLOW <<"[1] Play with computer\n" RESET;
    cout << GREEN << "[+]" RESET; cout << YELLOW <<"[2] Play with your friend\n" RESET;
    cout << CYAN << "> " RESET;
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
//___________________________________________________________________________________________

//------------------------------------ Second Game ------------------------------------------
void fourInRowMenu() {
    int choice;
    Player* players[2];
    players[0] = new Player (1, 'x');

    cout << RED <<
                " _  _        __  .__   __.         ___     \n"
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
//___________________________________________________________________________________________

//------------------------------------- Third Game ------------------------------------------
void X_O_5_5_Menu()
{
    int choice;
    Player *players[2];
    players[0] = new Player(1, 'x');
    cout << CYAN
    <<  " ____           ____    _____ _        _____            _____          \n"
        "| ___|  __  __ | ___|  |_   _(_) ___  |_   _|_ _  ___  |_   _|__   ___ \n"
        "|___ \\  \\ \\/ / |___ \\    | | | |/ __|   | |/ _` |/ __|   | |/ _ \\ / _ \\\n"
        " ___) |  >  <   ___) |   | | | | (__    | | (_| | (__    | | (_) |  __/\n"
        "|____/  /_/\\_\\ |____/    |_| |_|\\___|   |_|\\__,_|\\___|   |_|\\___/ \\___|\n" RESET;

    cout << MAGENTA << "Welcome to 5x5 Tic Tac Toe Game. :)\n";
    cout << GREEN << "[+]" RESET; cout << YELLOW <<"[1] Play with computer\n" RESET;
    cout << GREEN << "[+]" RESET; cout << YELLOW <<"[2] Play with your friend\n" RESET;
    cout << CYAN << "> " RESET;
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
//___________________________________________________________________________________________

// function for typing animation in the output
void typeText(const string& text, int millisecondsPerChar) {
    for (char c : text) {
        cout << MAGENTA << c << RESET << flush;
        this_thread::sleep_for(chrono::milliseconds(millisecondsPerChar));
    }
}

// function to display game rules
bool rulesOfGames() {
    int choice;
    int delayRulesMsg = 25; // delay for the welcome message at the end
    string rulesMsg = "Choose game you want to know the rules of:\n";
    while (true) {
        typeText(rulesMsg, delayRulesMsg);
        cout << GREEN << "[+]" RESET; cout << BLUE << "[1] Rules of Pyramic Tic Tac Toe\n" RESET;
        cout << GREEN << "[+]" RESET; cout << BLUE << "[2] Rules of Four In A Row\n" RESET;
        cout << GREEN << "[+]" RESET; cout << BLUE << "[3] Rules of 5x5 Tic Tac Toe\n" RESET;
        cout << GREEN << "[+]" RESET; cout << BLUE << "[4] Back to Main Menu\n" RESET;
        cout << CYAN << "> " RESET;
        cin >> choice;
        if (choice == 1) {
            cout << GREEN << "\nThe normal rules of X/O but the board is in the shape of a pyramid.\n\n";
        } else if (choice == 2) {
            cout << GREEN << "\nThe first player places an X in the bottom square of any column. Taking turns, players make their mark in any column, as long as it is in the lowest square possible. See the image below for an example of possible first six moves.\nThe first player to get four-in-a-row vertically, horizontally, or diagonally wins.\n\n";
        } else if (choice == 3) {
            cout << GREEN << "\nPlayers take turns placing an X or an O in one of the squares until all the squares except one are filled. (Each player has 12 turns for a total of 24 squares.)\nCount the number of three-in-a-rows each player has. Sequences can be vertically, horizontally, or diagonally. Whoever has the most, wins. Can one mark be counted in more than one three-in-a-row sequence? Decide ahead of time, yes or no. It is easier in implementation to allow counting more than once.\n\n";
        } else if (choice == 4) {
            return true;
        }
    }
}

int main() {
    int delayWelcomeMsg = 30; // delay for the welcome message
    string welcomeMsg = "Welcome to the Definitive Edition of X/O Games.\nChoose the game you want to play:\n";
    int number;
    while (true) {
        typeText(welcomeMsg, delayWelcomeMsg);
        cout << GREEN << "[+]" RESET; cout << YELLOW << "[1] Pyramic Tic Tac Toe\n" RESET;
        cout << GREEN << "[+]" RESET; cout << YELLOW << "[2] Four In A Row\n" RESET;
        cout << GREEN << "[+]" RESET; cout << YELLOW << "[3] 5x5 Tic Tac Toe\n" RESET;
        cout << GREEN << "[+]" RESET; cout << BLUE << "[4] Rules\n" RESET;
        cout << GREEN << "[+]" RESET; cout << RED << "[0] Exit\n" RESET;
        cout << CYAN << "> " RESET;
        cin >> number;
        if (number == 1) {
            pyramicTicTacToeMenu();
        } else if (number == 2) {
            fourInRowMenu();
        } else if (number == 3) {
            X_O_5_5_Menu();
        } else if (number == 4) {
            if (!rulesOfGames()) {
                break;
            }
        } else if (number == 0) {
            string thxMsg = "Thanks for playing ";
            int thxMsgDelay = 30; // delay for the thanks message at the end
            typeText(thxMsg, thxMsgDelay);
            cout << RED << "<3" RESET;
            exit(0);
        }
    }
}