// fourInRowBoard.cpp
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"../include/BoardGame_Classes.hpp"
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

// Set the board for Four-in-a-Row game
fourInRowBoard::fourInRowBoard() {
    n_rows = 6;  // Change to 6 rows
    n_cols = 7;  // Change to 7 columns
    board = new char*[n_rows];
    for (int i = 0; i < n_rows; i++) {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}

// Return true if move is valid and put it on the board
// within board boundaries in the lowest empty cell of the selected column
bool fourInRowBoard::update_board(int x, int y, char mark) {
    // Find the lowest empty square in the selected column
    for (x = 5; x >= 0; --x) {
        if (board[x][y] == 0) {
            board[x][y] = toupper(mark);
            n_moves++;
            return true;
        }
    }

    // If the column is full, return false
    return false;
}

// Return true if move is valid and put it on the board
// within board boundaries in the lowest empty cell of the selected column
void fourInRowBoard::display_board() {
    for (int i = 0; i < 6; i++) {
        cout << BLUE << "\n   |";
        for (int j = 0; j < 7; j++) {
            if (board[i][j] == 'X') {
                cout << "   \x1B[31mX   " BLUE;
            } else if (board[i][j] == 'O') {
                cout << "   \x1B[33mO   " BLUE;
            } else {
                cout << "       ";
            }
            cout << "|";
        }
        cout << BLUE << "\n   ----------------------------------------------------------" RESET;
    }

    // Display column numbers at the bottom        
    cout << BLUE << "\n=================================================================";
    cout << BLUE << "\n   |";
    for (int j = 0; j < 7; j++) {
        cout << setw(3) << j << "," << j << "  |";
    }
    cout << BLUE << "\n=================================================================" RESET;
    cout << endl;
}




// Returns true if there is any winner (four in a row vertically, horizontally, or diagonally)
bool fourInRowBoard::is_winner() {
    // Check for four in a row horizontally
    for (int i = 0; i < 6; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] != 0 && board[i][j] == board[i][j + 1] &&
                board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3]) {
                return true;
            }
        }
    }

    // Check for four in a row vertically
    for (int i = 0; i < 7; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[j][i] != 0 && board[j][i] == board[j + 1][i] &&
                board[j][i] == board[j + 2][i] && board[j][i] == board[j + 3][i]) {
                return true;
            }
        }
    }

    // Check for four in a row diagonally (left-top to right-bottom)
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j + 1] &&
                board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3]) {
                return true;
            }
        }
    }

    // Check for four in a row diagonally (right-top to left-bottom)
    for (int i = 0; i < 3; ++i) {
        for (int j = 3; j < 7; ++j) {
            if (board[i][j] != 0 && board[i][j] == board[i + 1][j - 1] &&
                board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3]) {
                return true;
            }
        }
    }

    return false;
}

// Return true if 42 moves are done and no winner (the board is full)
bool fourInRowBoard::is_draw() {
    return (n_moves == 42 && !is_winner());
}

// Return true if 42 moves are done (the board is full)
bool fourInRowBoard::game_is_over() {
    return n_moves >= 42;
}
