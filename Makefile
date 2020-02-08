all: generate transform solve

generate: sudoku.o generate.o
	g++ -o generate generate.o sudoku.o

transform: sudoku.o transform.o
	g++ -o transform transform.o sudoku.o

solve: sudoku.o solve.o
	g++ -o solve solve.o sudoku.o

generate.o: generate.cpp sudoku.h
	g++ -c generate.cpp

transform.o: transform.cpp sudoku.h
	g++ -c transform.cpp

solve.o: solve.cpp sudoku.h
	g++ -c solve.cpp

sudoku.o: sudoku.cpp sudoku.h
	g++ -c sudoku.cpp

clean:
	rm *.o generate transform solve
