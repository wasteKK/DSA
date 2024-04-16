#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

int i;
int a[3][3] = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
int b[3][3] = {{10, 11, 12},{13, 14, 15},{16, 17, 18}};
int res[3][3];

void * print(void *i)
{
	int *j=(int *)i;
	int sum = 0;
	int m, k;
	printf("Hi I am thread %d\n", *j);

	for(m=0; m<3; m++)
		res[*j][m]=0;
	
	for(m=0; m<3; m++)
	{
		for(k=0; k<3; k++)
			res[*j][m]+=a[*j][k] * b[k][m]; 
	}
	pthread_exit(0);
}

int main()
{
	int p, q;
	pthread_t tid[3];
	
	for(i=0; i<3; i++) {
		pthread_create(&tid[i], NULL, print,(void *)&i);
		sleep(1);
	}
		
	for(i=0; i<3; i++)
		pthread_join(tid[i], NULL);
		
	printf("Result: \n");
	for(p=0; p<3; p++)
	{
		for(q=0; q<3; q++)
			printf("%d\t", res[p][q]);
		printf("\n");
	}
}
