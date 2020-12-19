// NAME: Vladislav Kolev
// CLASS: XIb
// NUMBER: 7
#include <stdint.h>
#include <stdio.h>
#include <arpa/inet.h>
//#include "read.c"

void *read_image( const char *filepath );

int main( int argc, const char* argv[] ) {
		
	
	//void * file = read_image("mountain.bmp");
	
	//////BMP Info excercise
	/*void * file = read_image(argv[1]);
	uint32_t *width = file + 18;
	uint32_t *height = file + 22;
	printf("BMP image width: %d\n",*width);
	printf("BMP image height: %d\n",*height);
	*/


	////PNG Info excercise
	char *file = read_image(argv[1]);
	if(file == NULL)
	{
		printf("Unable to open file\n");
	}
	else
	{
		int itr = 0;
		int type_is_png = 1;
		char height[4];
		char width[4];
		char fileType[8] = {0x89, 0x50, 0x4E, 0x47, 0x0D, 0x0A, 0x1A, 0x0A};
		
		for(int i = 0; i < 8; i++){
			if(file[i] != fileType[i])
			{
				type_is_png = 0;
			}
		}
		if(type_is_png == 0)
		{
			printf("Unable to parse file\n");
		}
		else
		{
			while(file[itr] != 'I' || file[itr + 1] != 'E' || file[itr + 2] != 'N' || file[itr + 3] != 'D')
			{
				if(file[itr] == 'I' && file[itr + 1] == 'H' && file[itr + 2] == 'D' && file[itr + 3] == 'R')
				{
					int temp = 0;
					for(int i = 0; i < 4; i++)
					{
						width[i] = file[itr + 4 + i];		
						temp++;		
					}
					for(int j = 0 ; j < 4; j++)
					{
						height[j] = file[itr + 4 + temp + j];				
					}
					
				}
				itr++;	
			}
			////
			itr += 8;

			printf("PNG image width: %d\n",ntohl(*(int*)width));
		 	printf("PNG image height: %d\n",ntohl(*(int*)height));
		 	printf("PNG file size: %d\n",itr);

		}
		
		
	}
	
}
