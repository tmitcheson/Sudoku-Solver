#ifndef SUDOKU_H
#define SUDOKU_H

void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(const char board[9][9]);
bool make_move(const char position[3], int digit, char board[9][9]);
bool check_input(const char input[3]);
bool check_logic(const char position[3], int digit, const char board[9][9]);
void update_board(const char position[3], int digit, char board[9][9]);

#endif