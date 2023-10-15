#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct cellule
{
    char valeur[100];
    struct  cellule *next;
}Element;

typedef struct pile{
    Element *sommet;
}Pile;

Pile* Initialiser(Pile* p){
    p=malloc(sizeof(Pile));
    p->sommet=NULL;
    return p;
}


Pile* Empiler(Pile* p,char *v ){
    Element* nv_element = malloc(sizeof(Element));
    strcpy(nv_element->valeur,v);
    nv_element->next=p->sommet;
    p->sommet = nv_element;
    return p;
}

Pile *depiler(Pile* p ){
    if(p->sommet == NULL){
        return p;
    }
    Element* e;
    e=p->sommet;
    p->sommet=p->sommet->next;
    free(e);
    return p;
}

char* sommet_pile(Pile* p){
 if(p->sommet == NULL )
  return " pile vide ";
  else
  return p->sommet->valeur ;
}

void afficher(Pile* p){
    if(p->sommet != NULL){
        Element* tmp = malloc(sizeof(Element));
        tmp=p->sommet;
        while (tmp!=NULL)
        {
            printf("\n %s ",tmp->valeur);
            tmp=tmp->next;
        }
    }
    else
    printf("\n pile vide desolé ");
}

int main(){
    FILE* file; 
    Pile* maPile;
    maPile=Initialiser(maPile);
    char chaine[100]={0};
    char c;
    file =fopen("etudiant.txt","r");
    if (file != NULL)
    {
        while (fgets(chaine,100, file) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        {
           maPile= Empiler(maPile,chaine);
        }

        fclose(file);
    }
    printf("\n ************************** voila l'affichage de la pile ************************** \n ");
    afficher(maPile);
 

}


