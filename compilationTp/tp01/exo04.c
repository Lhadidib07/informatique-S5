#include<stdio.h>
#include<string.h>
void afficheChaine(char* chaine){
    int longeur=strlen(chaine);
    for(int i=0;i<longeur;i++){
       printf(" %c  " ,chaine[i]);
    }
}
int voyelle (char *chaine){
    int nbr=0;
    int longeur=strlen(chaine);
    for(int i1=0;i1<longeur;i1++){
       if(chaine[i1] == 'a' || chaine[i1] == 'e' || chaine[i1] =='i' || chaine[i1] =='o' ||  chaine[i1] =='y'){
        nbr++; 
       }
    }
    return nbr; 
}

int main(){
    char* chaine="salam";
    afficheChaine(chaine);
    printf(" \n le nombre de voyelle est de %d",voyelle(chaine));

    return 0;
}