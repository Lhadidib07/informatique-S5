#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define IDENTIFIANT_UL 260
#define NOMBRE_UL 261
#define OPERATEUR_ARETHMETIQUE 262
#define SEPARATEUR_VIRGULE 263
#define SEPARATEUR_POINT_VIRGULE 264
#define ACCOLADE_OUVRANTE 265
#define ACCOLADE_FERMANTE 266
#define OPERATEUR_RELATIONNEL 267
#define OPERATEUR_LOGIQUE 268
#define SELECT_KW 269
#define FROM_KW 270
#define WHERE_KW 271
#define COUNT_KW 272
#define DISTINCT_KW 273
#define EPSILON 111
#define FIN_SUITE_UL (#) 333
#define ERREUR -99

int detecter_operateur_relationnel(char c){
    switch(c){
        case '>':
        case '<':
           return 1;
        default :
            return 0;
        break;
    }
}
int code_idetifiant(char* c0){

  if(strcmp(c0,"select")==0 || strcmp(c0,"SELECT")== 0)
    return SELECT_KW;
  else if(strcmp(c0,"from")==0 || strcmp(c0,"FROM") == 0)
    return FROM_KW;
  else if(strcmp(c0,"where")== 0 || strcmp(c0,"WHERE")==0)
    return WHERE_KW;
  else if(strcmp(c0,"count")== 0 ||strcmp(c0,"COUNT")==0)
    return COUNT_KW;
  else if(strcmp(c0,"distinct")==0 || strcmp(c0,"DISTINCT")==0)
    return DISTINCT_KW;
  else if(strcmp(c0,"and")== 0 || strcmp(c0,"AND")==0)
    return OPERATEUR_LOGIQUE;
  else if(strcmp(c0,"or")==0 || strcmp(c0,"OR")==0)
    return OPERATEUR_LOGIQUE;
    else
     return IDENTIFIANT_UL;
}
int detecter_code_operateur(char *c){
    switch(*c){
        case '+':
        case '/':
        case '*':
        case '-':
        case '=':
          return OPERATEUR_ARETHMETIQUE;
        break;
        case ';':
         return SEPARATEUR_POINT_VIRGULE;
        break;
        case ',':
         return SEPARATEUR_VIRGULE;
        break;
        case '[':
         return ACCOLADE_OUVRANTE;
        break;
        case ']':
         return ACCOLADE_FERMANTE;
        break;
        case '>':
        case '<':
        case ')':
        case '(':
        return OPERATEUR_RELATIONNEL;
        default :
            return ERREUR;
        break;
    }
}
int detecter_separateur(char c){
    switch (c)
    {
      case ' ':
      case '\0':
      case '\n':
      case '\t':
          return 1;
      break;

      default:
        return 0;
    
    }
}
int detecter_operateur(char c){
    switch(c){
        case '+':
        case '-':
        case '/':
        case '*':
        case '=':
        case ';':
        case ',':
        case '(':
        case ')':
        case '>':
        case '<':
           return 1;
        break;
        default :
            return 0;
        
    }
}
typedef struct Unite_Lexicale {
 char Lexeme[20];
 int code;
 int ligne;
 struct Unite_Lexicale* Suivant;
} UL;

UL* Inserer_a_la_fin(UL* les_mots_de_laphrase, char* mot,int code,int ligne){
  // si la liste chainee est vdie
  printf("je suis dans la fonction inserer a la fin ");

  if(les_mots_de_laphrase==NULL){
    les_mots_de_laphrase=malloc(sizeof(UL));
    les_mots_de_laphrase->Suivant=NULL;
    strcpy(les_mots_de_laphrase->Lexeme,mot);
    les_mots_de_laphrase->ligne=ligne;
    les_mots_de_laphrase->code=code;

    return les_mots_de_laphrase;
  }

 // si la liste chainee n'est pas vide affecter le 1er element a un pointeur temporaire
  UL* dernier_mot=les_mots_de_laphrase;
  while(dernier_mot->Suivant!=NULL){
    dernier_mot=dernier_mot->Suivant;
  }
  dernier_mot->Suivant=malloc(sizeof(UL));
  strcpy(dernier_mot->Suivant->Lexeme,mot);
  dernier_mot->Suivant->ligne=ligne;
  les_mots_de_laphrase->code=code;
  dernier_mot->Suivant->Suivant=NULL;
  return les_mots_de_laphrase;
}

void afficher_liste(UL* les_mots_de_laphrase){
  if(les_mots_de_laphrase== NULL){
    printf("ma liste est vide \n");
  }
  else{
    printf("\n voila la liste apres le decoupage ");
    UL* tmp=les_mots_de_laphrase;
    while(tmp != NULL){
      printf("\n %s ligne : %d ",tmp->Lexeme,tmp->ligne);
      tmp=tmp->Suivant;
    }
  }
}

