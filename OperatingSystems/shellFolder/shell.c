// NAME: Vladislav Kolev
// CLASS: XIb
// NUMBER: 7
// PROBLEM: #1
// FILE NAME: shell.c
// FILE PURPOSE: to make simple command interpretator shell 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


char **parse_cmdline( const char *cmdline)
{
	
}


int main()
{
	write(STDOUT_FILENO, "$ ", 2);

	char *str = malloc(500 * sizeof(char));

	while(1)
	{
		int bytesRead = read(STDIN_FILENO, str, 500);
		if(bytesRead == 0)
		{
			break;
		}
		else if(bytesRead == -1)
		{
			perror("Reading");
		}
	}
	
	printf("%s",str);
	return 0;
	
}
