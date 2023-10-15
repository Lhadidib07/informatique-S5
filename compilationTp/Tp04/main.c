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
/*revoir le fonctionnementde strcmp */

/* fonction ta3 les mots clé apres AEF strcmp() */

int code_idetifiant(char* c0){

  if(strcmp(c0,"select")==0 || strcmp(c0,"SELECT")==0)
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
int detecter_code_operateur(char* c){
    switch(*c){
        case '+':
        case '/':
        case '*':
        case '-':
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
        case '=':
        return OPERATEUR_RELATIONNEL;
        default :
            return ERREUR;
        break;
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
        default :
            return 0;
        break;
    }
}

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

int detecter_separateur(char c){ // juste pour AEF est c 
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
        break;
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
  dernier_mot->Suivant->code=code;
  dernier_mot->Suivant->Suivant=NULL;
  return les_mots_de_laphrase;
}

UL* decouper(char *phrase,UL* phrase_decouper){
 //printf("\n je suis dans la fonction decouper : %s ",phrase);
 char mot_tmp[20];
 int index=0;
 int ligne=1;
 int code=0;
 int i=0;
 int i1=0;
 //printf("\n la longueur de la phrase est de %d",strlen(phrase));
 //printf("\n la chaine est composer de %d",langeur_chaine);
 //printf("\n le dernier caractere est le : %c",phrase[90]);
 for( i=0; i<=strlen(phrase);i++){
    if( ( detecter_separateur(phrase[i])==0 && detecter_operateur(phrase[i])==0 ) ){ 
      mot_tmp[index]=phrase[i];
      mot_tmp[index+1]='\0';
      index++;
    }
    else{
      if(index !=0 ){
     // printf("\n\t le mot que je vais insere  %s ", mot_tmp);
      phrase_decouper=Inserer_a_la_fin(phrase_decouper,mot_tmp,0,ligne);
      mot_tmp[0]='\0';
      index=0;
      }
      if(( detecter_operateur(phrase[i])) ){
       // printf("\n je suis dans l'insertion de operateur ");
        mot_tmp[index]=phrase[i];// ; 
        mot_tmp[index+1]='\0';
        code=detecter_code_operateur(mot_tmp);
        //printf("\n\t\t  je vais inseré le  dans le 2eme if du decouper %s",mot_tmp);
        phrase_decouper=Inserer_a_la_fin(phrase_decouper,mot_tmp,0,ligne);
        mot_tmp[0]='\0';
        index=0;
      }
      if(phrase[i]=='\n'){
      ligne++;
      }
    }
  }
 /* printf("\n \t\t\t\t mot tmp : ==> %d",mot_tmp);
  phrase_decouper=Inserer_a_la_fin(phrase_decouper,mot_tmp,0,ligne);*/
 return phrase_decouper;
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

void afficher_Ul(UL* phrase_decouper1){
  if(phrase_decouper1 != NULL)
 printf("\n\t\t AFFICHAGE DE LA SUITE DES UNITES LEXICALES \n \n");
  UL* tmp=phrase_decouper1;
  while(tmp != NULL){
    printf("\n\t LEXEME = [ %s ] \t CODE = [ %d ] \t Ligne = [ %d ] ",tmp->Lexeme,tmp->code,tmp->ligne);
    tmp=tmp->Suivant;
  }
}

int AEF_sql(char *phrase,int ligne){
 // printf("\n je suis dans la fonction %s",phrase);
  int i, n;
  int etat_automate=0;

  for(int i=0;i<strlen(phrase);i++){
    switch(etat_automate){
      case 0:
     // printf("\n je suis apres la boucle dans le case 0 %c ",phrase[i]);
      
      if ( detecter_operateur_relationnel(phrase[i]) ) // si > < ira dans Q5 
        etat_automate=5;
      else if(isdigit(phrase[i]))
        etat_automate=2;
      else if(isalpha(phrase[i]))
        etat_automate=1;
      else if(detecter_operateur(phrase[i])) // si > < il n'arrivras pas ici 
        etat_automate=0;
      else if( phrase[i]=='.')
        etat_automate=3;
        else{
        printf("\n  erreur lexical, le caractere  %c est non reconnu ligne %d \n",phrase[i],ligne);
        return 0;
        }
      break;

      case 1:
      //  printf("\n je suis apres la boucle  dans le case 1 %c ",phrase[i]);
        if(detecter_operateur_relationnel(phrase[i]) )
          etat_automate=5;
        else if(isalpha(phrase[i]) || isdigit(phrase[i]))
          etat_automate=1;
         else{
          printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d \n\n ",phrase[i],ligne);
          return 0;
         }
      break;

      case 2:
       if(detecter_operateur_relationnel(phrase[i]) )
         etat_automate=5;
       else if(isdigit(phrase[i]))
         etat_automate= 2;
       else if( phrase[i]=='.')
         etat_automate=3;
         else{
          printf("\n  erreur lexical, le caractere  %c est non reconnu ligne %d  \n\n",phrase[i],ligne);
          return 0;
         }
      break;

      case 3:
      printf("\n je suis dans le case 3 ");
        if(isdigit(phrase[i]))
         etat_automate= 4;
         else{
          printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d \n\n",phrase[i],ligne);
          return 0;
         }
      break;
      case 4:
        if(isdigit(phrase[i]))
         etat_automate= 4;
        else if(detecter_operateur_relationnel(phrase[i]) )
         etat_automate=5;
          else{
           printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d \n",phrase[i],ligne);
           return 0;
          }
      break;

      case 5:
        if(isdigit(phrase[i]))
          etat_automate= 2;
        else if(isalpha(phrase[i]))
          etat_automate=1;
         else{
           printf("\n   erreur lexical, le caractere  %c est non reconnu ligne %d \n",phrase[i],ligne);
           return 0;
          }
      break;
    }
  }

  // return etat_autmates == ( 1 || 2 || 4 || 5 ); 
  switch (etat_automate)
  {
    case 1:
     return 1;
    break;

    case 2:
     return 2;
    break;
  
    case 4:
     return 4;
    break;

    case 5:
     return 5;
    break;

    default:
     return 0;
    break;
  }
}

UL* test_AEF(UL* phrase_decouper1){
  char mot_tmp_test[25]; 
  char succer[3]="#";
  int ligne=0; 
  UL* tmp=phrase_decouper1;
  UL* ptmp=phrase_decouper1;

  int choix; 
  if(phrase_decouper1== NULL){
    printf("ma liste est vide \n");
  }
  else{
    while(tmp != NULL){ // pour parcourir ga3 la liste decouper ta3i 
      ptmp=tmp;  // pour remplir le # 
      strcpy(mot_tmp_test,tmp->Lexeme);
      if(mot_tmp_test==" "){
        return 0;
      }
      else if(strlen(mot_tmp_test) <= 1 && detecter_operateur(mot_tmp_test[0])){
        tmp->code=detecter_code_operateur(mot_tmp_test);
        tmp=tmp->Suivant;
      }
      else {
        choix=AEF_sql(mot_tmp_test,tmp->ligne);
        //printf("\n le choix est d %d ",choix);
        switch (choix)
        {
          /* case 0: 
          tmp->code=detecter_code_operateur(mot_tmp_test); 
          // a remplcé par un detectée et un attribution de code 
          break;*/
         case 1:
          // cherche code identifiant avec switch
          tmp->code=code_idetifiant(mot_tmp_test);
         break;

         case 2:
          tmp->code=NOMBRE_UL;
         break;
         case 4:
          tmp->code=tmp->code=NOMBRE_UL;
         break;

         case 5:
          tmp->code=detecter_code_operateur(mot_tmp_test); // op relationnele 
         break;

         default:
          return 0; 
         break;
       }
       tmp=tmp->Suivant;
      }
    }
   ligne=ptmp->ligne;  // remplissage du # 
  }
 
  phrase_decouper1=Inserer_a_la_fin(phrase_decouper1,succer,999,ligne+1);
  //afficher_Ul(phrase_decouper1);
  return phrase_decouper1; 
}


int main()
{
 char phrase[500];
 UL* phrase_decouper = NULL;
 FILE *file;
 int i=0;
 /* passer le text par un fichier */

 file=fopen("text01.txt","r"); // exemple 1
 //file=fopen("text02.txt","r"); // exemple 2 
 //file=fopen("text03.txt","r"); // exemple 3 

 if(file == NULL )
  printf("\n erreur le fichier ne c'est pas ouvert ");
  else{
   while ( !feof(file) ){
    phrase[i]= fgetc(file);
    i++;
   }
   if(phrase[--i]!='\0') // pour ne pas ajouter /0 deux fois 
   phrase[i]='\0';
  }
 printf("\n\t LECTURE ET AFFICHAGE DU CODE SOURCE LIGNE PAR LIGNE \n \n");
 puts(phrase);
 phrase_decouper=decouper(phrase,phrase_decouper);
 phrase_decouper=test_AEF(phrase_decouper);
 // afficher_Ul(phrase_decouper);
 // afficher_liste(phrase_decouper);
}

/*
1- lire le fichier 
2- decouper en liste chainé eliminer les espaces........ 
3- passer la liste découper a la fonction testAEF 
   qui permet de : 
   - passer les mots dans l'AEF prend la valeur de retour de AEF 
   c'est a dire l'etat AEF 
   le passe dans un switch pour leur donnée un code selon l'etat final  
   -les opérateur ne passe pas dans l'AEF et leur attribu un code 
   - a la fin si tous se passe bien c'est dire ya pas d'erreur elle ajoute
     le caractére # a la fin de la liste
   - retourne al liste decouper avec le code des lexeme et le # a la fin  
*/
