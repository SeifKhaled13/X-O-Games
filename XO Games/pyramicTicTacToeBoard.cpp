#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
#include"../include/BoardGame_Classes.hpp"
using namespace std;

pyramicTicTacToeBoard::pyramicTicTacToeBoard()
{
    n_rows = 3;
    n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
        {
            board[i][j] = 0;
        }
    }
}

bool pyramicTicTacToeBoard::update_board(int x, int y, char mark)
{
    // Only update if move is valid
    if (!((x == 0 && y == 0) || (x == 0 && y == 1) || (x == 0 && y == 3) ||
          (x == 0 && y == 4) || (x == 1 && y == 0) || (x == 1 && y == 4)) &&
        (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

void pyramicTicTacToeBoard::display_board()
{
    cout << "                |(0, 2) " << board[0][2] << '|' << endl;
    cout << "               -----------" << endl;
    cout << "        |(1, 1) " << board[1][1] << "|(1, 2) " << board[1][2] << "|(1, 3) " << board[1][3] << '|' << endl;
    cout << "        -------------------------" << endl;
    cout << "|(2, 0) " << board[2][0] << "|(2, 1) " << board[2][1] << "|(2, 2) " << board[2][2] << "|(2, 3) ";
    cout << board[2][3] << "|(2, 4) " << board[2][4] << '|' << endl;
    cout << "------------------------------------------" << endl;
}

bool pyramicTicTacToeBoard::is_winner()
{
    char row_win[3], col_win[3], diag_win[2];
    for (int i : {0, 1, 2})
    {
        row_win[i] = board[i][0] & board[i][1] & board[i][2];
        col_win[i] = board[0][i] & board[1][i] & board[2][i];
    }
    diag_win[0] = board[0][2] & board[1][3] & board[2][4];
    diag_win[1] = board[0][2] & board[1][1] & board[2][0];

    for (int i : {0, 1, 2})
    {
        if ((row_win[i] && (row_win[i] == board[i][0])) ||
            (col_win[i] && (col_win[i] == board[0][i])))
        {
            return true;
        }
    }
    if ((diag_win[0] && diag_win[0] == board[1][3]) ||
        (diag_win[1] && diag_win[1] == board[1][1]))
    {
        return true;
    }
    return false;
}

// Return true if 9 moves are done and no winner
bool pyramicTicTacToeBoard::is_draw()
{
    return (n_moves == 9 && !is_winner());
}

bool pyramicTicTacToeBoard::game_is_over()
{
    return n_moves >= 9;
}
