#include<sys/types.h>
#include<unistd.h> //pour fork()
#include<stdio.h> //pour printf()
#include<sys/wait.h>
#include <stdlib.h>
int main()
{
printf("\n Bonjour  ");
 fflush(stdout);
if(fork () == 0)
{
printf(" Monsieur  ");
exit(0);
}
else
{

printf("Madame ");
wait(NULL);
exit(0);
}
return 0 ;
}
