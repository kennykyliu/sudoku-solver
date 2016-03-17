#include "sudoku-validator.h"

void clearVecHelper(vector<int>& vec) {
    for (int i = 0; i < vec.size(); ++i) {
        vec[i] = 0;
    }
}

bool verifySingleLine(vector<int>& board) {
    vector<bool> numExist(10, false);

    for (int i = 0; i < board.size(); ++i) {
        if (numExist[board[i]]) {
            return false;
        }
        numExist[board[i]] = true;
    }

    return true;
}

void grabBlockNum(vector<vector<int> >& board, int rowStart, int colStart, vector<int>& nums) {
    int idx = 0;

    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            nums[idx++] = board[i][j];
        }
    }
}

bool isValidSudoku(vector<vector<int> >& board) {
    int row_size = board.size();
    int col_size = board[0].size();

    // Check each row
    for (int i = 0; i < row_size; ++i) {
        if (!verifySingleLine(board[i])) {
            return false;
        }
    }

    // Check each column
    vector<int> vec2Verify(10, 0);
    for (int j = 0; j < col_size; ++j) {
        // Grab number from each column
        for (int i = 0; i < row_size; ++i) {
            vec2Verify[i] = board[i][j];
        }

        // Verify it
        if (!verifySingleLine(vec2Verify)) {
            return false;
        }
        clearVecHelper(vec2Verify);
    }

    // Check each block
    for (int i = 0; i < row_size; i += 3) {
        for (int j = 0; j < col_size; j += 3) {
            // Grab number from each column
            grabBlockNum(board, i, j, vec2Verify);
            // Verify it
            if (!verifySingleLine(board[i])) {
                return false;
            }
            clearVecHelper(vec2Verify);
        }
    }

    return true;
}
