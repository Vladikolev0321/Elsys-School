all: miners

miners.o: miners.c
			gcc -Wall -Werror -Wpedantic -std=c11 -lm -pthread miners.c

miners: miners.o
				gcc -Wall -Werror -Wpedantic -std=c11 -lm -pthread miners.o miners