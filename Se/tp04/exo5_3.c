#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<semaphore.h>
sem_t sema1, sema2,sema3;
//Fonctions correspondant au corps d’un thread(tache)
void *etoile(void *inutilise);
void *diese(void *inutilise);
void *arobase(void *inutilise);
//Remarque:le prototype d’une tâche doit être :
void *(*start_routine)(void *);
int main(void)
{
	sem_init(&sema1,0, 1);
	sem_init(&sema2,0, 0);
	sem_init(&sema3,0, 0);
	pthread_t thrEtoile, thrDiese,thrarobase;
	//les ID des de 3 thread
	setbuf(stdout, NULL);
	//pas de tampon sur stdout
	printf("Je vais créer et lancer 3 threads");
	pthread_create(&thrEtoile, NULL, etoile, NULL);
	pthread_create(&thrDiese, NULL, diese, NULL);
	pthread_create(&thrarobase, NULL, arobase, NULL);
	//printf("J’attends la fin des 3 threads\n");
	pthread_join(thrEtoile, NULL);
	pthread_join(thrDiese, NULL);
	pthread_join(thrarobase, NULL);
	printf("\nLes 3 threads se sont termines\n");
	printf("Fin du thread principal\n");
	pthread_exit(NULL);
	return EXIT_SUCCESS;
}

void *etoile( void *inutilise)
{ 
	int i;
	char c1 = '*';
	for(i=1;i<=200;i++)
	{
	sem_wait(&sema1);
	for(int j=2;j>0;j--)
	write(1, &c1, 1);
	sem_post(&sema2);
	// écrit un caractère sur stdout(descripteur 1)
	}
	return NULL;
}

void *diese(void *inutilise){
	int i;
	char c1 = '#';
	for(i=1;i<=200;i++)
	{
	sem_wait(&sema2);
	write(1, &c1, 1);
	sem_post(&sema3);
	}
	return NULL;
}

void *arobase(void *inutilise){
	int i;
	char c1 = '@';
	for(i=1;i<=200;i++)
	{
	sem_wait(&sema3);
	write(1, &c1, 1);
	sem_post(&sema1);
	}
	return NULL;
}
