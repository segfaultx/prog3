.PHONY: run clean

textfun.o: textfun.c
	cc -g -ansi -pedantic -Wall -c  textfun.c
main: main.c
	cc -g -ansi -pedantic -Wall -c  main.c

a16: textfun.o main.o
	cc -g -ansi -pedantic -Wall textfun.o main.o -o a16
run: a16
	valgrind -q ./a16 $(ARGS)