UL* AEF_sql(char *phrase,UL* phrase_decouper ){
  //printf("\nje suis dans la fonction  AEF ligne 166 ");
  char mot_tmp[20];
  int ligne=1; 
  int code; 
  int i, n;
  int index=0;
  int etat_automate=0;

  for(int i=0;i<=strlen(phrase);i++){
     // c'est un etat final et on a un separateur on ajoute le mot ensuite en ajoute le sepa
        if(( etat_automate == 1 || 2 || 4 || 5  ) && ( detecter_operateur(phrase[i]) || detecter_separateur(phrase[i]))){
          //  printf(" \n je suis dans le premier if");
            if(phrase[i]=='\n')
            ligne++; 
            if(detecter_separateur(phrase[i]) == 0 ){ 
            switch (etat_automate)
            {
            
            break;
            case 1:
                // cherche code identifiant avec switch
                code=code_idetifiant(mot_tmp);
            break;
            case 2:
                code=NOMBRE_UL;
            break;
            case 4:
                code=NOMBRE_UL;
            break;
            case 5:
                code=detecter_code_operateur(mot_tmp);
            break;
            default:
                code=ERREUR;
            break;
            }
            printf("\n le mot tmp est %s ",mot_tmp);
            phrase_decouper=Inserer_a_la_fin(phrase_decouper,mot_tmp,code,ligne);
            code=0;
            mot_tmp[0]='\0';
            index=0;
            
            if(detecter_operateur(phrase[i])){
                mot_tmp[index]=phrase[i];
                mot_tmp[index+1]='\0';
                code=detecter_code_operateur(mot_tmp);
                printf("\n le mot tmp est %s ",mot_tmp);
                phrase_decouper=Inserer_a_la_fin(phrase_decouper,mot_tmp,code,ligne);
                code=0; 
                mot_tmp[0]='\0';
                index=0;
            }


            }
    
           
        }
        else{
          //  printf("\n je suis dans le else  est phrase i est de %c ",phrase[i]);
            /**************************************************************/
            mot_tmp[index]=phrase[i];
            mot_tmp[index+1]='\0';
            index++;
           // printf("\n etat automates est de %d",etat_automate);
            switch(etat_automate){
                case 0:
               // printf("\n je suis apres la boucle dans le case 0 %c ",phrase[i]);
                if(detecter_operateur(phrase[i]))
                    etat_automate=0;
                else if ( detecter_operateur_relationnel(phrase[i]) )
                    etat_automate=5;
                else if(isdigit(phrase[i]))
                    etat_automate=2;
                else if(isalpha(phrase[i]))
                    etat_automate=1;
                    else{
                    printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d",phrase[i],ligne);
                    return 0;
                    }
                break;

                case 1:
                   // printf("\n je suis apres la boucle  dans le case 1 %c ",phrase[i]);
                    if(detecter_operateur_relationnel(phrase[i]) )
                    etat_automate=5;
                    else if(detecter_separateur(phrase[i]) )
                    etat_automate=0;
                    else if(isalpha(phrase[i]) || isdigit(phrase[i]))
                    etat_automate=1;
                    else{
                    printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d",phrase[i],ligne);
                    return 0;
                    }
                break;

                case 2:
                if(detecter_operateur_relationnel(phrase[i]) )
                    etat_automate=5;
                else if(detecter_separateur(phrase[i]) )
                    etat_automate=0;
                else if(isdigit(phrase[i]))
                    etat_automate= 2;
                else if( phrase[i]=='.')
                    etat_automate=3;
                 else{
                    printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d",phrase[i],ligne);
                    return 0;
                    }
                break;

                case 3:
                    if(isdigit(phrase[i]))
                    etat_automate= 4;
                    else{
                    printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d",phrase[i],ligne);
                    return 0;
                    }
                break;
                case 4:
                    if(isdigit(phrase[i]))
                    etat_automate= 4;
                    else if(detecter_separateur(phrase[i]) )
                    etat_automate=0;
                    else if(detecter_operateur_relationnel(phrase[i]) )
                    etat_automate=5;
                    else{
                    printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d",phrase[i],ligne);
                    return 0;
                    }
                break;

                case 5:
                    if(detecter_separateur(phrase[i]) )
                    etat_automate=0;
                    else if(isdigit(phrase[i]))
                    etat_automate= 2;
                    else if(isalpha(phrase[i]))
                    etat_automate=1;
                    else{
                    printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d",phrase[i],ligne);
                    return 0;
                    }
                break;
            }
        } 
   }
return phrase_decouper;
}

void afficher_Ul(UL* phrase_decouper1){
  UL* tmp=phrase_decouper1;
  while(tmp != NULL){
   printf("\n\t LEXEME = [ %s ] \t CODE = [ %d ] \t Ligne = [ %d ] ",tmp->Lexeme,tmp->code,tmp->ligne);
   // printf("\n\t LEXEME = [ %s ] \t  Ligne = [ %d ] ",tmp->Lexeme,tmp->ligne);
    tmp=tmp->Suivant;
  }
}

int main()
{
  char phrase[500]="select from  salam";
  printf("%s",phrase);
 //gets(phrase);
  UL* phrase_decouper = NULL;
  FILE *file;
  int i=0;
  /*file=fopen("text01.txt","r");
  if(file == NULL )
  printf("\n erreur le fichier ne c'est pas ouvert ");
  else{
    while ( !feof(file) ) {
     phrase[i]= fgetc(file);
     i++;
    }
    phrase[i]='\0';
  }*/
  phrase_decouper=AEF_sql(phrase,phrase_decouper);
  afficher_Ul(phrase_decouper);
    return 0;
}
