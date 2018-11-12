.PHONY: run clean

a13: a13.c
	cc -g -ansi -pedantic -Wall a13.c -o a13
run: a13
	valgrind --leak-check=full ./a13
remove: a13
	rm a13
debug: a13
	gdb -q a13
