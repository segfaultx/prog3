.PHONY: run clean

a17:a17.c
	cc -g -ansi -pedantic -Wall a17.c -o a17
run: a17
	valgrind -q ./a17
remove: a17
	rm a17
debug: a17
	gdb -q ./a17
