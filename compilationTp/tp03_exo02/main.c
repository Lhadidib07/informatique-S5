
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>
int AEF_commentaire(char* nbr){
  int  n=strlen(nbr); 
  int etat_automate=0,etat_final=4; 
  for(int i=0;(i<n);i++ ){
    switch (etat_automate){
      case 0: 
       if(nbr[i]=='/')
        etat_automate=1; 
        else 
         etat_automate=0; 
      break;
      case 1:
      if(nbr[i]=='*')
       etat_automate=2; 
       else 
       etat_automate=0; 
      break;
      case 2: 
       if(nbr[i]=='*')
        etat_automate=3;
         else if(( nbr[i] >= 'a' && nbr[i] <= 'z') || ( nbr[i]>= '0'  && nbr[i]<='9') || ( nbr[i]=='/' || nbr[i]=='\\' || nbr[i]==' ' || nbr[i]==','|| nbr[i]==';' || nbr[i]==':' ||nbr[i]=='!'|| nbr[i]=='?') || nbr[i]==10 ) 
          etat_automate=2; 
           else 
            etat_automate=0;
      break;
      case 3:
       if(nbr[i]=='/')
        etat_automate=4; 
        else if(nbr[i]=='*')
         etat_automate=3;
         else if(( nbr[i] >= 'a' && nbr[i] <= 'z') || ( nbr[i]>= '0'  && nbr[i]<='9') || ( nbr[i]==' ' || nbr[i]==','|| nbr[i]==';' || nbr[i]==':' ||nbr[i]=='!'|| nbr[i]=='?') )
           etat_automate=2;  
      break;
      case 4:
        if(nbr[i] >= '*' || ( nbr[i] >= 'a' && nbr[i] <= 'z') || ( nbr[i]>= '0'  && nbr[i]<='9') || ( nbr[i]=='/' || nbr[i]=='\\' || nbr[i]==' ' || nbr[i]==','|| nbr[i]==';' || nbr[i]==':' ||nbr[i]=='!'|| nbr[i]=='?')||nbr[i]==10) 
          etat_automate=0; 
          else 
           return (etat_automate==etat_final);          
      break;
    }
  }
  return (etat_automate==etat_final);
}


bool lire_ligne(char *chaine, size_t max)
{
    size_t i;

    for (i = 0; i < max - 1; ++i)
    {
        char c;

        if (scanf("%c", &c) != 1)
            return false;
        else if (c == '\n')
            break;

        chaine[i] = c;
    }

    chaine[i] = '\0';
    return true;
}


int main(void)
{
    char chaine[255];
    int choix ; 
    FILE *file; 
    int i=0; 
    
    do{
      printf("\n****************** exercice 02 du TP 03******************")
      printf("\n  0 pour sortir "); 
      printf("\n 1 pour voir si un mot appartient au langage "); 
      printf("\n 2 pour voir si un fichier appartient au langage "); 
      printf("\n faites votre choix :"); 
      scanf("%d",&choix); 
      switch (choix)
      {
        case 0:

        break;
        case 1: 
          fflush(stdin);
          printf("entrz votre chaine : ");
          if (lire_ligne(chaine, sizeof chaine)){ 
            if(AEF_commentaire(chaine))
             printf("\n appartient "); 
             else 
              printf("\n appartient pas ");
          }
        break;

        case 2:
        file=fopen("text.txt","r"); 
        if(file == NULL )
          printf("\n erreur le fichier ne c'est pas ouvert ");
          else{ 
            while ( ! feof( file ) ) {
              chaine[i]= fgetc( file );
              i++; 
            }
            chaine[i]='\0';
            printf("\n votre chain est : %s",chaine);
            if(AEF_commentaire(chaine))
              printf("\n appartient "); 
            else 
              printf("\n appartient pas ");
            i=0;   
          }
        break;

        default:
          printf("\n vous avez fait un mauvais choix "); 
        break;
      }
    }while (choix !=0); 
    
    return 0;
}