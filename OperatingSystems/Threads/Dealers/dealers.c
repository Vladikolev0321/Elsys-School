#include <stdio.h>
#include <pthread.h>
#include <unistd.h>

pthread_mutex_t mutex;
int N = 20;
int M = 5;

void *test(void *arg)
{
    int index = *(int*)arg;
    for(int i = 0; i < M; i++)
    {
        pthread_mutex_lock(&mutex);
        printf("Buyer %d takes car M\n", index);
        printf("Buyer %d returns car M\n", index);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    if(pthread_mutex_init(&mutex, NULL))
    {
        return 1;
    }


    pthread_t drivers[N];

    for(int i = 0; i < N; i++)
    {
        int index = i + 1;
        pthread_create(&drivers[i], NULL, &test, &index);
    }

    for(int i = 0; i < N; i++)
    {
        pthread_join(drivers[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}