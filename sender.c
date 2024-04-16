#include<unistd.h>
#include<sys/ipc.h>
#include<sys/shm.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	void *shared_memory;
	char buffer[100];
	int shmid;
	key_t key = 1222;
	shmid=shmget(key,1024,0666|IPC_CREAT);
	printf("key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
	printf("process attached at %p\n",shared_memory);
	printf("enter some data to write to shared memory:\n");
	read(0,buffer,100);
	strcpy(shared_memory,buffer);
	printf("you wrote is:%s",(char*)shared_memory);
}