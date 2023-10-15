#include<sys/types.h>
#include<unistd.h> //pour fork()
#include<stdio.h> //pour printf()
#include <stdlib.h> 
#include <sys/wait.h>
int main()
{
printf("Bonjour ");
fflush(stdout);
if(fork () == 0)
{
printf("Monsieur\n");
exit(0);
}
else
{
printf("Madame\n");
wait(NULL);
exit(0);
}
return 0 ;
}
