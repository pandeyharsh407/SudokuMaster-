# SudokuSolverPlusPlus
## Sudoku Solver

Author: Harsh Pandey
Email: pandeyharsh407@gmail.com

## Description
Sudoku Solver is a C++ program that allows users to input Sudoku puzzles of different sizes (4x4, 6x6, 9x9, 12x12, 16x16) and attempts to solve them using a backtracking algorithm. The program provides a command-line interface for user interaction.

## Technologies Used
- C++ programming language
- Standard Template Library (STL) in C++
- Backtracking algorithm for solving Sudoku puzzles

## Algorithm
1. The program starts by taking user input for the size of the Sudoku puzzle (4, 6, 9, 12, or 16).
2. If the chosen size is not valid, an error message is displayed.
3. The program then prompts the user to input the initial Sudoku puzzle values, with '0' representing empty cells.
4. The given Sudoku puzzle is displayed in a styled grid format.
5. The backtracking algorithm is used to solve the Sudoku puzzle recursively:
   - The `solveSudoku` function attempts to place numbers in empty cells and backtrack if a solution is not possible.
   - The `isSafe` function checks if it's safe to place a number in a particular cell.
   - The `findEmptyCell` function finds an empty cell in the puzzle to start solving from.
6. If a solution is found, the solved Sudoku puzzle is displayed in the same styled grid format.
7. If no solution is found, a message indicating that the Sudoku puzzle is unsolvable is displayed.

## How to Use
1. Clone this repository to your local machine.
2. Compile the `sudoku_solver.cpp` file using a C++ compiler.
3. Run the compiled executable.
4. Enter the size of the Sudoku puzzle and provide the initial values.
5. The program will display the given and solved Sudoku puzzles.
