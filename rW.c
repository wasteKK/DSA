#include<stdio.h>
#include<semaphore.h>
#include<pthread.h>
#include<stdlib.h>

pthread_t tidP[20],tidC[20];
sem_t wr,mutex;
int rC = 0;
int count = 0;

void* w(void *i){
	int *c = (int *)i;
	
	sem_wait(&wr);
	printf("wr %d writes %d\n",*c,++count);
	sem_post(&wr);
}

void* r(void *i){
	
	int *c = (int *)i;
	sem_wait(&mutex);
	rC++;
	if(rC == 1) sem_wait(&wr);
	sem_post(&mutex);
	printf("r %d reads %d\n",*c,count);
	sem_wait(&mutex);
	rC--;
	if(rC==0) sem_post(&wr);
	sem_post(&mutex);
}

int main(){
	
	sem_init(&wr,1,1);
	sem_init(&mutex,1,1);
	
	int wA[10] = {1,2,3,4,5,6,7,8,9,10};
	int rA[10] = {1,2,3,4,5,6,7,8,9,10};
	int p = 1,c = 1;
	int pC = 4,cC = 10;
	for(int i = 0; i<pC; i++) {pthread_create(&tidP[i],NULL,w,&wA[i]);}
	for(int i = 0; i<cC; i++) {pthread_create(&tidC[i],NULL,r,&rA[i]);}
	
	for(int i = 0; i<pC; i++) pthread_join(tidP[i],NULL);
	for(int i = 0; i<cC; i++) pthread_join(tidC[i],NULL);
	
	return 0;
}
