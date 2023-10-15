#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
int a =0;
sem_t sem1; 
sem_t sem2;
void* increment(void *arg);
void* decrement(void *arg);
int main ( )
{
sem_init(&sem1,0,1);
sem_init(&sem2,0,0);
pthread_t threadA;
pthread_t threadB;
printf("programme principale : a = %d\n", a);
pthread_create(&threadA, NULL, increment,NULL);
pthread_create(&threadB,NULL,decrement,NULL);
pthread_join(threadA,NULL);
pthread_join(threadB,NULL);
printf("programme principale, fin threads : a =%d \n",a);
return 0;
}
void* decrement(void *arg)
{
sem_wait(&sem2); 
a = a - 1 ;
sem_post(&sem1);
printf("thread B decrement : a=%d\n", a);
return (NULL);
}
void* increment (void *arg)
{
sem_wait(&sem1);
a = a + 1;
sem_post(&sem2);
printf("thread A increment : a = %d\n", a);
return (NULL);
}
