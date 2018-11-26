.PHONY: run clean
ARGS=kunft=yo haus=unterkunft

a20: textfun.o main.o
	cc -g -ansi -pedantic -Wall *.o -o a20

main.o: main.c
	cc -c  main.c

textfun.o: textfun.c textfun.h
	cc -c  textfun.c

run: a20
	valgrind ./a20 $(ARGS)
