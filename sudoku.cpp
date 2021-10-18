#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstring>
#include <cassert>
#include "sudoku.h"

using namespace std;

/* You are pre-supplied with the functions below. Add your own 
   function definitions to the end of this file. */

/* pre-supplied function to load a Sudoku board from a file */
void load_board(const char* filename, char board[9][9]) {

  cout << "Loading Sudoku board from file '" << filename << "'... ";

  ifstream in(filename);
  if (!in) {
    cout << "Failed!\n";
  }
  assert(in);

  char buffer[512];

  int row = 0;
  in.getline(buffer,512);
  while (in && row < 9) {
    for (int n=0; n<9; n++) {
      assert(buffer[n] == '.' || isdigit(buffer[n]));
      board[row][n] = buffer[n];
    }
    row++;
    in.getline(buffer,512);
  }

  cout << ((row == 9) ? "Success!" : "Failed!") << '\n';
  assert(row == 9);
}

/* internal helper function */
void print_frame(int row) {
  if (!(row % 3)) {
    cout << "  +===========+===========+===========+\n";
  } else {
    cout << "  +---+---+---+---+---+---+---+---+---+\n";
  }
}

/* internal helper function */
void print_row(const char* data, int row) {
  cout << (char) ('A' + row) << " ";
  for (int i=0; i<9; i++) {
    cout << ( (i % 3) ? ':' : '|' ) << " ";
    cout << ( (data[i]=='.') ? ' ' : data[i]) << " ";
  }
  cout << "|\n";
}

/* pre-supplied function to display a Sudoku board */
void display_board(const char board[9][9]) {
  cout << "    ";
  for (int r=0; r<9; r++) {
    cout << (char) ('1'+r) << "   ";
  }
  cout << '\n';
  for (int r=0; r<9; r++) {
    print_frame(r);
    print_row(board[r],r);
  }
  print_frame(9);
}

/* add your functions here */


// Question 1, checks each space has a valid value between 1-9
bool is_complete(const char board[9][9]){
  for(int row = 0; row < 9; row++){
    for(int col = 0; col < 9; col++){
      if(!((board[row][col] > '0') && (board[row][col] <= '9')))
        return false;
      else return true;
    }
  }
  return true;
}

// Question 2, series of functions testing for validity, before updating board and returning true if it passes all tests

bool make_move(const char position[3], int digit, char board[9][9]){
  // valid position check (for range)
  if (!(check_input(position)))
    return false;
  
  // valid position check (for sudoku logic)
  if (!(check_logic(position, digit, board)))
    return false;

  // update board if it passes both tests
  update_board(position, digit, board);
  return true;
} 


// helper function for Q2, function for checking range validity of 'position'. Returns true if valid, and false otherwise.
bool check_input(const char input[3]){
  if(input[0] < 'A' || input[0] > 'I')
    return false;
  if(input[1] < '1' || input[1] > '9')
    return false;
  else return true;
}

// helper function for Q2, function for checking whether digit is already in specified row/column. Returns true if not, and false if it is.
bool check_logic(const char position[3], int digit, const char board[9][9]){

  int row_pos = (static_cast<int>(position[0])) - 65;
  
  for(int col = 0; col < 9; col++){
    if(board[row_pos][col] == digit)
      return false;
  }

  int col_pos = (static_cast<int>(position[1])) - 49;

  for(int row = 0; row < 9; row++){
    if(board[row][col_pos] == digit)
      return false;
  }

  return true;
}

// helper function for updating board once fail checks have been passed
void update_board(const char position[3], int digit, char board[9][9]){

  int row_pos = (static_cast<int>(position[0])) - 65;
  int col_pos = (static_cast<int>(position[1])) - 49;

  board[row_pos][col_pos] = digit;
  
  
}


// Question 3, function for outputting board into another file.
bool save_board(const char* filename, const char board[9][9]){
  
  ofstream out(filename);
  
  if(out.fail())
    return false;
  
  for(int row = 0; row < 9; row++){
    for(int col = 0; col < 9; col++){
      out.put(board[row][col]);
    }
    if(row == 8)
      break;
    out.put('\n');
  }

  out.close();

  return true;

}

