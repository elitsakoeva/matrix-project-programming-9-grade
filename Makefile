main: matrix.h matrix.c printing.c add.c subtract.c multiply.c transpose.c
	gcc matrix.c printing.c add.c subtract.c multiply.c transpose.c -o main.exe

main-run: main
	./main.exe

test: tests.c matrix.h add.c subtract.c multiply.c transpose.c 
	gcc tests.c add.c subtract.c multiply.c transpose.c -o test.exe

test-run: test
	./test.exe

clean:
	del *.exe
