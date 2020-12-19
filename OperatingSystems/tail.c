// NAME: Vladislav Kolev
// CLASS: XIb
// NUMBER: 7
// PROBLEM: #1
// FILE NAME: tail.c 
// FILE PURPOSE: последните 10 реда от 
//всеки файл последователно се копират
//в стандартния изход, разделени със заглавна секция.
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER 1
// FUNCTION: check_file checks if file can open and displays message;
// PARAMETERS:
// fildes - file descriptor to check if open returns -1 ; name - name of file
int check_file(int fildes,char name[])
{
	if(fildes < 0)
		{
			char str1[50] = "tail: cannot open '";
			strcat(str1, name);
			strcat(str1, "' for reading");
			perror(str1);
			return -1;
		}	
		return 1;
}
// FUNCTION: display_read_error displays read error
// PARAMETERS:
// name- name of file
void display_read_error(char name[])
{
	//tail: error reading '/tmp/'
	char str1[50] = "tail: error reading '";
	strcat(str1, name);
	strcat(str1, "'");
	perror(str1);
}
// FUNCTION: display_write_error displays error if it has problem with writing on the file
void display_write_error()
{
	perror("tail: error writing 'standard output'");
}
// FUNCTION: display_close_error displays error if it has problem with closing the file
// PARAMETERS:
// name- name of file
void display_close_error(char name[])
{
	char str1[50] = "tail: error reading '";
	strcat(str1, name);
	strcat(str1, "'");
	perror(str1);
}
// FUNCTION: write_on_close writes on console and then reads it on the output
void write_on_console()
{
	
	char *str = malloc(1 * sizeof(char));
	char buff[1];
	while(1)
	{
		int bytesRead = read(0,buff,1);
		if(bytesRead == -1)
		{
			display_read_error("standard output");
			break;
		}
		if(bytesRead == 0)
		{
			break;
		}
		strcat(str, buff);	
		str = realloc(str, (strlen(str)+strlen(buff)) * sizeof(char));
	}

	int i = 0;
	int counter = 0;
	while(i < strlen(str))
	{
		 if(str[i] == '\n')
		 {
		 	counter++;
		 }
		 i++;
	}
	if(counter <= 10)
	{
		write(STDOUT_FILENO, str, strlen(str));
	}
	else if(counter > 10)
	{
		int j = 0;
		int currCounter = 0;
		while(j < strlen(str))
		{
		
		 	if(currCounter >= counter - 10)
			{
				if(write(STDOUT_FILENO, &str[j], 1)== -1)
					{
						display_write_error();
						break;
    				}					
			}
		  	if(str[j] == '\n')
		    {
		 		currCounter++;
		  	}
			j++;
		}

	}
	free(str);

}
// FUNCTION: main it has the main functionality
int main(int argc, char *argv[])
{
	if(argc < 2){
		/*char s1[50] = "Used: ";
		strcat(s1,argv[0]);			
		write(STDOUT_FILENO, s1, strlen(s1));
		return -1;
		*/
		write_on_console();	
	}
	if(argc == 2)
	{
		if(strcmp(argv[1],"-") == 0)
		{
			write_on_console();
		}
		else	
		{
			int fildes = open(argv[1], O_RDONLY);
		if(check_file(fildes,argv[1]) != -1)
		{
			char buf[BUFFER + 1] = {0};
	
			int counter = 0;
			while(1)
			{
				/*
				if(*buf == '\n')
				{
					counter++;
				}
				*/
				int bytesRead = read(fildes,buf,BUFFER);
				if(bytesRead == 0)
				{
					break;
				}
				else if(bytesRead == -1)
				{
					display_read_error(argv[1]);
				    break;
				}
				if(*buf == '\n')
				{
					counter++;
				}
			}
			lseek(fildes, 0, SEEK_SET);
			//printf("%d",counter);
			if(counter <= 10 && counter!= 0)
			{
				//printf("in");
				while(1)
				{
					int bytesRead = read(fildes,buf,BUFFER);
					if(bytesRead == 0)
					{
						break;
					}
					else if(bytesRead == -1)
					{
						display_read_error(argv[1]);
					    break;
					}
					if(write(STDOUT_FILENO, buf, strlen(buf)) == -1)
					{	//printf
						display_write_error();
						break;
					}	
				}
			}
			else if(counter > 10 && counter != 0)
			{
				//printf("in");
				//printf("%d\n",counter );
				int currCounter = 0;
				while(1)
				{
					int bytesRead = read(fildes,buf,BUFFER);
					if(bytesRead == 0)
					{
						break;
					}
					else if(bytesRead == -1)
					{
						display_read_error(argv[1]);
					    break;
					}
					else if(bytesRead > 0)
					{
						if(currCounter >= counter - 10)
						{
							if(write(STDOUT_FILENO, buf, strlen(buf))== -1)
							{
								display_write_error();
								break;
							}		
						}
						if(*buf == '\n')
						{	
							currCounter++;
						}
					
					}
					
				}
			}
			if(close(fildes) == -1)
			{
				display_close_error(argv[1]);
			}
		}	
		}
		
	}
	else if(argc > 2)
	{
		for(int i = 1;i < argc; i++)
		{	
			if(strcmp(argv[i], "-") == 0)
			{
				char s1[] = "==> standard input <==\n";
				write(STDOUT_FILENO, s1, strlen(s1));
				write_on_console();
				write(STDOUT_FILENO, "\n", 1);
			}
			else
			{
				int fildes = open(argv[i],O_RDONLY);
			if(check_file(fildes,argv[i]) != -1)
			{
			//int bytesRead;
			char buf[BUFFER + 1] = {0};
			
			int canBeRead = 1;
			int counter = 0;
			while(1)
			{
				int bytesRead = read(fildes,buf,BUFFER);
				if(bytesRead == 0)
				{
					break;
				}
				else if(bytesRead == -1)
				{
					display_read_error(argv[i]);
					canBeRead = 0;
				    break;
				}
				if(*buf == '\n')
				{
					counter++;
				}
			}

			if(canBeRead == 1)
			{
				lseek(fildes, 0, SEEK_SET);
				char s1[] = "==> ";
				strcat(s1,argv[i]);
				strcat(s1," <==\n");
				write(STDOUT_FILENO, s1, strlen(s1));
				
			}
			

			if(counter <= 10)
			{
				if(counter <= 10 && counter!= 0)
				{
					while(1)
					{
						int bytesRead = read(fildes,buf,BUFFER);
						if(bytesRead == 0)
						{
							break;
						}
						else if(bytesRead == -1)
						{
							display_read_error(argv[i]);
						    break;
						}
					if(write(STDOUT_FILENO, buf, strlen(buf)) == -1)
					{
						display_write_error();
						break;
					}	
					}
				}
			}
			else if(counter > 10 && counter != 0)
			{
				int currCounter = 0;
				while(1)
				{
					int bytesRead = read(fildes,buf,BUFFER);
					if(bytesRead == 0)
					{
						break;
					}
					else if(bytesRead == -1)
					{
						display_read_error(argv[i]);
					    break;
					}
					else if(bytesRead > 0)
					{
						if(currCounter >= counter - 10)
						{
							if(write(STDOUT_FILENO, buf, strlen(buf)) == -1)
							{
								display_write_error();
								break;
							}		
						}
						if(*buf == '\n')
						{	
							currCounter++;
						}
					
					}
					
				}
			}
			if(i + 1 != argc)
			{		
				write(STDOUT_FILENO, "\n", 1);
			}
		if(close(fildes) == -1)
		{
			display_close_error(argv[i]);
		}
		
		}
			}
			
	    }

	}
}