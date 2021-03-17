#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <string.h>
#include <unistd.h>

pthread_mutex_t mutex;
int turn = 0;
int count_gold = 0;

void *mine(void *arg)
{
    //while(1)
    int index = *(int*)arg;
    for(int i = 0; i < 20; i++)
    {
        pthread_mutex_lock(&mutex);
        
        count_gold = count_gold + 10;
        printf("Miner %d gathered 10 gold\n", index);

        pthread_mutex_unlock(&mutex);
        sleep(2);
    }

    return NULL;
}

void *sell(void *arg)
{
    int index = *(int*)arg;
    for(int i = 0; i < 20; i++)
    {
        pthread_mutex_lock(&mutex);
        
            if(count_gold < 10)
            {
                printf("The warehouse is empty, cannot sell!\n");
            }
            else
            {
                count_gold = count_gold - 10;
                printf("Trader %d sold 10 gold\n", index);
            }
            
        pthread_mutex_unlock(&mutex);  
        sleep(2); 
    }

    return NULL;
}


int main(int argc, char *argv[])
{
    int rc;
    int miners_count = 1;
    int seller_count = 1;
    //pthread_t miner, seller;

    miners_count = atoi(argv[1]);
    seller_count = atoi(argv[2]);

    pthread_t miners[miners_count];
    pthread_t sellers[seller_count];
    

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < miners_count; i++)
    {
        int index = i + 1;
        
        printf("%d", index);
        rc = pthread_create(&miners[i], NULL, &mine, &index);
        if(rc)
        {
            printf(strerror(rc));
            return 1;
        }
    }

    for (int i = 0; i < seller_count; i++)
    {
        int index = i + 1;

        rc = pthread_create(&sellers[i], NULL, &sell, &index);
        if(rc)
        {
            printf(strerror(rc));
            return 1;
        }

    }

    for (int i = 0; i < miners_count; i++)
    {
        pthread_join(miners[i], NULL);
    }
    for (int i = 0; i < seller_count; i++)
    {
        pthread_join(sellers[i], NULL);
    }
    
    
    
    printf("Gold: %d\n", count_gold);
    
    
    
    //pthread_join(miner, NULL);
    //pthread_join(seller, NULL);

    pthread_mutex_destroy(&mutex);
    return 0;

}
