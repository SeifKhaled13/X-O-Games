#include "../include/BoardGame_Classes.hpp"
#include <iostream>
#include <random>
#include <iomanip>
#include <algorithm>
using namespace std;
X_O_5_5_Board::X_O_5_5_Board()
{
    n_rows = n_cols = 5;
    board = new char *[n_rows];
    for (int i = 0; i < n_rows; i++)
    {
        board[i] = new char[n_cols];
        for (int j = 0; j < n_cols; j++)
            board[i][j] = 0;
    }
}
// Return true  if move is valid and put it on board
// within board boundaries in empty cell
// Return false otherwise
bool X_O_5_5_Board::update_board(int x, int y, char mark)
{

    // Only update if move is valid
    if (!(x < 0 || x > 4 || y < 0 || y > 4) && (board[x][y] == 0))
    {
        board[x][y] = toupper(mark);
        n_moves++;
        return true;
    }
    else
        return false;
}

// Display the board and the pieces on it
void X_O_5_5_Board::display_board()
{
    for (int i : {0, 1, 2, 3, 4})
    {
        cout << "\n| ";
        for (int j : {0, 1, 2, 3, 4})
        {
            cout << "(" << i << "," << j << ")";
            cout << setw(4) << board[i][j] << " |";
        }
        cout << "\n-----------------------------";
    }
    cout << endl;
}

// Returns true if there is any winner
// either X or O
// Written in a complex way. DO NOT DO LIKE THIS.
int X_O_5_5_Board::num_of_3s(char x)
{

    char row_win[15], col_win[15], diag_win[12];
    int target = 0;
    char c = x;
    for (int i : {0, 1, 2, 3, 4})
    {
        for (int j = 0; j < 15; j++)
        {

            row_win[j] = board[i][0] & board[i][1] & board[i][2];
            col_win[j] = board[0][i] & board[1][i] & board[2][i];

            row_win[j] = board[i][1] & board[i][2] & board[i][3];
            col_win[j] = board[1][i] & board[2][i] & board[3][i];

            row_win[j] = board[i][2] & board[i][3] & board[i][4];
            col_win[j] = board[2][i] & board[3][i] & board[4][i];
        }
    }
    // 12 dialog
    diag_win[0] = board[0][0] & board[1][1] & board[2][2];
    diag_win[1] = board[1][1] & board[2][2] & board[3][3];
    diag_win[2] = board[2][2] & board[3][3] & board[4][4];
    diag_win[3] = board[4][0] & board[3][1] & board[2][2];
    diag_win[4] = board[3][1] & board[2][2] & board[1][3];
    diag_win[5] = board[2][2] & board[1][3] & board[0][4];
    diag_win[6] = board[2][0] & board[1][1] & board[0][2];
    diag_win[7] = board[4][2] & board[3][3] & board[2][4];
    diag_win[8] = board[4][1] & board[3][2] & board[2][3];
    diag_win[9] = board[3][2] & board[2][3] & board[1][4];
    diag_win[10] = board[3][0] & board[2][1] & board[1][2];
    diag_win[11] = board[2][1] & board[1][2] & board[0][3];
    for (int i : {0, 1, 2, 3, 4})
    {
        for (int j = 0; j < 15; j++)
        {
            if ((row_win[j] == c && (row_win[j] == board[i][0])) ||
                (col_win[j] == c && (col_win[j] == board[0][i])))
            {
                target++;
            }
        }
    }
    for (int i : {0, 1, 2, 3, 4})
    {
        for (int j : {0, 1, 2, 3, 4})
        {
            for (int k = 0; k < 12; k++)
            {

                if ((diag_win[k] == c && diag_win[k] == board[i][j]) ||
                    (diag_win[k] == c && diag_win[k] == board[i][j]))
                {
                    target++;
                }
            }
        }
    }
    return target;
}
bool X_O_5_5_Board::is_winner()
{
    if (num_of_3s('X') > num_of_3s('O') && n_moves == 24)
    {
        return true;
    }
    else
        return false;
}
bool X_O_5_5_Board::is_draw()
{
    if (num_of_3s('X') == num_of_3s('O') && n_moves == 24)
    {
        return true;
    }
    else
        return false;
}
bool X_O_5_5_Board::game_is_over()
{
    return n_moves >= 24;
}