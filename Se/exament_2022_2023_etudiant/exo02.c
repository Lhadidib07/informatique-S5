#include<sys/types.h>
#include<unistd.h> //pour fork()
#include<stdio.h> //pour printf()
#include<sys/wait.h> // pour le wait 
#include <stdlib.h>
#include <pthread.h> // pour les thread 
#include <semaphore.h>

	/* programme fait pas Dib Mohammed El-Hadi du groupe 03 */

sem_t sem1,sem2,sem3; 
sem_t sem4,sem5,sem6; 
sem_t sem7,sem8; 

void *T1(void *arg){
 sem_wait(&sem1);
 printf("\n T"); 
 sem_post(&sem2);
 
 sem_wait(&sem3);
 printf("ST "); 
 sem_post(&sem4);
 
 sem_wait(&sem8);
 printf("RE \n"); 
 
 pthread_exit(NULL);
} 

void *T2 ( void *arg){
sem_wait(&sem2);
printf("E"); 
sem_post(&sem3);

sem_wait(&sem5);
printf("P "); 
sem_post(&sem6);

sem_wait(&sem7);
printf("PHO");
sem_post(&sem8);

 
pthread_exit(NULL);

}

void *T3(void *arg){
sem_wait(&sem4);
printf(" T"); 
sem_post(&sem5);

sem_wait(&sem6);
printf(" SEMA");
sem_post(&sem7); 

pthread_exit(NULL);
}
int main(){
  
  sem_init(&sem1,0,1);
  sem_init(&sem2,0,0);
  sem_init(&sem3,0,0);
  sem_init(&sem4,0,0);
  sem_init(&sem5,0,0);
  sem_init(&sem6,0,0);
  sem_init(&sem7,0,0);
  sem_init(&sem8,0,0);
  
  pthread_t tid1,tid2,tid3; 
  
  pthread_create(&tid1,NULL,T1,NULL); 
  pthread_create(&tid2,NULL,T2,NULL); 
  pthread_create(&tid3,NULL,T3,NULL); 
  pthread_join(tid1,NULL); 
  pthread_join(tid2,NULL); 
  pthread_join(tid3,NULL); 
 exit(0); 
}

