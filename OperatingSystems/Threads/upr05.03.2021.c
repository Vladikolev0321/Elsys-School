#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>

#define COUNT_THREADS
#define BUFFER_SIZE 100
char buff[BUFFER_SIZE];
pthread_mutex_t mutex_buff;
int g_buf_full = 0;
ssize_t bytes_read;

void *reader(void *p)
{
    //char *buff;
    while(1)
    {
        pthread_mutex_lock(&mutex_buff);
        if(g_buf_full == 0)
        {
            g_buf_full = 1;
            bytes_read = read(STDIN_FILENO, buff, BUFFER_SIZE);
            if(bytes_read < 0)
            {
                perror("read()");
                pthread_mutex_unlock(&mutex_buff);
                break;
            }
            if(bytes_read == 0)
            {
                pthread_mutex_unlock(&mutex_buff);
                break;
            }
        }
        pthread_mutex_unlock(&mutex_buff);
    }

    return NULL;
}
void *writer(void *p)
{   
    while(1)
    {
        pthread_mutex_lock(&mutex_buff);
        if(g_buf_full == 1)
        {
            g_buf_full = 0;
            if(bytes_read <= 0)
            {
                pthread_mutex_unlock(&mutex_buff);
                break;
            }
            write(STDOUT_FILENO, "Echo: ", strlen("Echo: "));
            if(write(STDOUT_FILENO, buff, bytes_read) < 0)
            {
                perror("write():");
                pthread_mutex_unlock(&mutex_buff);
                break;
            }
        }
        
        pthread_mutex_unlock(&mutex_buff);
    }

    return NULL;
}

int main(int argc, char *argv[])
{
    int rc;
    //char *buff;
    pthread_t thr1, thr2;

    pthread_mutex_init(&mutex_buff, NULL);

    rc = pthread_create(&thr1, NULL, &reader, NULL);
    if(rc)
    {
        printf(strerror(rc));
        return 1;
    }
    rc = pthread_create(&thr2, NULL, &writer, NULL);
    if(rc)
    {
        printf(strerror(rc));
        return 1;
    }

    pthread_join(thr1, NULL);
    pthread_join(thr2, NULL);

    pthread_mutex_destroy(&mutex_buff);

    return 0;


}