#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_mutex_t mutex;
int count_all_minerals = 0;
int count_blocks = 2;
int *blocks;

struct command_center
{
    int size;
};
void *work(void *block)
{
    while(1)
    {

    }
}
int main(int argc, char *argv[])
{
    ///game ends when count_blocks = 0 and are made
    // soldiers

    if(pthread_mutex_init(&mutex, NULL))
    {
        return 1;
    }
    int count_workers = 5;
    
    if(argc == 2)
    {
        count_blocks = atoi(argv[1]);
    }
    /// inicialising blocks
    blocks = malloc(count_blocks * sizeof(int));

    for (int i = 0; i < count_blocks; i++)
    {
        count_all_minerals += 500;
        blocks[i] = 500;
    }
    
    /// creating first 5 workers
    pthread_t *workers = malloc(200 * sizeof(pthread_t));

    ///
    
    /// create workers
    for (int i = 0; i < 5; i++)
    {
        int result = pthread_create(&workers[i], NULL, &work, NULL);
        if(result)
        {
            return 1;
        }
    }
    

    free(blocks);
    free(workers);

    return 0;


}