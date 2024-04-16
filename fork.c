#include<stdio.h>
#include<unistd.h>

int main(){
	pid_t pid;
	int n=5;
	if(pid<0){
		printf("error occured while creating new child process\n");
	}
	else if(pid==0){
		n++;
		printf("iam child process\n");
		printf("n = %d\n",n);
		printf("pid of child : %d\n",getpid());
	}
	else if {
	n=n+2;
	printf("iam parent process\n");
	printf("n = %d\n",n);
	printf("pid of parent : %d\n",getpid());
	}
}
