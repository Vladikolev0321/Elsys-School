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
#include <string.h>
#include <stdlib.h>
//#include <limits.h>

void process_only_by_type(char *name, char *path)
{
        struct stat st;
        stat(path, &st);
        if(S_ISREG(st.st_mode))
        {
            printf("- %s\n", name);
        }
        else if(S_ISDIR(st.st_mode))
        {
            printf("d %s\n", name);

        }   
        else if(S_ISBLK(st.st_mode)){ printf("b %s\n", name);}
        else if(S_ISCHR(st.st_mode)){ printf("c %s\n", name); }
        else if(S_ISFIFO(st.st_mode)){ printf("p %s\n", name); }
        else if(S_ISLNK(st.st_mode)){ printf("l %s\n", name); }
        
        else if(S_ISSOCK(st.st_mode)){ printf("s %s\n", name); }

        else{   printf("No\n");  }//TODO:
}
void process(char *name, int multiple_args)
{
    struct stat st;
        stat(name, &st);
        if(S_ISREG(st.st_mode)){ printf("- %s\n", name); }
        
        else if(S_ISDIR(st.st_mode))
        {

            DIR *dir = opendir(name);
            struct dirent *d;
            if(multiple_args)
            {
                printf("%s:\n", name);
            }
            while ((d = readdir(dir)) != NULL)
            {
                //printf("in");
                //if (S_ISDIR(d->st_mode))
               // {
                
                if (strcmp(d->d_name , ".") != 0 &&  strcmp(d->d_name , "..") != 0)
                {
                      ///????
                      char *temp = malloc(1 + strlen(name)+ strlen(d->d_name));
                      strcpy(temp, name);
                      strcat(temp, "/");
                      strcat(temp, d->d_name);
                     // printf("%s\n", temp);
                     // process(temp);
        	         // printf("%s\n", d->d_name);
                    // printf("%s", d->d_name);
                      if(d->d_name[0] != '.')
                      {
                        process_only_by_type(d->d_name, temp);
                      }
                }   
            }
            closedir(dir);

            
            //printf("d %s\n", name);

        }   
        else if(S_ISBLK(st.st_mode)){ printf("b %s\n", name);}
        else if(S_ISCHR(st.st_mode)){ printf("c %s\n", name); }
        else if(S_ISFIFO(st.st_mode)){ printf("p %s\n", name); }
        else if(S_ISLNK(st.st_mode)){ printf("l %s\n", name); }
        
        else if(S_ISSOCK(st.st_mode)){ printf("s %s\n", name); }

        else{   perror(name);  }//TODO:

}

