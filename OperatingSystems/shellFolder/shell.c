// NAME: Vladislav Kolev
// CLASS: XIb
// NUMBER: 7
// PROBLEM: #1
// FILE NAME: shell.c
// FILE PURPOSE: to make simple command interpretator shell 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


char **parse_cmdline( const char *cmdline)
{
	char *temp_cmd_line = (char*)malloc(sizeof(cmdline)*sizeof(char));
	strcpy(temp_cmd_line, cmdline);
	//printf("%ld\n", strlen(temp_cmd_line));
	//printf("%ld\n", strlen(cmdline));
	//printf("%s\n", temp_cmd_line);

	char **cmd_args = (char**)malloc(sizeof(char*)*1);

	char *curr_tok = strtok(temp_cmd_line, " ");
	cmd_args[0] = curr_tok;
	int count = 1;

	while(1)
	{
		curr_tok = strtok(NULL, " ");
		if(curr_tok == NULL)
		{
			break;
		}
		count++;
		cmd_args = (char**)realloc(cmd_args, (count + 1)*sizeof(char*));
		cmd_args[count] = curr_tok;
		//printf("%s\n", curr_tok);
		
	}

		printf("%d\n", count);
	/*for (int i = 0; i < count; i++)
	{
		printf("%s\n", cmd_args[i]);
	}
	*/
	printf("First:%s\n", cmd_args[0]);


}


int main()
{
	write(STDOUT_FILENO, "$ ", 2);

	char *buff = malloc(500 * sizeof(char));

	while(1)
	{
		int bytesRead = read(STDIN_FILENO, buff, 500);
		if(bytesRead == 0)
		{
			break;
		}
		else if(bytesRead == -1)
		{
			perror("Reading");
		}


		char **cmd_args = parse_cmdline(buff);
	}
	
	return 0;
	
}
