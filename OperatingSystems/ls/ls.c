// NAME: Vladislav Kolev
// CLASS: Xi b
// NUMBER: 7
// FILE NAME: ls.c 
// FILE PURPOSE:
// making ls

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>
#include <dirent.h>


void process(char *name)
{
    struct stat st;
        stat(name, &st);
        if(S_ISREG(st.st_mode))
        {
            printf("- %s\n", name);
        }
        else if(S_ISDIR(st.st_mode))
        {
            DIR *dir = opendir(name);
            struct dirent *d;
            while ((d = readdir(dir)) != NULL)
            {
                //printf("in");
                process(d->d_name);
        	    printf("%s\n", d->d_name);
            }
            closedir(dir);

            printf("d %s\n", name);
        }   
        else if(S_ISBLK(st.st_mode))
        {
            printf("b %s\n", name);
        }
        else if(S_ISCHR(st.st_mode))
        {
            printf("c %s\n", name);
        }
        else if(S_ISFIFO(st.st_mode))
        {
            printf("c %s\n", name);
        }
        ///Why???????

        // else if(S_ISLNK(st.st_mode))
        // {
        //     printf("T %s\n", name);
        // }
        // else if(S_ISSOCK(st.st_mode))
        // {
        //     printf("s %s\n", name);
        // }
        else
        {
            //TODO:
        }

}

int main(int argc, char *argv[])
{
    for (int i = 1; i < argc; i++)
    {
        char *name = argv[i];
        process(name);
        
    }
    
}