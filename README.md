This is a sudoku-solver using DFS algorithm

Usage:

Under Linux environment, just execute make command and you will get two executable file: unitest-SudokuValidator and unitest-SudokuSolver

  $ make


  ● unitest-SudokuSolver: A unitest tool for verifying sudokuSolver(...) API. Put Sudoku problem you would like to solve in file [sudoku-problem.txt]. For data format, you can refer to the original file.

  Solution will show on the screen and output into file [sudoku-solution.txt] as well.

  For Example:

    $ ./unitest-SudokuSolver

    Sudoku board get to verify:
    3 4 5 6 0 8 9 1 2
    6 0 8 9 1 2 3 4 5
    9 1 2 3 0 5 6 7 8
    1 2 3 4 5 6 7 8 9
    0 5 0 7 8 9 0 2 3
    7 8 9 1 2 3 4 0 6
    2 3 4 0 6 7 8 9 0
    0 6 7 8 9 1 2 3 4
    8 0 1 2 3 0 5 6 7

    This is a valid sudoku board!!!
    Start to solve this sudoku problem...

    Done. Result is: (Also write down in file: sudoku-solution.txt)
    3 4 5 6 7 8 9 1 2
    6 7 8 9 1 2 3 4 5
    9 1 2 3 4 5 6 7 8
    1 2 3 4 5 6 7 8 9
    4 5 6 7 8 9 1 2 3
    7 8 9 1 2 3 4 5 6
    2 3 4 5 6 7 8 9 1
    5 6 7 8 9 1 2 3 4
    8 9 1 2 3 4 5 6 7


  ● unitest-SudokuValidator: A unitest tool for verifying isValidSudoku(...) API. Put input data in file [sudoku-data.txt]. For data format, you can refer to the original file.


  For example:

    $ ./unitest-SudokuValidator

    Sudoku board get to verify:
    3 4 5 6 7 8 9 1 2
    6 7 8 9 1 2 3 4 5
    9 1 2 3 4 5 6 7 8
    1 2 3 4 5 6 7 8 9
    4 5 6 7 8 9 1 2 3
    7 8 9 1 2 3 4 5 6
    2 3 4 5 6 7 8 9 1
    5 6 7 8 9 1 2 3 4
    8 9 1 2 3 4 5 6 7

    This is a valid sudoku board!!!


  You can execute make clean to remove all execution files.
