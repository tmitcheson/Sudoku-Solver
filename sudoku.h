#ifndef SUDOKU_H
#define SUDOKU_H

const int MAX_LENGTH = 80;

void load_board(const char* filename, char board[9][9]);
void display_board(const char board[9][9]);
bool is_complete(const char board[9][9]);
bool make_move(const char position[3], const int digit, char board[9][9]);
bool check_input(const char input[3]);
bool check_logic(const char position[3], const int digit, const char board[9][9]);
bool mini_grid_check(const int digit, const char board[9][9], const int grid_row, const int grid_col);
void update_board(const char position[3], const int digit, char board[9][9]);
bool save_board(const char* filename, const char board[9][9]);
void empty_square(char &row, char &col, const char board[9][9]);
bool solve_board(char board[9][9]);
bool solve_board(char board[9][9], int& counter);

#endif
