CC = g++

all: unitest

unitest: sudoku-validator.o sudoku-solver.o
	$(CC) unitest-SudokuValidator.cpp sudoku-validator.o -o unitest-SudokuValidator
	$(CC) unitest-SudokuSolver.cpp sudoku-validator.o sudoku-solver.o -o unitest-SudokuSolver

Vlidator:
	$(CC) -c sudoku-validator.cpp

Solver:
	$(CC) -c sudoku-solver.cpp

clean:
	rm -f *.o *.out unitest-SudokuValidator unitest-SudokuSolver sudoku-validator
