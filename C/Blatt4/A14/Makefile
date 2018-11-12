.PHONY: run clean

a14: a14.c
	cc -g -ansi -pedantic -Wall a14.c -o a14
run: a14
	valgrind -q ./a14
remove: a14
	rm a14
debug: a14
	gdb -q a14
