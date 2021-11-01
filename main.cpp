#include <iostream>
#include <cstdio>
#include <chrono>
#include "sudoku.h"

using namespace std;
using namespace std::chrono;

int main() {

  char board[9][9];

  /* This section illustrates the use of the pre-supplied helper functions. */
  cout << "============= Pre-supplied functions =============\n\n";

  cout << "Calling load_board():\n";
  load_board("easy.dat", board);

  cout << '\n';
	cout << "Displaying Sudoku board with display_board():\n";
  display_board(board);
  cout << "Done!\n\n";

  cout << "=================== Question 1 ===================\n\n";

  load_board("easy.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  load_board("easy-solution.dat", board);
  cout << "Board is ";
  if (!is_complete(board)) {
    cout << "NOT ";
  }
  cout << "complete.\n\n";

  cout << "=================== Question 2 ===================\n\n";

  load_board("easy.dat", board);

  // Should be OK
  cout << "Putting '1' into I8 is ";
  if (!make_move("I8", '1', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  //Test: already placed in that mini grid
  cout << "Putting '9' into E5 is ";
  if (!make_move("E5", '9', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);
  

  // Test: already filled space
  cout << "Putting '2' into B1 is ";
  if (!make_move("B1", '2', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test: illegal sudoku logic
  cout << "Putting '9' into G6 is ";
  if (!make_move("G6", '9', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Test: out of range input
  cout << "Putting '5' into X0 is ";
  if (!make_move("X0", '5', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);

  // Should be OK
  cout << "Putting '9' into F9 is ";
  if (!make_move("F9", '9', board)) {
    cout << "NOT ";
  }
  cout << "a valid move. The board is:\n";
  display_board(board);


  cout << "=================== Question 3 ===================\n\n";

  load_board("easy.dat", board);
  if (save_board("easy-copy.dat", board)) {
    cout << "Save board to 'easy-copy.dat' successful.\n";
  } else {
    cout << "Save board failed.\n";
  }
  cout << '\n';


  cout << "=================== Question 4 ===================\n\n";

  load_board("easy.dat", board);
  if (solve_board(board)) {
    cout << "The 'easy' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  load_board("medium.dat", board);
  if (solve_board(board)) {
    cout << "The 'medium' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  
  load_board("mystery1.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery1' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';
  

  load_board("mystery2.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery2' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
    // to prove a failure leads to the original board as specified in Q4
    display_board(board);
  }
  cout << '\n';

  
  load_board("mystery3.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery3' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';


  
  cout << "=================== Question 5 ===================\n\n";

  auto start1 = high_resolution_clock::now();
  int counter1 = 0;
  load_board("mystery1.dat", board);
  if (solve_board(board, counter1)) {
    cout << "The 'mystery1' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  auto stop1 = high_resolution_clock::now();
  cout << "Number of recursions used to solve mystery board 1: " << counter1 << endl;
  auto duration1 = duration_cast<microseconds>(stop1 - start1);
  cout << "Time taken to compute mystery board 1 in microseconds: " << duration1.count() << endl << endl;

  load_board("mystery2.dat", board);
  if (solve_board(board)) {
    cout << "The 'mystery2' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  auto start3 = high_resolution_clock::now();
  int counter3 = 0;  
  load_board("mystery3.dat", board);
  if (solve_board(board, counter3)) {
    cout << "The 'mystery3' board has a solution:\n";
    display_board(board);
  } else {
    cout << "A solution cannot be found.\n";
  }
  cout << '\n';

  auto stop3 = high_resolution_clock::now();
  cout << "Number of recursions used to solve mystery board 3: " << counter3 << endl;
  auto duration3 = duration_cast<microseconds>(stop3 - start3);
  cout << "Time taken to compute mystery board 3 in microseconds: " << duration3.count() << endl << endl;

  return 0;
}
