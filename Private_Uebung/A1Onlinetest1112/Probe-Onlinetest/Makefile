CC=gcc -ansi -g -Wall -ansi -pedantic
CFLAGS=-ansi -g -Wall -ansi -pedantic

dummy:
	@echo "Geben Sie \"make ai\" ein, um Aufgabe i zu erstellen"
	@echo "          \"ai\", um ai laufen zu lassen"
	@echo  "         \"valgrind ai\",um ai mit valgrind laufen zu lassen"
	
a1: a1.c a1.h runa1.o t.o
	$(CC) $(CFLAGS) a1.c runa1.o t.o -o a1
	
a2: a2.c a2.h runa2.o t.o
	$(CC) $(CFLAGS) a2.c runa2.o t.o -o a2
	
tests:
	a1
	a2
	
all: a1 a2 # bewusst nicht erstes Ziel

.PHONY: clean

clean:
	-/bin/rm a1 a2

%.o : %.c
	$(CC) -c $(CFLAGS) $< -o $@
	
%.o : %.c %.h
	$(CC) -c $(CFLAGS) $< -o $@	