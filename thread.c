#include<pthread.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<stdio.h>

int v[4] = {1,2,3,4};

void *matrixeval(void *val) {
	int *i = (int *)val;
	printf("Hi i am thread %d\n",(*i) + 1);
	v[*i] *= 2;
	pthread_exit(NULL);
}

int main(){
	pthread_t tid[4]; int i,j;

	for (i=0; i<4; i++){
		pthread_create(&tid[i], NULL, matrixeval, (void *)&i);
		sleep(1); 
	}
	for (i=0; i<4; i++)
		pthread_join(tid[i], NULL);
	
	for(int i = 0; i<4; i++) printf("%d",v[i]);
	return 0;
}
