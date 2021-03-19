#include <stdio.h>
#include <unistd.h>

int main()
{
	char buff[500];
	read(STDIN_FILENO, buff, 500);



	int fd = open("output.txt", O_WRONLY | O_TRUNC);
	printf("%s\n", buff);

}