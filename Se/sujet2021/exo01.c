#include<sys/types.h>
#include<unistd.h> //pour fork()
#include<stdio.h> //pour printf()
#include<sys/wait.h> // pour le wait 
#include <stdlib.h>
 
 
int main(){
  if(fork()==0)
  {
   printf("T");
   fflush(stdout);
   if(fork()==0){
    printf("L");
    fflush(stdout);
    exit(0);
    }
    exit(0);
    wait(NULL);
   }
   
   if(fork()==0){
 
    if(fork()==0){
     printf("E"); 
     fflush(stdout);
     exit(0);
    }
    printf("M");   
    fflush(stdout);
    exit(0);
    wait(NULL);
   }
   
   if(fork()==0){
     if(fork()==0){
      printf("C");
      fflush(stdout);
      exit(0);
     }
    printf("E"); 
    fflush(stdout);
     exit(0); 
     wait(NULL); 
   }
   
      
    wait(NULL); 
    printf("N"); 
  return 0; 
}
  
