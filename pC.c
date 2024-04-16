#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t tidP[20],tidC[20];
sem_t full,empty,mutex;
int count = 0;

void* p(void *i){
	sem_wait(&empty);
	sem_wait(&mutex);
	printf("p prod: %d\n",++count);
	sem_post(&mutex);
	sem_post(&full);
}

void* c(void *i){
	sem_wait(&full);
	sem_wait(&mutex);
	printf("c cons: %d\n",count--);
	sem_post(&mutex);
	sem_post(&empty);
}

int main(){
	sem_init(&empty,1,5);
	sem_init(&full,1,0);
	sem_init(&mutex,1,1);
	
	int pC = 5,cC = 3;
	for(int i = 0; i<pC; i++) pthread_create(&tidP[i],NULL,p,NULL);
	for(int i = 0; i<cC; i++) pthread_create(&tidC[i],NULL,c,NULL);
	
	for(int i = 0; i<pC; i++) pthread_join(tidP[i],NULL);
	for(int i = 0; i<cC; i++) pthread_join(tidC[i],NULL);
	
	return 0;
}
