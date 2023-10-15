#include<sys/types.h>
#include <sys/wait.h>
#include<unistd.h>
#include<stdio.h> 
#include<stdlib.h> 
int main()
{ 
	printf("\t le pére \n"); 
	fflush(stdout);
	if(fork()==0 ){
		 printf(" T  \n");
		 fflush(stdout);
		 if(fork()==0){
			 printf(" E ");
			 exit(0);
		 }
		 wait(NULL);
		 exit(0);
	}
	else{
		wait(NULL);
	} 
	 
	if(fork()==0 ){
		 printf("\t s \n");
		 if(fork() ==0){
		 printf("\t T \n");
		 exit(0);
		 }
		 wait(NULL);
		 exit(0);
	}else{
	wait(NULL);
	}

	if(fork()==0 ){
		 printf("\t\t T  \n");
		 if(fork() ==0){
			 printf("\t\t P \n");
			 exit(0);
		 }
		 wait(NULL);
		 exit(0);
	}

return 0 ;
}

/* programme 3 reponse */
/* le procesus pére ecris bonjour  
   crée le fork une copie du programme principale et ecris Monsieur 
   le fork ecris bonjour ensuite le pére ecris madame */  
   
   
   
   
