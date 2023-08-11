#include <iostream>
#include <vector>
#include <cmath>

bool findEmptyCell(const std::vector<std::vector<int>>& grid, int size, int& row, int& col);
// Function to print the Sudoku grid
void printSudoku(const std::vector<std::vector<int>>& grid, int size) {
    for (int i = 0; i < size; i++) {
        if (i % int(sqrt(size)) == 0 && i != 0) {
            std::cout << std::string(size * 4 + int(sqrt(size)) - 1, '-') << std::endl;
        }
        for (int j = 0; j < size; j++) {
            if (j % int(sqrt(size)) == 0 && j != 0) {
                std::cout << "| ";
            }
            std::cout << grid[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if it's safe to place num at grid[row][col]
bool isSafe(const std::vector<std::vector<int>>& grid, int row, int col, int num) {
    int size = grid.size();
    for (int i = 0; i < size; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }
    int regionSize = sqrt(size);
    int startRow = row - row % regionSize;
    int startCol = col - col % regionSize;
    for (int i = 0; i < regionSize; i++) {
        for (int j = 0; j < regionSize; j++) {
            if (grid[startRow + i][startCol + j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Function to solve the Sudoku puzzle using backtracking
bool solveSudoku(std::vector<std::vector<int>>& grid, int size) {
    int row, col;
    if (!findEmptyCell(grid, size, row, col)) {
        return true; // All cells are filled, puzzle is solved
    }
    for (int num = 1; num <= size; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid, size)) {
                return true;
            }
            grid[row][col] = 0; // Backtrack
        }
    }
    return false; // No solution found
}

// Function to find an empty cell in the Sudoku grid
bool findEmptyCell(const std::vector<std::vector<int>>& grid, int size, int& row, int& col) {
    for (row = 0; row < size; row++) {
        for (col = 0; col < size; col++) {
            if (grid[row][col] == 0) {
                return true; // Empty cell found
            }
        }
    }
    return false; // No empty cell found
}

int main() {
    int size;
    std::cout << "Enter Sudoku size (4, 6, 9, 12, 16): ";
    std::cin >> size;
    if (size != 4 && size != 6 && size != 9 && size != 12 && size != 16) {
        std::cout << "Invalid size." << std::endl;
        return 1;
    }

    std::vector<std::vector<int>> grid(size, std::vector<int>(size, 0));
    std::cout << "Enter Sudoku to solve (0 for empty cells):" << std::endl;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            std::cin >> grid[i][j];
        }
    }

    std::cout << "Given Sudoku:" << std::endl;
    printSudoku(grid, size);

    if (solveSudoku(grid, size)) {
        std::cout << "\n\nSolved Sudoku:" << std::endl;
        printSudoku(grid, size);
    } else {
        std::cout << "Sudoku is unsolvable." << std::endl;
    }

    return 0;
}
