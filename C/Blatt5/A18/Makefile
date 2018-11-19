.PHONY: run clean

a18:a18.c
	cc -g -ansi -pedantic -D$(ARG1) -DSIZE=$(ARG2) -Wall a18.c -o a18
run: a18
	valgrind -q ./a18
remove: a18
	rm a18
debug: a18
	gdb -q ./a18
