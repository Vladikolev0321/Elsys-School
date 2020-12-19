//------------------------------------------------------------------------
// NAME: Vladislav Kolev
// CLASS: XIb
// NUMBER: 7
// PROBLEM: #1
// FILE NAME: lseek.c 
// FILE PURPOSE: parser of block system
// 
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#define BUFFER 1
//------------------------------------------------------------------------
// FUNCTION 
// parsing block system
// PARAMETERS:
// int argc, char *argv[]
int main(int argc, char *argv[])
{
	if(argc < 2)
	{	
		char s1[50] = "Used: ";
		strcat(s1,argv[0]);
		write(STDOUT_FILENO, s1, strlen(s1));
		return -1;			
	}
	int fildes = open(argv[1],O_RDONLY);
	if(fildes < 0)
	{
		perror("open() failed: ");
		return -1;
	}	
				
	char buff;
	unsigned char nextElementAdress;
	for(int counter = 0; counter < 128; counter++)
	{
		read(fildes, &buff, BUFFER);
		write(STDOUT_FILENO, &buff, BUFFER);
		read(fildes, &nextElementAdress, BUFFER);
		if(nextElementAdress == 0)
		{
			break;
		}
		lseek(fildes, (int)nextElementAdress, SEEK_SET);
	}

	close(fildes);
};
