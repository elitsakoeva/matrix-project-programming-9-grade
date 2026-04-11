main: matrix.h matrix.c printing.c operations.c
	gcc matrix.c printing.c operations.c -o main.exe

main-run: main
	./main.exe

test: matrix.h tests.c printing.c operations.c
	gcc tests.c printing.c operations.c -o test.exe

test-run: test
	./test.exe

clean:
	del *.exe
