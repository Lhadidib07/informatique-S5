#include <pthread.h>
#include <stdio.h>
void* fct1(void *arg);
void* fct2(void *arg);
void* fct3(void *arg);
int main ( )
{
pthread_t threadA;
pthread_t threadB;
pthread_t threadC;
printf("debut execution de mes threads\n");
pthread_create(&threadA, NULL,fct1,NULL);
pthread_create(&threadB,NULL,fct2,NULL);
pthread_create(&threadC,NULL,fct3,NULL);
pthread_join(threadA,NULL);
pthread_join(threadB,NULL);
pthread_join(threadC,NULL);
printf("fin de mes
threads\n");
return 0;
}
void* fct1(void *arg)
{
int i;
printf("je suis le thread A\n");
for(i=1; i<=3; i++)
{ printf("%d\n",i);}
return (NULL);
}
void* fct2(void *arg)
{
int i;
printf("je suis le thread B\n");
for(i=4; i<=6; i++)
{ printf("%d\n",i);}
return (NULL);
}
void* fct3(void *arg)
{
int i;
printf("je suis le thread C\n");
for(i=7; i<=10; i++)
{ printf("%d\n",i);}
return (NULL);
}
