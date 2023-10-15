//progamme prod_cons.c
#include <semaphore.h>
#include <unistd.h>
#include <pthread.h>
#include <stdio.h>
#define N 3 //taille de tampon
int tampon[N];
void* consommateur(void *);
void* producteur(void *);
sem_t sema1, sema2;
int main()
{
	sem_init(&sema1,0, 1);
	sem_init(&sema2,0, 0);
	pthread_t th1,th2;
	//créer les threads
	pthread_create(&th1, NULL,consommateur, NULL);
	pthread_create(&th2, NULL, producteur, NULL);
	//attendre la fin des threads
	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	printf("ici programme principale, fin des threads \n");
	return 0;
}
void* producteur(void *depot)
{
	int i=0, nbprod=0, mess=0;
	
	do {
		//produire message
		sem_wait(&sema1);
		tampon[i]=mess;
		sem_post(&sema2);
		printf("\n ici prod. : tampon[%d]= %d\n", i,mess);
		i=(i+1)%N;
		mess++;
		nbprod++;
		sleep(2);
		
	}while ( nbprod<=5 );
	

	  return NULL;
}
void* consommateur(void *retrait)
{

int j=0, nbcons = 0, mess;
do {
	//consommation message
	sem_wait(&sema2);
	 mess = tampon[j];
	sem_post(&sema1);
	printf("\n ici cons. :tampon[%d]= %d\n",j,mess);
	j=(j+1)%N;
	nbcons++;
	sleep(2);
} while ( nbcons<=5 );

return (NULL);}
