#include<stdio.h>
#include<stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>

struct pack_t{
	int worker_ID;
	int size;
	int *blocks;
	pthread_mutex_t *mutexes;
};

int total = 0;
int soldiers = 0;
int minerals = 0;
pthread_mutex_t command_mutex;

void *worker_stuff(void *pack){

	struct pack_t *data = pack;
	int mined = 0;
		
	while(1){
	
		for(int i = 0; i < data->size; i++){
		
			if(data->blocks[i] > 0){
				sleep(3);
			
				if(pthread_mutex_trylock(&data->mutexes[i]) == 0){
					 
					if(data->blocks[i] == 0){
						continue;
					} 
					 
					printf("SCV %d is mining from mineral block %d\n", data->worker_ID, i + 1); 
					 
					if(data->blocks[i] > 8){
						mined += 8;
						data->blocks[i] -= 8;
						total -= 8;
						
					}else{
						mined += data->blocks[i];
						data->blocks[i] = 0;
						total -= mined;
					}
					
					pthread_mutex_unlock(&data->mutexes[i]);
					break;
				}
			}
		}
		
		if(mined){
			printf("SCV %d is transporting minerals\n", data->worker_ID);
			sleep(2);
	
			while(mined != 0){
		
				if(pthread_mutex_trylock(&command_mutex) == 0){
					printf("SCV %d delivered minerals to the Command center\n", data->worker_ID);
					minerals += mined;
					mined = 0;
					pthread_mutex_unlock(&command_mutex);
				}
			}
		}
		
		if(total == 0){
			break;
		}
	}
	
	free(pack);
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){

	int res = pthread_mutex_init(&command_mutex, NULL);

	if(res){
		return 0;
	}

	int veins = 2, initial_workers = 5;

	if (argc == 2){
		veins = atoi(argv[1]);
	}

	int *mineral_blocks = (int*) malloc(veins * sizeof(int));
	
	for(int i = 0; i < veins; i++){
		mineral_blocks[i] = 500;
		total += 500;
	}
	
	pthread_t *workers = (pthread_t*) malloc(100 * sizeof(pthread_t));
	pthread_mutex_t *workers_mutex = (pthread_mutex_t*) malloc(veins * sizeof(pthread_mutex_t));
	
	for(int i = 0; i < veins; i++){
		int res = pthread_mutex_init(&workers_mutex[i], NULL);
		
		if(res){
			return 0; 
		}
	}

	for(int i = 0; i < 5; i++){
		struct pack_t *pack = malloc(sizeof(struct pack_t));
		
		pack->worker_ID = i + 1;
		pack->blocks = mineral_blocks;
		pack->mutexes = workers_mutex;
		pack->size = veins;
		
		int res = pthread_create(&workers[i], NULL, &worker_stuff, (void*)pack);
	
		if(res){
			goto END;
		}
	}
	
	while(1){
	
		if(total == 0 && soldiers == 20){
			break;
		}
	
		char c;
		scanf("%c", &c);
		
		if(c == 's'){
		
			if(minerals >= 50){
		
				struct pack_t *pack = malloc(sizeof(struct pack_t));
				pack->worker_ID = initial_workers;
				pack->blocks = mineral_blocks + 1; 
				pack->mutexes = workers_mutex;
				pack->size = veins;
			
				int res = pthread_create(&workers[initial_workers], NULL, &worker_stuff, (void*)pack);
			
				if(res){
					goto END;
			
				}else{
					initial_workers += 1;
					printf("SCV good to go, sir.\n");
					minerals -= 50;
					sleep(4);
				}
				
			}else{
				printf("Not enough minerals.\n");
			}
			
		}else if(c == 'm'){
		
			if(minerals >= 50){
				printf("You wanna piece of me, boy?\n");
				soldiers += 1;
				minerals -= 50;
				sleep(1);
				
			}else{
				printf("Not enough minerals.\n");
			} 
		}
	}
	
	
	for(int i = 0; i < initial_workers; i++){
		pthread_join(workers[i], NULL);
	}

	printf("Map minerals %d, player minerals %d, SCVs %d, Marines %d", veins * 500, minerals, initial_workers, soldiers);

	END:
	for(int i = 0; i < veins; i++){
		pthread_mutex_destroy(&workers_mutex[i]	);
	}

	pthread_mutex_destroy(&command_mutex);
	
	free(mineral_blocks);
	free(workers);
	free(workers_mutex);
	
	return 0;
}
