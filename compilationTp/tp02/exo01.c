#include<stdio.h>
#include<string.h>
#include<conio.h>
#include<ctype.h>
#include<stdlib.h>
int main(){
    char* login="Dib";
    char* mdps="a64DS";
    for(int i=0;i<strlen(login);i++){
      if(isdigit(login[i])){
         printf("\n le login contient un chifre ");
         break;
         return 0;
      }
    }
   if(mdps != login && strlen(mdps)>10){
      printf("\n le mpds est != du login ");
     for(int i=0;i<strlen(mdps);i++){  
      if(islower(mdps[i]) == 0 && isalpha(mdps[i]) !=0 ){
         printf(" \n la valeur de isLower pour le caractere %c est de %d ",mdps[i],islower(mdps[i]));
         printf(" \n mpds correct ");
         return 0;
      }
     }
     printf("\n inccorecte il nya pas de majiscule "); 
   }
   else{
      printf("inccorect login == mpds ou mdps < 10 ");
   }
      

   return 0;
}
