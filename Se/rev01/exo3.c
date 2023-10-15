#include<sys/types.h>
#include<unistd.h> //pour fork()
#include<stdio.h> //pour printf()
#include<sys/wait.h>
#include <stdlib.h>
int main()
{
if(fork () == 0)
{
  printf(" T ");
  fflush(stdout);
  if(fork()==0)
  printf("E");
  fflush(stdout);
  
 exit(0); 
  
}
 wait(NULL);
if(fork () == 0)
{
  printf(" S ");
  fflush(stdout);
  if(fork()==0)
  printf("T");
  fflush(stdout);
  
 exit(0); 
 
}
wait(NULL);  
if(fork () == 0)
{
  printf(" T ");
  fflush(stdout);
  if(fork()==0)
  printf("P");
  
 exit(0); 
   
}
wait(NULL);
return 0 ;
}
