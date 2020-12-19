#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFF 1

int main(int argc, char *argv[])
{
	if(argc < 3)
	{
		perror("Used: ./a.out");
		return -1;	
	}

	int fildes1 = open(argv[1], O_RDONLY);
	int fildes2 = open(argv[2], O_WRONLY);

	if(fildes1 == -1)
	{
		perror("Error while opening file1");
		return -1;
	}
	
	if(fildes2 == -1)
	{
		perror("Error while opening file2");
		return -1;	
	}


//	char buff;
	//char buff[1] = {0};
	char buff[BUFF + 1] = {0};
	int bytes_read;
	int bytes_write;
		

	while(bytes_read  = read(fildes1, buff, BUFF) > 0)
	{
		bytes_write = write(fildes2, buff, BUFF);
		//buff[bytes_read] = 0;
		if(bytes_write == -1)
		{
			perror("Error while writing in file2");
			return -1;

		}

	}

	close(fildes1);
	close(fildes2);

	



}
