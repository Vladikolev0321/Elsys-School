//--------------------------------------------
// NAME: Teodor Dishanski
// CLASS: XI b
// NUMBER: 23
// PROBLEM: #2
//---------------------------------------------

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

/* The mutex and the variable for the collected gold have to be global
declared in roder to be seen by all the functions below. If this is not
like this, our program will not work correct. I make the variable for the
gold long integer in case a very big numbers for miners and traders are
given as console arguments. 

The warehouse with the gold will be our critical section, because the miners
will add gold in it, bu the traders will take gold from it. */

long int collected_gold = 0;
pthread_mutex_t mutex;

void *miner_work(void *thread_argument) {

    /* This will be the function for thread of the workers. Every single
    miner will do his work exactly 20 times. Because of that fact*/
    
    int argument = *(int*) thread_argument;

    for (int i = 0; i < 20; i++) {
        int locking = pthread_mutex_lock(&mutex);
        if (locking != 0) { printf("Error with the locking of the mutex!"); exit(-1); }

        collected_gold = collected_gold + 10;
        printf("Miner %d gathered 10 gold\n", argument);

        int unlocking = pthread_mutex_unlock(&mutex);
        if (unlocking != 0) { printf("Error with the unlocking of the mutex!"); exit(-1); }
        sleep(2);
    }

    return NULL;
}

void *trader_work(void *thread_argument) {

    int argument = *(int*) thread_argument;

    for (int i = 0; i < 20; i++) {
        int locking = pthread_mutex_lock(&mutex);
        if (locking != 0) { printf("Error with the locking of the mutex!"); exit(-1); }

        if (collected_gold < 10) {
            printf("The warehouse is empty, cannot sell!\n");
        }
        else {
            collected_gold = collected_gold - 10;
            printf("Trader %d sold 10 gold\n", argument);
        }

        int unlocking = pthread_mutex_unlock(&mutex);
        if (unlocking != 0) { printf("Error with the unlocking of the mutex!"); exit(-1); }
        sleep(2);
    }

    return NULL;
}

int main(int argc, char **argv) {

    /* By default the count of the miners and the count of the traders will
    be 1. If these count variables are given as console arguments, we will
    change their values. */

    int count_miners = 1;
    int count_traders = 1;

    if (argc > 2) {
        count_miners = atoi(argv[1]);
        count_traders = atoi(argv[2]);
    }

    /* We declare the arrays of the threads with the
    values from the console arguments or 1 by default. */

    pthread_t miners[count_miners];
    pthread_t traders[count_traders];

    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < count_miners; i++) {
        int number = i + 1;
        int creating = pthread_create(&(miners[i]), NULL, miner_work, &number);
        if (creating != 0) { printf("Error with the creating of the thread!"); exit(-1); }
    }

    for (int i = 0; i < count_traders; i++) {
        int number = i + 1;
        int creating = pthread_create(&(traders[i]), NULL, trader_work, &number);
        if (creating != 0) { printf("Error with the creating of the thread!"); exit(-1); }
    }

    for (int i = 0; i < count_miners; i++) {
        int joining = pthread_join(miners[i], NULL);
        if (joining != 0) { printf("Error with the joining of the thread!"); exit(-1); }
    }

    for (int i = 0; i < count_traders; i++) {
        int joining = pthread_join(traders[i], NULL);
        if (joining != 0) { printf("Error with the joining of the thread!"); exit(-1); }
    }

    printf("Gold: %ld\n", collected_gold);

    int destroying = pthread_mutex_destroy(&mutex);
    if (destroying != 0) { printf("Error with the destrying of the mutex!"); exit(-1); }

    return 0;
}