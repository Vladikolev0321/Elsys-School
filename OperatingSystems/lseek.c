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
	////Size file

	lseek(fildes, 2, SEEK_SET);

	char buff[5];
	read(fildes,buff,4);
	
	uint32_t *size_file = (uint32_t*)buff;	
	
	////Width
	lseek(fildes,18,SEEK_SET);
	
	char width[5];
	read(fildes,width,4);
	
	////Height
	lseek(fildes,22,SEEK_SET);
	
	char height[5];
	read(fildes,height,4);

	printf("File size:%d\n",*size_file);
	printf("Width:%d\n",*(int32_t*)width);
	printf("Height:%d\n",*(int32_t*)height);

	
	close(fildes);


}
