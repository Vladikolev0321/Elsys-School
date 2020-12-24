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
#include <sys/types.h>
#include <sys/wait.h>


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

	//printf("%ld\n", sizeof(char*));
	while(1)
	{
		curr_tok = strtok(NULL, " ");
		if(curr_tok == NULL)
		{
			break;
		}
		cmd_args = (char**)realloc(cmd_args, (count+1) * sizeof(char*));
		cmd_args[count] = curr_tok;
		count++;
		//printf("%s\n", curr_tok);
		//printf("%ld\n", sizeof(curr_tok));
		
	}

	cmd_args = (char**)realloc(cmd_args, (count+1) * sizeof(char*));
	cmd_args[count] = NULL;
	////Problem with longer commands realloc();
	////Should do the parsing part with getline maybe
	//// not strtok


	/*printf("%d\n", count);
	for (int i = 0; i < count; i++)
	{
		printf("%s\n", cmd_args[i]);
	}
	*/
	
	
	//printf("Second:%s\n", cmd_args[1]);
	
	return cmd_args;
}
void run_command(const char *file_name, char **cmd_args)
{
	pid_t pid = fork();

	if(pid < 0)
	{
		perror("fork");
	}
	else if(pid == 0)
	{
		if(execv(file_name, cmd_args) == -1)
		{
			perror(file_name);
		}
		exit(pid);
	}
	else if(pid > 0)
	{
		int status;
		if(waitpid(pid, &status, 0) == -1)
		{
			perror("wait");
		}
	}
	////////Should i add NULL at the end of 2nd arg
	/// of execv
}

int main()
{

	char *buff = malloc(500 * sizeof(char));
	/////Try reading with getline
	while(1)
	{
		write(STDOUT_FILENO, "$ ", 2);

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

		run_command(cmd_args[0], cmd_args);
		/*for (int i = 0; i < 3; i++)
		{
			printf("%s\n", cmd_args[i]);
		}
		*/
		free(cmd_args);
		//////free buffer
	}


	
	return 0;
	
}
