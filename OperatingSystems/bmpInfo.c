#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>

#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER 1024

int main(int argc, char* argv[])
{
	if(argc < 2)
	{			
		printf("Usage: %s\n",argv[0]);
		return -1;			
	}	



	int fildes = open(argv[1],O_RDONLY);
	if(fildes < 0)
	{
		perror("open() failed: ");
		return -1;
	}
	int nread;
	char buf[BUFFER + 1] = {0};
	while((nread = read(fildes,buf,BUFFER)) > 0)
	{
		buf[nread] = 0;
		printf("%s", buf);
	}
		
	close(fildes);
	
}
