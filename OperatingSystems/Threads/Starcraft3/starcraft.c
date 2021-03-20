#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

//pthread_mutex_t mutex;
int count_all_minerals = 0;
int count_blocks = 2;
//int *blocks;
struct block_t *blocks;
//int curr_worker_id;


struct block_t
{
    int size;
    pthread_mutex_t block_mutex;
};
struct command_center
{
    int size;
};
void *work(void *w_indexes)
{


    while(1)
    {
       for (int i = 0; i < count_blocks; i++)
       {
           if(blocks[i].size > 0)
           {
               sleep(3);
               if(pthread_mutex_trylock(&blocks[i].block_mutex) == 0)
               {
                   if(blocks[i].size == 0)
                   {
                       continue;
                   }

                  //printf("SCV %d is mining from mineral block %d\n", , i+1);
               }

           }
       }
       
    }
    

    //return NULL;
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    ///game ends when count_blocks = 0 and are made
    // soldiers

    //if(pthread_mutex_init(&mutex, NULL))
   // {
  //      return 1;
  //  }
    int count_workers = 5;
    
    if(argc == 2)//if given blocks are null
    {
        count_blocks = atoi(argv[1]);
    }
    /// inicialising blocks
    //blocks = malloc(count_blocks * sizeof(int));
    blocks = malloc(count_blocks * sizeof(struct block_t));

    for (int i = 0; i < count_blocks; i++)
    {
        count_all_minerals += 500;
        blocks[i].size = 500; 
        pthread_mutex_init(&blocks[i].block_mutex, NULL);
        //blocks[i] = 500;
    }
    
    /// creating first 5 workers 
    pthread_t *workers = malloc(200 * sizeof(pthread_t)); // should allocate for 5 workers
    //int workers_indexes[count_workers]; 
    ///
    
    /// create workers
    for (int i = 0; i < 5; i++)
    {   
        //workers_indexes[i] = i + 1;
        int result = pthread_create(&workers[i], NULL, &work, NULL);//(void*)workers_indexes
        if(result)
        {
            printf("Error creating");
            return 1;
        }
    }
    
    // free memory
    for (int i = 0; i < count_blocks; i++)
    {
        if(pthread_mutex_destroy(&blocks[i].block_mutex))
        {
            printf("Error destroying");
            return 1;
        }
        //free(&blocks[i].block_mutex);
    }
    for (int i = 0; i < count_blocks; i++)
    {
        free(&blocks[i]);
    }
    
    for (int i = 0; i < count_workers; i++)
    {
        free(&workers[i]);
    }
    
    
    free(blocks);
    free(workers);

    return 0;


}