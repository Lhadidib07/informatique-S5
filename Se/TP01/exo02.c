#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>
#include<stdlib.h>
void main(){
int id,i;
fork();
printf(" ecrit par le processus %ld  processus pere est %ld  A \n",getpid(),getppid()); 
if( (id=fork() ==0)){
 printf("ecrit par le processus %ld  processus pere est %ld  B\n",getpid(),getppid()); 
 exit(0); 
}
sleep(15);
wait(0);
printf("ecrit par le processus %ld  processus pere est %ld C \n",getpid(),getppid());
}

