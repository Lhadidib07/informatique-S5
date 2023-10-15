#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct pile
{
    char  chaine[100];
    struct  cellule *precedent;    
}pile;


 
//************************************* initialiser pile 
pile initialiser(pile *maPile ){
    maPile=NULL; 
}

//************************************* empiler 
pile empiler(pile *mapile,char *v){
    pile *nv_ellemnt = malloc(sizeof(pile)); 
    nv_ellemnt->chaine=v; 
    nv_ellemnt->precedent=mapile; 
}
// depiler 

// sommet pile 

// afficher pile 




int main(){

   /* if (file != NULL)
    {
        while (fgets(chaine,100, file) != NULL) // On lit le fichier tant qu'on ne reçoit pas d'erreur (NULL)
        { 
           printf("\n %s", chaine); // On affiche la chaîne qu'on vient de lire
           maPile= Empiler(maPile,chaine);
           printf("\n le sommet de la pile %s",sommet_pile(maPile));
        }
 
        fclose(file); */ 
    printf("************************** voila l'affichage de la pile **************************");
   /* for(int i=0;i<5;i++){
        printf("\n %s ",sommet_pile(maPile)); 
        maPile=depiler(maPile);
    }*/
 
}