#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<wait.h>

int main(int argc, char *argv[]){
	printf("Main Function: \n");
	int retval=1;
	int wt;
	pid_t pid = fork();
	if(pid<0){
		printf("Error in fork operation\n");
	}
	if(pid==0){
		printf("PID for Child process: %d\nPID of its parent process: %d\n",getpid(),getppid());
		execl("./app2","app2", argv[1], NULL);
		exit(34);
	}
	else{
		
		printf("PID for Parent process: %d\nPID of its parent process: %d\n",getpid(),getppid());
		wait(&wt);
		if(WIFEXITED(wt))
		{
			printf("Child terminated normally %d \n",WEXITSTATUS(wt));
		}
		else if(WIFSIGNALED(wt)){
			printf("Child terminated abnormally %d \n",WTERMSIG(wt));
			exit(0);
		}
		
	}
	return 0;
}