void process_with_A(char *name, int multiple_args)
{
    struct stat st;
        stat(name, &st);
        if(S_ISREG(st.st_mode)){ printf("- %s\n", name); }
        
        else if(S_ISDIR(st.st_mode))
        {

            DIR *dir = opendir(name);
            struct dirent *d;
            if(multiple_args)
            {
                printf("%s:\n", name);
            }
            while ((d = readdir(dir)) != NULL)
            {
                //printf("in");
                //if (S_ISDIR(d->st_mode))
               // {
                
                if (strcmp(d->d_name , ".") != 0 &&  strcmp(d->d_name , "..") != 0)
                {
                      ///????
                      char *temp = malloc(1 + strlen(name)+ strlen(d->d_name));
                      strcpy(temp, name);
                      strcat(temp, "/");
                      strcat(temp, d->d_name);
                     // printf("%s\n", temp);
                     // process(temp);
        	         // printf("%s\n", d->d_name);
                    // printf("%s", d->d_name);
                    
                    process_only_by_type(d->d_name, temp);
                }   
            }
            closedir(dir);

            
            //printf("d %s\n", name);

        }   
        else if(S_ISBLK(st.st_mode)){ printf("b %s\n", name);}
        else if(S_ISCHR(st.st_mode)){ printf("c %s\n", name); }
        else if(S_ISFIFO(st.st_mode)){ printf("p %s\n", name); }
        else if(S_ISLNK(st.st_mode)){ printf("l %s\n", name); }
        
        else if(S_ISSOCK(st.st_mode)){ printf("s %s\n", name); }

        else{   printf("No\n");  }//TODO:

}
int getChmod(const char *path){
    struct stat ret;

    if (stat(path, &ret) == -1) {
        return -1;
    }

    return (ret.st_mode & S_IRUSR)|(ret.st_mode & S_IWUSR)|(ret.st_mode & S_IXUSR)|/*owner*/
        (ret.st_mode & S_IRGRP)|(ret.st_mode & S_IWGRP)|(ret.st_mode & S_IXGRP)|/*group*/
        (ret.st_mode & S_IROTH)|(ret.st_mode & S_IWOTH)|(ret.st_mode & S_IXOTH);/*other*/
}
void process_files_info_for_l(char *name, char *path)
{
        struct stat st;
        stat(path, &st);
        if(S_ISREG(st.st_mode))
        {
            printf("- %0X%s\n",  getChmod(path),name);
        }
        else if(S_ISDIR(st.st_mode))
        {
            printf("d %s\n", name);

        }   
        else if(S_ISBLK(st.st_mode)){ printf("b %s\n", name);}
        else if(S_ISCHR(st.st_mode)){ printf("c %s\n", name); }
        else if(S_ISFIFO(st.st_mode)){ printf("p %s\n", name); }
        else if(S_ISLNK(st.st_mode)){ printf("l %s\n", name); }
        
        else if(S_ISSOCK(st.st_mode)){ printf("s %s\n", name); }

        else{   printf("No\n");  }//TODO:
}
////////////////////-l
void process_with_l(char *name, int multiple_args)
{
    struct stat st;
        stat(name, &st);
        int total_sum = 0;
        if(S_ISREG(st.st_mode)){ printf("- %s\n", name); }
        
        else if(S_ISDIR(st.st_mode))
        {

            DIR *dir = opendir(name);
            struct dirent *d;
           // struct dirent *d2;
            if(multiple_args)
            {
                printf("%s:\n", name);
            }
            while ((d = readdir(dir)) != NULL)
            {
                //printf("in");
                //if (S_ISDIR(d->st_mode))
               // {
                
                if (strcmp(d->d_name , ".") != 0 &&  strcmp(d->d_name , "..") != 0)
                {
                      ///????
                      char *temp = malloc(1 + strlen(name)+ strlen(d->d_name));
                      strcpy(temp, name);
                      strcat(temp, "/");
                      strcat(temp, d->d_name);
                     // printf("%s\n", temp);
                     // process(temp);
        	         // printf("%s\n", d->d_name);
                    // printf("%s", d->d_name);
                    
                    if(d->d_name[0] != '.')
                    {
                        process_files_info_for_l(d->d_name, temp);
                        struct stat temp_st;
                    stat(d->d_name, &temp_st);
                    total_sum +=  temp_st.st_blocks;
                    }
                    
                    //printf("%ld\n", temp_st.st_blocks);
                }   
            }
            printf("total %d\n", total_sum/2);
            closedir(dir);


            dir = opendir(name);
            struct dirent *d2;
            while ((d2 = readdir(dir)) != NULL)
            {
                //printf("in");
                //if (S_ISDIR(d->st_mode))
               // {
                
                if (strcmp(d2->d_name , ".") != 0 &&  strcmp(d2->d_name , "..") != 0)
                {
                      ///????
                      char *temp = malloc(1 + strlen(name)+ strlen(d2->d_name));
                      strcpy(temp, name);
                      strcat(temp, "/");
                      strcat(temp, d2->d_name);
                    
                    if(d2->d_name[0] != '.')
                    {
                        process_only_by_type(d2->d_name, temp);
                        struct stat temp_st;
                    stat(d2->d_name, &temp_st);
                    total_sum +=  temp_st.st_blocks;
                    }
                    //printf("in");
                    //printf("%ld\n", temp_st.st_blocks);
                }   
            }
            
            printf("total %d\n", total_sum/2);
            closedir(dir);
            
            //printf("d %s\n", name);

        }   
        else if(S_ISBLK(st.st_mode)){ printf("b %s\n", name);}
        else if(S_ISCHR(st.st_mode)){ printf("c %s\n", name); }
        else if(S_ISFIFO(st.st_mode)){ printf("p %s\n", name); }
        else if(S_ISLNK(st.st_mode)){ printf("l %s\n", name); }
        
        else if(S_ISSOCK(st.st_mode)){ printf("s %s\n", name); }

        else{  printf("No\n");  }//TODO:

}
int main(int argc, char *argv[])
{
    int multiple_args;
    if(argc == 1)
    {
        multiple_args = 0;

        char cwd[100000];

        char * currD = getcwd(cwd, 100000);
       // printf("%s", currD);
        process(currD, multiple_args);
        return 0;
    }
    else if(argc == 2 && strcmp(argv[1],"-A") == 0)
    {
        multiple_args = 0;

        char cwd[200000];

        char * currD = getcwd(cwd, 200000);
       // printf("%s", currD);
        process_with_A(currD, multiple_args);
        return 0;
    }
    else if(argc == 2 && strcmp(argv[1],"-l") == 0)
    {
        multiple_args = 0;

        char cwd[200000];

        char * currD = getcwd(cwd, 200000);
       // printf("%s", currD);
        process_with_l(currD, multiple_args);
        return 0;
    }

    multiple_args = 1;
    int firstdir = 1;
    for (int i = 1; i < argc; i++)
    {
        
        char *name = argv[i];
        struct stat st;
        stat(name, &st);
        if(i != 1  && S_ISDIR(st.st_mode) && firstdir)
        {
            printf("\n");
            firstdir = 0;
        }
        process(name, multiple_args);

        
        //// What is the logic for the new line
        if(i + 1 != argc && S_ISDIR(st.st_mode))
        {
            printf("\n");
        }
    }
    
}