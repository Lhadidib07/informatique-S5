#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main()
{
int id, i ;
fork();
printf("A\n");
if ((id=fork()==0)) {
printf("B\n");
exit(0);
}
wait(0);
printf("C\n");
}
