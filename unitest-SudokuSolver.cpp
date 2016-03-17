#include "util.h"
#include "sudoku-validator.h"
#include "sudoku-solver.h"

int main() {
    ifstream dataFile;
    dataFile.open("sudoku-problem.txt");
    vector<vector<int> > board(9, vector<int>(9, 0));
    int row = 0;
    int col = 0;
    int num = 0;

    if (!dataFile.good()) {
        cout << "Fail to open file [sudoku-data.txt]." << endl;
        return -1;
    }

    while (row < 9 && col < 9 && dataFile >> num) {
        board[row][col++] = num;
        // Reset column index, get data for next row
        if (col == 9) {
            row++;
            col = 0;
        }
    }

    // Got all data
    if (row == 9) {
        cout << "Sudoku board get to verify: " << endl;
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
    } else {
        cout << "Invalid data inside sudoku-data.txt";
        return -2;
    }
    cout << endl;
    // Call function for verification
    int ret = isValidSudoku(board);
    
    if (ret) {
        cout << "This is a valid sudoku board!!!" << endl;
        cout << "Start to solve this sudoku problem..." << endl << endl;
        sudokuSolver(board);
        cout << "Done. Result is: (Also write down in file: sudoku-solution.txt)" << endl;
        ofstream solFile;
        solFile.open("sudoku-solution.txt");
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cout << board[i][j] << " ";
                solFile << board[i][j] << " ";
            }
            cout << endl;
            solFile << endl;
        }
        cout << endl << endl;
        solFile.close();
    } else {
        cout << "Fail!!! This is not a valid sudoku board." << endl;
    }

    return 0;
}
