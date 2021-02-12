#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

void *get_sum(void *thread_id, int N)
{
    int sum = 0;
    for (int i = 1; i <= N; i++)
    {
        sum += i;
    }

    return sum;
}
int main(int argc, char *argv[])
{
    int count_threads = atoi(argv[1]);
    int count_threads;
    int N;
    scanf("%d", count_threads);
    scanf("%d", N);
    
    pthread_t thread[count_threads];
    for (int i = 0; i < count_threads; i++)
    {
        printf ( "Creating  thread %d \n " , i );
        int rc = pthread_create(&thread[i], NULL, get_sum, N);
        
    }
    
    return 0;
}