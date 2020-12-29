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

// FUNCTION: char **parse_cmdline
// parses the given string cmdline into an array of strings by " " 
//and returns the new array
// PARAMETERS:const char *cmdline - this is the given string

char **parse_cmdline( const char *cmdline )
{
	int lenght = strlen(cmdline);

	int count_args = 1;
	for(int i = 0; i < lenght; i++)
	{
		if(cmdline[i] == ' ')
		{
			count_args++;
		}
	}

	char **cmd_args = (char **) malloc((count_args+1) * sizeof(char *));

	int counter = 0;
	int arg_index = 0;
	char *curr_tok;
	int curr_tok_size = 0;
	int was_space = 0;
	while(counter < lenght+1)
	{
		if((cmdline[counter] == ' ' || cmdline[counter] == '\0') && was_space == 0)
		{
			curr_tok[curr_tok_size] = '\0';
			cmd_args[arg_index] = malloc((strlen(curr_tok)+1)* sizeof(char));
			strcpy(cmd_args[arg_index], curr_tok);
			free(curr_tok);
			arg_index++;
			curr_tok_size = 0;
			if(cmdline[counter] == ' ')
			{
				was_space = 1;
			}
		}
		else
		{
			if(cmdline[counter] == ' ' && cmdline[counter+1] == ' ')
			{
				was_space = 1;
			}
			else
			{
				was_space = 0;
			}
			if(counter != lenght)
			{
				if(curr_tok_size == 0)
				{
					curr_tok = (char *) malloc(sizeof(char) * 1);
				}
				curr_tok[curr_tok_size] = cmdline[counter];
				curr_tok_size++;
				curr_tok = (char*)realloc(curr_tok, (curr_tok_size+1)*sizeof(char));
			}
			
		}
		counter++;
	}
	cmd_args[count_args] = NULL;

	/*printf("%d\n", arg_index);
	for (int i = 0; i < arg_index; i++)
	{
		printf("%s:%ld\n", cmd_args[i], strlen(cmd_args[i]));
	}
	*/
	

	return cmd_args;
}


/*char **parse_cmdline2( const char *cmdline)
{

	char *temp_cmd_line = (char*)malloc((strlen(cmdline)+1)*sizeof(char));
	strcpy(temp_cmd_line, cmdline);

	char **cmd_args = (char**)malloc(sizeof(char*)*1);

	char *curr_tok = strtok(temp_cmd_line, " ");
	cmd_args[0] = curr_tok;
	int count = 1;

	
	////Count segm
	////Allocate space 
	///

	while(1)
	{
		curr_tok = strtok(NULL, " ");
		if(curr_tok == NULL)
		{
			break;
		}
		cmd_args = (char**)realloc(cmd_args, (count+1) * sizeof(char*));
		//cmd_args[count] = (char*)malloc((strlen(cmdline)+1) * sizeof(char));
		cmd_args[count] = curr_tok;
		count++;
		//printf("%s\n", curr_tok);
		//printf("%ld\n", sizeof(curr_tok));
		
	}

	cmd_args = (char**)realloc(cmd_args, (count+1) * sizeof(char*));
	cmd_args[count] = NULL;



	//printf("%d\n", count);
	//for (int i = 0; i < count; i++)
	//{
	//	printf("%s\n", cmd_args[i]);
	//}
	
	
	//printf("first:%s", cmd_args[0]);
	//printf("%ld\n", strlen(cmd_args[0]));
	//temp_cmd_line = NULL;
	//free(temp_cmd_line);
	return cmd_args;
}
*/
// FUNCTION: void free_memory
//frees the memory used by the array of strings cmd_args
// PARAMETERS:char **cmd_args - the array of strings to be freed
void free_memory(char **cmd_args)
{
	for (int i = 0; cmd_args[i] != NULL; i++)
		{
			free(cmd_args[i]);
		}
		free(cmd_args);
}

// FUNCTION: void run_command
// creates a process and tries to execute the command
// PARAMETERS: const char *file_name - the path of file used in
//first parameter of execv
// char **cmd_args - array of arguments used in the second parameter
//of execv
void run_command(const char *file_name, char **cmd_args)
{
	pid_t pid = fork();

	if(pid < 0)
	{
		perror("fork");
		//
		free_memory(cmd_args);
		//free(file_name);
		//exit(pid);
	}
	else if(pid == 0)
	{
		if(execv(file_name, cmd_args) == -1)
		{
			perror(file_name);
			free_memory(cmd_args);

			//free_memory(cmd_args);
			//free(file_name);
			exit(-1);
		}
		exit(pid);
	}
	else if(pid > 0)
	{
		int status;
		if(waitpid(pid, &status, 0) == -1)
		{
			perror("wait");
			free_memory(cmd_args);

			//
			//free_memory(cmd_args);
			//free(file_name);
		}
	}
}
// FUNCTION: int main
// reads from the standart input using getline
// and invokes the other functions 
int main()
{

	while(1)
	{
		char *buff = malloc(500 * sizeof(char));

		write(STDOUT_FILENO, "$ ", 2);
		//write(STDOUT_FILENO, "\n", 1);
		//putchar('\n');
		//printf("%s\n", );

		size_t size = 500;
		//int bytesRead = read(STDIN_FILENO, buff, 500);
		int bytesRead = getline(&buff, &size, stdin);
		if(bytesRead == 0)
		{
			free(buff);
			break;
		}
		if(bytesRead == -1)
		{
			free(buff);
			//perror("Reading");
			break;
		}

		if(buff[0] == '\n')
		{
				free(buff);
				continue;
		}
	
				char *buff_without_new_line;
				if(buff[bytesRead-1] != '\n')
				{
					buff_without_new_line = malloc((bytesRead+1)*sizeof(char));
					memcpy(buff_without_new_line, buff, bytesRead);
					//printf("%s\n", buff_without_new_line);
					buff_without_new_line[bytesRead] = '\0';
				}
				else
				{
					buff_without_new_line = malloc(bytesRead*sizeof(char));
					memcpy(buff_without_new_line, buff, bytesRead-1);
					buff_without_new_line[bytesRead-1] = '\0';
				}

			



			char **cmd_args = parse_cmdline(buff_without_new_line);

			free(buff);
			free(buff_without_new_line);

			run_command(cmd_args[0], cmd_args);
			/*for (int i = 0; i < 1; i++)
			{
			printf("El[%d]%s\n", i,cmd_args[i]);
			}
			*/

		
			free_memory(cmd_args);
		
		
		
		
	}


	
	return 0;
	
}