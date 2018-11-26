.PHONY: run clean

a20: textfun.o main.o
	cc -g -ansi -pedantic -Wall textfun.o main.o -o a20
textfun.o: textfun.c textfun.h
	cc -c  textfun.c
main: main.c textfun.h
	cc -c  main.c
run: a20
	valgrind -q ./a20
