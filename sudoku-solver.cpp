#include "sudoku-solver.h"

bool sudokuSolverDFS(vector<vector<int> >& board, int rowStartPos, int colStartPos) {
    if (rowStartPos == 9) {
        return true;
    }

    // Already finish this row, go to solve next row
    if (colStartPos >= 9) {
        return sudokuSolverDFS(board, rowStartPos + 1, 0);
    }

    // No data here, we need find a number to fill it up
    if (board[rowStartPos][colStartPos] == 0) {
        // Using DFS to list all possibilities (1 ~ 9)
        for (int i = 1; i <= 9; ++i) {
            board[rowStartPos][colStartPos] = i;
            if (isValidSudoku(board)) {
               // Backtracking, because we already got answer of this row
                if (sudokuSolverDFS(board, rowStartPos, colStartPos + 1)) {
                    return true;
                }
            }
            // This i is not the valid possibility, try to use next one
            board[rowStartPos][colStartPos] = 0;
        }
    } else {
        // It already has data in board[rowStartPos][colStartPos]
        // Keep to handle next coordinate at board[rowStartPos][colStartPos + 1]
        return sudokuSolverDFS(board, rowStartPos, colStartPos + 1);
    }
    return false;
}

void sudokuSolver(vector<vector<int> >& board) {
    sudokuSolverDFS(board, 0, 0);
}
