#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sema1;
sem_t sema2;
sem_t sema3; 
void *T1(void *arg) {
 sem_wait(&sema3);
	printf("2");
	printf("0");
	printf("1");
	printf("9\n");
	sem_post(&sema3);
	pthread_exit(NULL);
 
}
void *T2(void *arg) {
sem_wait(&sema1);
printf("S");
printf("Y");
printf("S");
 sem_post(&sema2);
pthread_exit(NULL);

}
void *T3(void *arg) {
sem_wait(&sema2);
printf("T");
printf("E");
printf("M");
printf("E\n");
 sem_post(&sema3);
pthread_exit(NULL);
}
int main(){
	sem_init(&sema1,0, 1);
	sem_init(&sema2,0, 0);
	sem_init(&sema3,0, 0);
pthread_t tid1,tid2,tid3;
pthread_create(&tid1,NULL,T1, NULL);
pthread_create(&tid2,NULL,T2, NULL);
pthread_create(&tid3,NULL,T3, NULL);
pthread_join(tid1,NULL);
pthread_join(tid2,NULL);
pthread_join(tid3,NULL);
exit(0);
}
