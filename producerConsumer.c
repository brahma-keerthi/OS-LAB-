#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

sem_t empty, full;
pthread_mutex_t mutex;
int in = 0, out = 0;
int buffer[3];

void * producer( void *pno){
    for(int i = 0; i<3; ++i){
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);

    buffer[in] = rand()%1000;
    printf("PRODUCER - %d : Insert item %d at %d\n", *((int *)pno), buffer[in], in);
    in = (in + 1)%3;

    pthread_mutex_unlock(&mutex);
    sem_post(&full);
    }
}

void * consumer( void *pno ){
    for(int i = 0; i<3; ++i){
    sem_wait(&full);
    pthread_mutex_lock(&mutex);

    printf("CONSUMER - %d : Remove item %d at %d\n", *(int *)pno, buffer[out] , out);
    out = (out + 1)%3;

    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
    }
}

void main(){
    pthread_t con[3], pro[3];
    pthread_mutex_init(&mutex, NULL);
    sem_init(&empty, 0, 3);
    sem_init(&full, 0, 0);

    int a[3] = {1, 2, 3};

    for(int i = 0; i<3; ++i)
        pthread_create(&pro[i], NULL, (void *)producer, (void *)&a[i]);

    for(int i = 0; i<3; ++i)
        pthread_create(&con[i], NULL, (void *)consumer, (void *)&a[i]);

    for(int i = 0; i<3; ++i)
        pthread_join(pro[i], NULL);
    
    for(int i = 0; i<3; ++i)
        pthread_join(con[i], NULL);

    pthread_mutex_destroy(&mutex);
    sem_destroy(&empty);
    sem_destroy(&full);
}