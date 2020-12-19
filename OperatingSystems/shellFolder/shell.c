// NAME: Vladislav Kolev
// CLASS: XIb
// NUMBER: 7
// PROBLEM: #1
// FILE NAME: shell.c
// FILE PURPOSE: to make simple command interpretator shell 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
	char *str = malloc(500 * sizeof(char));

	while(1)
	{
		if(read(STDIN_FILENO, str, 500) == 0)
		{
			break;
		}
	}
	
	printf("%s",str);
	return 0;
	
}
