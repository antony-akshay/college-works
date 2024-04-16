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
    shmid=shmget(key,1024,0666);
    printf("key of shared memory is %d\n",shmid);
	shared_memory=shmat(shmid,NULL,0);
    printf("process attached at %p\n",shared_memory);
    printf("data read from shared memory is %s\n",(char*)shared_memory);
}