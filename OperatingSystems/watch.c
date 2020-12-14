#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{

	char *p_args[argc];
	for (int i = 1; i < argc; ++i)
	{
		p_args[i-1] = argv[i];
	}
	p_args[argc-1] = NULL;
	while(1)
	{
		pid_t pid = fork();
		if(pid < 0)
		{
			perror("fork");
		}
		else if(pid == 0)
		{
			if(execvp(argv[1], p_args) == -1)
			{
				perror(argv[1]);
			}
			exit(pid);
		}
		else
		{
			int status;
			waitpid(pid, &status, 0);

			sleep(2);
		}

	}

	return 0;

}