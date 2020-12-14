#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER 1

int main(int argc, char* argv[])
{
	if(argc < 2)
	{	
		char s1[50] = "Used: ";
		strcat(s1,argv[0]);			
		//printf("Used: %s\n",argv[0]);
		write(STDOUT_FILENO, s1, strlen(s1));
		return -1;			
	}
	if(argc == 2)
	{
		int fildes = open(argv[1],O_RDONLY);
		if(fildes < 0)
		{
			perror("open() failed: ");
			return -1;
		}		
		int bytesRead;
		char buf[BUFFER + 1] = {0};

		int counter = 0;
		while((bytesRead = read(fildes,buf,BUFFER)) > 0 && counter < 10)
		{
			if(*buf == '\n')
			{
				counter++;
			}
	
		write(STDOUT_FILENO, buf, strlen(buf));	
		}

	
		close(fildes);
	}
	else
	{
		for(int i = 1;i < argc; i++)
		{	
			int fildes = open(argv[i],O_RDONLY);
			if(fildes < 0)
			{
				perror("open() failed: ");
				return -1;
			}		


			int bytesRead;
			char buf[BUFFER + 1] = {0};

		
			char s1[] = "==> ";
			strcat(s1,argv[i]);
			strcat(s1," <==\n");
			write(STDOUT_FILENO, s1, strlen(s1));
	
			//printf("==> %s <==\n",argv[i]);

		
			int counter = 0;
			while((bytesRead = read(fildes,buf,BUFFER)) > 0 && counter < 10)
			{
				if(*buf == '\n')
				{
					counter++;
				}
			write(STDOUT_FILENO, buf, strlen(buf));
			
			}
			if(i + 1 != argc)
			{		
				write(STDOUT_FILENO, "\n", 1);
			}
		close(fildes);
	}


	}
	

}
