// NAME: Vladislav Kolev
// CLASS: Xi b
// NUMBER: 7
// FILE NAME: starcraft.c 
// FILE PURPOSE:
// making starcraft 3 using threads and mutexes


#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t command_center_mutex;
int count_all_minerals = 0;
int count_blocks = 2;
int minerals_got = 0;
//int *blocks;
struct block_t *blocks;
//int curr_worker_id;
struct command_center command_center;

struct worker_indexes
{
    int curr_index;
    //int *indexes;
};
struct block_t
{
    int size;
    pthread_mutex_t block_mutex;
};
struct command_center
{
    int initial_minerals;
    int minerals_got;
    int count_workers;
    int count_soldiers;
};
void *work(void *wo_indexes)
{
    struct worker_indexes *w_indexes = wo_indexes; 
    int count_mined = 0;
    while(1)
    {
       if(count_all_minerals == 0)
       {
           break;
       }
       
       for (int i = 0; i < count_blocks; i++)
       {
           if(pthread_mutex_trylock(&blocks[i].block_mutex) == 0)
            {
                if(blocks[i].size > 0)
                {
                    sleep(3);
               
                   if(blocks[i].size == 0)
                   {
                     pthread_mutex_unlock(&blocks[i].block_mutex);
                     continue;
                   }

                   printf("SCV %d is mining from mineral block %d\n", w_indexes->curr_index, i+1); // TO ADD
               
                   if(blocks[i].size > 8)
                   {
                       ///mined +
                       count_mined += 8;//
                       blocks[i].size -= 8;
                       count_all_minerals -= 8;
                   }
                   else
                   {
                       //mined +
                       count_mined += blocks[i].size;//
                       count_all_minerals -= blocks[i].size;
                       blocks[i].size = 0;
                   }

                   pthread_mutex_unlock(&blocks[i].block_mutex);
                   //i = 0;
                   break;

                }

           }
       }

       if(count_mined > 0)
       {
            printf("SCV %d is transporting minerals\n", w_indexes->curr_index); // TO ADD
            sleep(2);
           while(count_mined != 0)
           {

              if(pthread_mutex_trylock(&command_center_mutex) == 0)
              {
                printf("SCV %d delivered minerals to the Command center\n", w_indexes->curr_index);
                command_center.minerals_got += count_mined;
                count_mined = 0;
                pthread_mutex_unlock(&command_center_mutex);
              }
           }
            ///
       }

       
    }
    
    free(wo_indexes);
    //return NULL;
    pthread_exit(NULL);
}
int main(int argc, char *argv[])
{
    ///game ends when count_blocks = 0 and are made
    // soldiers

    if(pthread_mutex_init(&command_center_mutex, NULL))
    {
        return 1;
    }
    //int count_workers = 5;
    command_center.count_workers = 5;
    command_center.count_soldiers = 0;

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
        command_center.initial_minerals += 500;
        blocks[i].size = 500; 
        pthread_mutex_init(&blocks[i].block_mutex, NULL);
        //blocks[i] = 500;
    }
    
    /// creating first 5 workers 
    pthread_t *workers = malloc(200 * sizeof(pthread_t)); // should allocate for 5 workers
    ///
   // struct worker_indexes worker_indexes;
    //worker_indexes.indexes = malloc(5 * sizeof(struct worker_indexes));/// chnege allocation
    //int workers_indexes[count_workers]; 
    ///
    
    /// create workers
    for (int i = 0; i < 5; i++)
    {   
        //workers_indexes[i] = i + 1;
        //worker_indexes.indexes[i] = i + 1;
        struct worker_indexes *worker_indexes = malloc(sizeof(struct worker_indexes));
        worker_indexes->curr_index = i + 1;
        int result = pthread_create(&workers[i], NULL, &work, (void*)worker_indexes);//(void*)workers_indexes
        if(result)
        {
            printf("Error creating");
            free(blocks);
            free(workers);
            return 1;
        }
    }
    //command_center.count_soldiers != 20 && count_all_minerals != 0
    while(1)
    {
       // printf("w-%d , all_min-%d\n", command_center.count_soldiers, count_all_minerals);
        if(command_center.count_soldiers == 20 && count_all_minerals == 0)
        {
            break;
        }
        //*/
        char input;
        scanf("%c", &input);

        if(input == 'm')
        {
            if(command_center.minerals_got >= 50 && command_center.count_soldiers < 20)
            {
                sleep(1);
                command_center.minerals_got -= 50;
                printf("You wanna piece of me, boy?\n");
                command_center.count_soldiers++;
            }
            else
            {
                printf("Not enough minerals.\n");
            }
            
        }
        else if(input == 's')
        {
            if(command_center.minerals_got >= 50)
            {
                command_center.minerals_got -= 50;
                sleep(4);
                //printf("SCV good to go, sir.\n");
                //// to realloc workers
                struct worker_indexes *worker_indexes = malloc(sizeof(struct worker_indexes));
                worker_indexes->curr_index = command_center.count_workers;
                //
                command_center.count_workers++;
            //    worker_indexes.curr_index = command_center.count_workers - 1;
                int currIndex = command_center.count_workers - 1;
                int result = pthread_create(&workers[currIndex], NULL, &work, (void*)worker_indexes);//(void*)workers_indexes
                if(result)
                {
                    printf("Error creating");
                    free(blocks);
                    free(workers);
                    return 1;
                }
                printf("SCV good to go, sir.\n");
            }
            else
            {
                printf("Not enough minerals.\n");
            }
        }
    }


    /// pthread join 
    for (int i = 0; i < command_center.count_workers; i++)
    {
        if(pthread_join(workers[i], NULL) != 0)
        {
            free(blocks);
            free(workers);
            return 1;
        }
    }
    

    printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d\n", command_center.initial_minerals,
                                        command_center.minerals_got, command_center.count_workers, command_center.count_soldiers );
    // free memory
    for (int i = 0; i < count_blocks; i++)
    {
        if(pthread_mutex_destroy(&blocks[i].block_mutex))
        {
            //printf("Error destroying");
            free(blocks);
            free(workers);
            return 1;
        }
        //free(&blocks[i].block_mutex);
    }
    if(pthread_mutex_destroy(&command_center_mutex))
    {
        //printf("Error destroying");
        free(blocks);
        free(workers);
        return 1;
    }
    
   /* for (int i = 0; i < count_blocks; i++)
    {
        free(&blocks[i]);
    }
    */
    
    /*for (int i = 0; i < count_workers; i++)
    {
        free(&workers[i]);
    }
    */
    
    
    free(blocks);
    free(workers);
    //free(worker_indexes);

    return 0;


}