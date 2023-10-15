#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
typedef struct Mot_De_La_Phrase {
 char Mon_mot[20];
 struct Mot_De_La_Phrase* Adresse_Mot_suivant;
}Mot;

Mot* Inserer_a_la_fin(Mot* les_mots_de_laphrase, char* mot){
  // si la liste chainee est vdie
  // printf("\n je suis dans la fonction Inserer a la fin \n");
    if(les_mots_de_laphrase==NULL){
      // cration de la liste / reservation de memoire pour le 1er element
      les_mots_de_laphrase=malloc(sizeof(Mot));
      // c'est le 1er et dernier element (donc le prochain element est NULL)
      les_mots_de_laphrase->Adresse_Mot_suivant=NULL;
      // copier le mot
      strcpy(les_mots_de_laphrase->Mon_mot,mot);
      // retourner l'addresse du 1er element
      return les_mots_de_laphrase;
    }

 // si la liste chainee n'est pas vide affecter le 1er element a un pointeur temporaire
    Mot* dernier_mot=les_mots_de_laphrase;
    // tant que le pointeur suivant n'es pas NULL ( tant qu'on est pas arrivé au dernier )
    while(dernier_mot->Adresse_Mot_suivant!=NULL){
      // passer a l'element suivant
     dernier_mot=dernier_mot->Adresse_Mot_suivant;
    }
    // creer un nouvel element a la fin de la liste
    dernier_mot->Adresse_Mot_suivant=malloc(sizeof(Mot));
    // copier le mot
    strcpy(dernier_mot->Adresse_Mot_suivant->Mon_mot,mot);
    // c'est le 1er et dernier element (donc le prochain element est NULL)
    dernier_mot->Adresse_Mot_suivant->Adresse_Mot_suivant=NULL;
    // retourner l'addresse du 1er element
    return les_mots_de_laphrase;
}

Mot* Inserer_au_debut(Mot* les_mots_de_laphrase,char* mot){

  // creer un nouvel element
 Mot* premier_mot=malloc(sizeof(Mot));
 // copier la chaine de caractere
 strcpy(premier_mot->Mon_mot,mot);
 // affecter le pointeur du suivant au debut de le liste principale
 premier_mot->Adresse_Mot_suivant=les_mots_de_laphrase;
 // retourner l'@ du 1er element
 return premier_mot;
}

void afficher_liste(Mot* les_mots_de_laphrase){
  if(les_mots_de_laphrase->Adresse_Mot_suivant == NULL){
    printf("ma liste est vide \n");
  }
  else{
    Mot* tmp=les_mots_de_laphrase;
     // on affiches
    // printf("%s",tmp->Mon_mot);
    /*traversé le liste jusqu'au bout de la liste*/
    while(tmp->Adresse_Mot_suivant != NULL){
         printf("\n%s",tmp->Mon_mot);
        tmp=tmp->Adresse_Mot_suivant;
         /* on passe au suivant */
    }
  }
}




int separateur(char c){
    switch(c){
        case ',':
            return 1;
        break;
         case ';':
            return 1;
        break;
        case '.':
            return 1;
        break;
        case '!':
            return 1;
        break;
        case '?':
            return 1;
        break;
        case '-':
            return 1;
        break;
        case ' ':
            return 1;
        break;
        case '\0':
            return 1;
        break;
        default :
            return 0;
        break;

    }
}

Mot* decouper(char *phrase,Mot* phrase_decouper){
 char mot_tmp[20];
 int index=0;
 printf("\n la longueur de la phrase est de %d",strlen(phrase));
 for(int i=0;i<=strlen(phrase);i++){
    if(separateur(phrase[i])==0){
        mot_tmp[index]=phrase[i];
        mot_tmp[index+1]='\0';
        index++;
    }
     else{
         if(index !=0 ){
            printf("l\n e mot inserer dans la fonction de couper %s \n",mot_tmp);
            phrase_decouper=Inserer_a_la_fin(phrase_decouper,mot_tmp);
            mot_tmp[0]='\0';
            index=0;
         }
     }
 }
 return phrase_decouper;
}

int main(){
 //printf(" entrez une phrase : \n ");
 char phrase[500];
// gets(phrase);
 Mot* phrase_decouper = NULL;
 //printf("\n------------------la phrase avant le decoupage ------------- ");
 //printf("\n %s",phrase);
 phrase_decouper=decouper("111 222 333",phrase_decouper);
 printf("\n------------------la phrase apres le decoupage ------------- ");
 printf("\n voila la liste a la fin : \n");
 afficher_liste(phrase_decouper);
 return 0; 
}
