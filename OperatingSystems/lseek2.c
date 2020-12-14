#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdint.h>
#include <stdio.h>

#define BUFFER 1024

int main(int argc,char *argv[])
{
	if(argc < 2)
	{			
		printf("Used: %s\n",argv[0]);
		return -1;			
	}

	int fildes = open(argv[1],O_RDONLY);
	if(fildes < 0)
	{
		perror("open() failed: ");
		return -1;
	}


	int file_size = lseek(fildes,0,SEEK_END);

	printf("%d",file_size);

	close(fildes);


}
