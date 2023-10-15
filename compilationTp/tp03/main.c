#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdio.h>

int AEF_binnair_110(char* nbr){
    int i, n=strlen(nbr);
    int etat_automate=0, etat_finale=3;
    // parcourir la chaine de caract�res
    for(i=0; (i<n) && (nbr[i]!='\0'); i++)
    switch(etat_automate){
        // si le chiffre courant == 0 ou 5 le nombre devient multiple de 5
        case 0:

        if(nbr[i]=='0')
          etat_automate=0;
        // le premier caract�re 0
         else
          etat_automate=1;
        break;
        // si le chiffre courant == 0 ou 5 le nombre reste multiple de 5
        case 1: if(nbr[i]=='1')
        etat_automate=2;
         // sinon le nombre n'est pas un multiple de 5
         else
         etat_automate= 0;
        // si le caract�re n'est pas un chiffre, ce n'est pas un nombre et ce n'est pas multiple de 5 (a cet �tape)
        break;
        case 2: if(nbr[i]=='0')
         etat_automate= 3;
        else
          etat_automate= 2;
        break;
        case 3:
         if(nbr[i]='0')
          etat_automate= 0;
          else
            etat_automate=3;
        break;
    }
    // teste si l'�tat courant apr�s le parcours de la chaine de caract�re est un �tat final (Q1 est l'�tat final)
    return (etat_automate==etat_finale);
}

/************** question 02 *****************/

int AEF_xml(char nbr[20]){
  //printf("\n l'automate qu'on vas traiter et %s \n ",nbr);
  int i=0, n=strlen(nbr);
  int etat_automate=0, etat_finale=4;
  // parcourir la chaine de caract�res
  for(i=0; (i<n) && (nbr[i]!='\0'); i++){
    switch(etat_automate){
      case 0:
       if(nbr[i]=='<')
        etat_automate=1; 
        else 
         etat_automate=0; 
      break;

      case 1:
       if(nbr[i] >='a' && nbr[i] <= 'z' )
        etat_automate=3; 
        else if(nbr[i] =='/')
         etat_automate=2; 
         else 
          return 0; 
      break;

      case 2:
      if(nbr[i]=='>')
        etat_automate=4; 
        else if(nbr[i] >='a' && nbr[i] <= 'z' )
         etat_automate=3;
         else 
          return 0; 
      break;
      case 3:
       if(nbr[i] >='a' && nbr[i] <= 'z' )
        etat_automate=3;
        else if(nbr[i]=='>')
         etat_automate=4; 
         else
          return 0;  
      break;
    }
}
return ( etat_automate == etat_finale ) ; 
}

                            /************** question 03 *****************/
// une formule mathematique peut pas etre un chifre seul 
int AEF_formules_mathematiques(char* nbr){
    int i, n=strlen(nbr);
    int etat_automate=0, etat_finale=4;
    // parcourir la chaine de caract�res
    for(i=0; (i<n) && (nbr[i]!='\0'); i++)
    switch(etat_automate){
      case 0:
       if(nbr[i]>=  '0' && nbr[i] <= '9')
        etat_automate=1; 
         else
          return 0;  
      break;

      case 1:
        if(nbr[i]>= '0'  && nbr[i]<='9')
          etat_automate=2; 
          else if(nbr[i] == '+' || nbr[i] == '-'  || nbr[i] == '*' || nbr[i] == '/') 
           etat_automate=3;
           else 
            return 0; 
      break;
      case 2:
        if(nbr[i]>='0' && nbr[i]<='9')
          etat_automate=2;
           else if(nbr[i] == '+' || nbr[i] == '-'  || nbr[i] == '*' || nbr[i] == '/')
            etat_automate=3;
            else
             return 0;     
      break;

      case 3:
       if(nbr[i]>='0' && nbr[i]<='9')
        etat_automate=4;
         else 
         return 0;  
      break;
      
      case 4:
      if(nbr[i]>=0 && nbr[i]<=9)
        etat_automate=4;
        else if(nbr[i] == '+' || nbr[i] == '-'  || nbr[i] == '*' || nbr[i] == '/')
         etat_automate=3;
          else 
           return (etat_automate==etat_finale);
      break;
     

    }
    // teste si l'�tat courant apr�s le parcours de la chaine de caract�re est un �tat final (Q1 est l'�tat final)
    return (etat_automate==etat_finale);
}
                            /************** question 04 *****************/
 // le chifre le plus a droite est un chifre paire 
  int AEF_paire(char* nbr){
    int i, n=strlen(nbr);
    int etat_automate=0, etat_finale=1;
    // parcourir la chaine de caract�res
    for(i=0; (i<n) && (nbr[i]!='\0'); i++)
    switch(etat_automate){
      case 0: 
        if(nbr[i]=='0'|| nbr[i]=='2' || nbr[i]=='4' || nbr[i]=='6' || nbr[i]=='8')
          etat_automate=1; 
          else if(nbr[i]=='1'|| nbr[i]=='3' || nbr[i]=='5' || nbr[i]=='7' || nbr[i]=='9')
            etat_automate=0; 
            else 
            return 0; 
      break; 
      case 1:
        if(nbr[i]=='0'|| nbr[i]=='2' || nbr[i]=='4' || nbr[i]=='6' || nbr[i]=='8')
          etat_automate=1; 
          else if(nbr[i]=='1'|| nbr[i]=='3' || nbr[i]=='5' || nbr[i]=='7' || nbr[i]=='9')
            etat_automate=0; 
            else 
            return 0; 
      break;
    }
    // teste si l'�tat courant apr�s le parcours de la chaine de caract�re est un �tat final (Q1 est l'�tat final)
    return (etat_automate==etat_finale);
}

