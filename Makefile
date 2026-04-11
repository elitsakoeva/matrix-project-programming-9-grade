main: matrix.h matrix.c basic_options.c matrix_operations.c
	gcc matrix.c basic_options.c matrix_operations.c -o main.exe

main-run: main
	./main.exe

test: matrix.h tests.c basic_options.c matrix_operations.c
	gcc tests.c basic_options.c matrix_operations.c -o test.exe

test-run: test
	./test.exe

clean:
	del *.exe
