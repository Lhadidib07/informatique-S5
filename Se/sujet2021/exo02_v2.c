#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h> 
sem_t sema_1; 
sem_t sema_2;
sem_t sema_3;
sem_t sema_4;
sem_t sema_5;
sem_t sema_6;
//Fonctions correspondant au corps d'un thread(tache)
void *t1(void *inutilise);
void *t2(void *inutilise);
void *t3(void *inutilise);
int main(void)
{
sem_init(&sema_1,0,1);
sem_init(&sema_2,0,0);
sem_init(&sema_3,0,0);
sem_init(&sema_4,0,0);
sem_init(&sema_5,0,0);
sem_init(&sema_6,0,0);
pthread_t th1, th2,th3;
//les ID des de 3 thread
setbuf(stdout, NULL);
//pas de tampon sur stdout
printf("Je vais créer et lancer 3 threads:\n");

pthread_create(&th1, NULL, t1, NULL);
pthread_create(&th2, NULL, t2, NULL);
pthread_create(&th3, NULL, t3, NULL);
//printf("J'attends la fin des 3 threads\n");
pthread_join(th1, NULL);
pthread_join(th2, NULL);
pthread_join(th3, NULL);
printf("\nLes 3 threads se sont termines\n");
printf("Fin du thread principal\n");
pthread_exit(NULL);
return EXIT_SUCCESS;
}
void *t1( void *inutilise)
{ int i;
char c1 = '*';
for(i=1;i<=200;i++)
{
 sem_wait(&sema_1);
  write(1, &c1, 1);
 sem_post(&sema_2);
 
 sem_wait(&sema_6);
  write(1, &c1, 1);
   printf(" ");
 sem_post(&sema_1);
// écrit un caractère sur stdout(descripteur 1)
}
return NULL;
}

void *t2(void *inutilise)
{
int i;
char c1 = '#'; 

for(i=1;i<=200;i++)
{
 sem_wait(&sema_2); 
 write(1, &c1, 1);
 sem_post(&sema_3);
 
  sem_wait(&sema_5); 
 write(1, &c1, 1);
 sem_post(&sema_6);
 
}
return NULL;
}

void *t3(void *inutilise)
{
int i;
char c1 = '@';
for(i=1;i<=200;i++)
{
 sem_wait(&sema_3);
 write(1, &c1, 1);
  printf(" ");
 sem_post(&sema_4);
 
 sem_wait(&sema_4);
  write(1, &c1, 1);
 sem_post(&sema_5);
}

return NULL;
}
