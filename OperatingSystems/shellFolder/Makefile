all: shell

tail.o: shell.c
	gcc -Wall -pedantic -std=c11 -c shell.c

tail: shell.o
	gcc -Wall -pedantic -std=c11 shell.o -o shell