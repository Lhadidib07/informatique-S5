#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#define TRUE 1
#define FALSE 0
#define T 5
int cpt=0;
sem_t sema1; // declaration globale du semaphores 
sem_t sema2; 
/* UTILE POUR LES SEMAPHORES */
/* UTILE POUR LES THREADS */
void *f0();
void *f1();
void *f0(void *arg)
{
int i;
while (TRUE)
{
// sem_wait(&sema1); // pour stoper le sema 1 
printf("<<Je suis le thread 1\n");
for (i=1;i<=3;i++) {
printf("\tA");
}
printf("\n");
/* Pour s'arreter */
cpt++;
// sem_post(&sema2); // déclanché le sema 2 
if (cpt > T) exit(0);
}
}

void *f1(void *arg)
{
int i;
while (TRUE)
{
// sem_wait(&sema2); // stoper le sema 2
printf(">>Je suis le thread 2\n");
for (i=4;i<=6;i++) {
printf("\tB");
}
printf("\n");
/* Pour s'arreter */
cpt++;
// sem_post(&sema1); // declancher le sema 1 
if (cpt > T) exit(0);
}
}

int main(int argc, char **argv)
{
sem_init(&sema1,0,1); // initialisation du semaphore crée plus haut 
//sem_init(&sema2,0,0);
pthread_t thread0, thread1;
int i=1;
/* initialisation des sémaphores */
/* création des threads avec fonction à
exécuter */
pthread_create( &thread0, NULL, &f0, NULL);
pthread_create( &thread1, NULL, &f1, NULL);
/* attend que tous les threads soient terminés */
pthread_join( thread0, NULL);
pthread_join( thread1, NULL);
return(0);
}
