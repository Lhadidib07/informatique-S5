#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sema1, sema2;
void *T1(void *arg) {
sem_wait(&sema1);
printf("S");
sem_post(&sema2);
sem_wait(&sema1);
printf("S");
sem_post(&sema2);
sem_wait(&sema1);
printf("E");
sem_post(&sema2);
sem_wait(&sema1);
printf("E\n");
pthread_exit(NULL);
}
void *T2(void *arg) {
sem_wait(&sema2);
printf("Y");
sem_post(&sema1);
sem_wait(&sema2);
printf("T");
sem_post(&sema1);
sem_wait(&sema2);
printf("M");
sem_post(&sema1);
pthread_exit(NULL);
}
int main(){
sem_init(&sema1,0, 1);
sem_init(&sema2,0, 0);
pthread_t tid1, tid2;
pthread_create(&tid1,NULL,T1, NULL);
pthread_create(&tid2,NULL,T2, NULL);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
exit(0);
}
