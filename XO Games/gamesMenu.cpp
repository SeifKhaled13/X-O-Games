#include <iostream>
#include "../include/BoardGame_Classes.hpp"
#include "pyramicTicTacToeBoard.cpp"
#include "Player.cpp"
#include "GameManager.cpp"
#include "RandomPlayer.cpp"
#include "X_O_5_5_Board.cpp"
#include "fourInRowBoard.cpp"
using namespace std;

//------------------------------------- First Game -----------------------------------------
void pyramicTicTacToeMenu()
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
//___________________________________________________________________________________________

//------------------------------------ Second Game ------------------------------------------
void fourInRowMenu() {
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
//___________________________________________________________________________________________

//------------------------------------- Third Game ------------------------------------------
void X_O_5_5_Menu()
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
//___________________________________________________________________________________________
int main()
{
    cout << "hello user please choose one game from these games : " << endl;
    cout << "1 - pyramic tic tac toe" << endl;
    cout << "2 - four in row " << endl;
    cout << "3 - 5x5 XO " << endl;
    int number;
    cin >> number;
    if (number == 1)
    {
        pyramicTicTacToeMenu();
    }
    else if (number == 2)
    {
        fourInRowMenu();
    }
    else if (number == 3)
    {
        X_O_5_5_Menu();
    }
}