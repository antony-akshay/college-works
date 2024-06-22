#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>
#define BUFFERSIZE 5

int buffer[BUFFERSIZE];
int item=1;

sem_t mutex,empty,full;

void *producer(void *arg){
    int loops = *((int *)arg);
    for(int i=0;i<loops;i++){
        sem_wait(&empty);
        sem_wait(&mutex);
        buffer[item % BUFFERSIZE]=item;
        printf("PRODUCED ITEM: %d\n",item);
        sem_post(&mutex);
        sem_post(&full);
        item++;
    }
    pthread_exit(NULL);
}

void *consumer(void *arg){
    int loops = *((int *)arg);
    for(int i=0;i<loops;i++){
        sem_wait(&full);
        sem_wait(&mutex);
        int item=buffer[item%BUFFERSIZE];
        printf("CONSUMED ITEM: %d\n",item);
        sem_post(&mutex);
        sem_post(&empty);
        item--;
    }
    pthread_exit(NULL);
}

int main(){

    int loops;
    printf("enter the no of processes");
    scanf("%d",&loops);


    sem_init(&mutex,0,1);
    sem_init(&full,0,0);
    sem_init(&empty,0,BUFFERSIZE);

    pthread_t producerThread,consumerThread;

    pthread_create(&producerThread,NULL,producer,&loops);
    pthread_create(&consumerThread,NULL,consumer,&loops);

    pthread_join(producerThread,NULL);
    pthread_join(consumerThread,NULL);

    sem_destroy(&empty);
    sem_destroy(&full);
    sem_destroy(&mutex);
    
    return 0;
}