CC = g++

all: unitest

unitest: sudoku-validator.o
	$(CC) unitest-SudokuValidator.cpp sudoku-validator.o -o unitest-SudokuValidator

sudokuVlidator:
	$(CC) -c sudoku-validator.cpp

clean:
	rm -f *.o *.out unitest-SudokuValidator sudoku-validator
