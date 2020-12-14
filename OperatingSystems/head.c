#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER 1

//int main(int argc, char* argv[])
int main()
{
	int fildes = open("a.txt",O_RDONLY);
	if(fildes < 0)
	{
		perror("open() failed:");
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
