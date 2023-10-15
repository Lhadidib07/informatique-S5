#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void * fct1()
{
sleep(1);
printf("SUR DES THREADS \n");
}
void * fct2()
{
printf("TP N°2\n");
}
void main()
{
pthread_t tid1,tid2;


pthread_create(&tid1,NULL,fct1,NULL);
pthread_create(&tid2,NULL,fct2,NULL);

pthread_join(tid1,NULL);
pthread_join(tid2,NULL);


}
