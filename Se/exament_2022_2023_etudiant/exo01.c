#include<sys/types.h>
#include<unistd.h> //pour fork()
#include<stdio.h> //pour printf()
#include<sys/wait.h> // pour le wait 
#include <stdlib.h>

	/* programme fait pas Dib Mohammed El-Hadi du groupe 03 */

int main(){
  
  if( fork() == 0 ) { 
    printf("BO"); 
    fflush(stdout);
    if(fork()==0){
    printf("N");
    fflush(stdout);
    exit(0); 
    }
    if(fork()==0){
    printf("N");
    fflush(stdout);
    exit(0);
    }
    wait(NULL);
    printf("E");
    fflush(stdout);
    exit(0); 
  }
  wait(NULL);
  if(fork()==0){
  printf(" A");
  fflush(stdout);
    if(fork()==0){
    printf("N");
    fflush(stdout);
    exit(0);
    }
    if(fork()==0){
    printf("N");
    fflush(stdout);
    exit(0);
    }
    wait(NULL); 
    printf("EE");
    fflush(stdout);
    exit(0);
  } 
  wait(NULL); 
  printf(" 2023");
return 0; 
}