/******************************** exercice 02 ****************************************/

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
         else 
          etat_automate=2; 
      break;
      case 3:
       if(nbr[i]=='/')
        etat_automate=4; 
        else if(nbr[i]=='*')
         etat_automate=3;
          else 
           etat_automate=2;  
      break;
      case 4:
       if ( nbr[i] ) 
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


int main()
{

    char bin[50];
    char xml[10];
    char formule_math[10];
    char paire[10];
    char chifre[5]; 
    char c; 
    char chaine[255];
    int choix ; 
    FILE *file; 
    int i=0; 
    do{
     printf("\n****************** exercice 01 du TP 03********************");
     printf("\n 1) - pour tester si une  suite binaire  se termine par 110 ");
     printf("\n 2) -  pour voir si le mot entrer est une balise xml </> ");
     printf("\n 3) -  pour tester si le mot est une formule arithmetique"); 
     printf("\n 4) -  pour tester si le mot entré appartient au langage qui reconnait que des chifres paire "); 
     printf("\n 5) -  afficher les nombre pair et impaire compris entre 20 et 55 "); 
     printf("\n****************** exercice 02 du TP 03******************");
     printf("\n 6) -  pour voir si un mot appartient au langage "); 
     printf("\n 7) - pour voir si un fichier appartient au langage "); 
     printf("\n entrez votre choix : ");
     scanf("%d",&choix);

    switch(choix ){
      case 0:
      break;

      case 1:
          printf("\n entrz un mot  : ");
          scanf("%s",&bin);
          if(AEF_binnair_110(bin))
              printf(" le mot %s  appartient au langage ",bin);
          else
            printf("le mot %s  appartient pas au langage  ",bin);
      break;

      case 2:
          printf("\n entrz un mot  : ");
          scanf("%s",&xml);
          if(AEF_xml(xml))
              printf("\n le mot %s  appartieent au langage  ",xml );
          else
            printf("\n le mot %s  appartient pas  au langage  ",xml);
      break;
      case 3:
        printf("\n entrz un mot  : ");
        scanf("%s",&formule_math);
        if(AEF_formules_mathematiques(formule_math))
          printf("\n le mot %s  appartient au langage  ",formule_math );
        else
          printf("\n le mot %s  appartient pas au langage  ",formule_math );
            
      break;
      case 4:
        printf("\n entrz un mot  : ");
        scanf("%s",&paire);
        if(AEF_paire(paire))
          printf("\nle mot %s  appartient au langage  \n ",paire); 
          else
          printf("\n le mot %s  appartient pas au langage  \n",paire );
        paire[0]='\0';
      break;
      case 5:
      for(int i=20;i<=55;i++){
        sprintf(chifre,"%d",i);  // pour passer d'un int a un char  
        if(AEF_paire(chifre))
        printf("\n %s est paire ",chifre); 
        else 
          printf("\n %s est impaire ",chifre);
      }
      paire[0]='\0';
      break;
      case 6:
       fflush(stdin);
        printf("entrz votre chaine : ");
        if (lire_ligne(chaine, sizeof chaine)){ 
          if(AEF_commentaire(chaine))
           printf("\n appartient "); 
          else 
            printf("\n appartient pas ");
        }
      break;

      case 7:
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
          printf("vous avez fait le mauvait choix ");
      break;
    }
  }while(choix !=0 );
  return 0;
}
