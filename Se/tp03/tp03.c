#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <stdbool.h>
int v = 0;  
int tour=0; 
int c[2];
c[1]=0; 
c[2]=0;
void verou(  int i ) { 
	c[i]=1;
	tour =0 ; 
	while ( ( c[1-i] == 1 ) && ( tour = 1-i ) );  
}

void deverouller(int i){
 c[î]= 0; 
}


void * decremante(int *num)
{
	 for (int i = 0; i <= 10000; i++ ) {   
	    v--;
	    printf("\n thread %d %d ",num,v); 	 
	}
}

void main()
{
	pthread_t tid1,tid2;
	pthread_create(&tid1,verou,decremante,(void*)1);
	pthread_create(&tid2,verou,decremante,(void*)2);
	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);
}
/* gcc nom_excutable nom_fichier -lpthread  */
