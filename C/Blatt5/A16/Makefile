.PHONY: run clean

textfun.o: textfun.c
	cc -o -g -ansi -pedantic -Wall textfun.c -o textfun.o

compile: textfun.c
	cc -g -ansi -pedantic -Wall textfun.c -o textfun

run: textfun
	./textfun
