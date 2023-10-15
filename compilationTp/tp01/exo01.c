#include <stdio.h>
#include <stdlib.h>

int main(){
    printf("le premier entier : ");
    int a;
    scanf("%d",&a);
    printf("2eme entier :");
    int b;
    scanf("%d",&b);
    printf(" \n A - pour fair l'addition ");
    printf(" \n S - pour fair la soustraction ");
    printf(" \n M - pour fair la multiplication ");
    printf(" \n D - pour fair la division ");
    printf(" \n faites votre choix");
    char* choix;
    scanf("%s",choix);
    switch(choix[0]){
    case 'A':
            printf(" \n la somme de %d + %d est de %d",a,b,a+b);
        break;
    case 'S':
            printf(" \n la soustraction de %d - %d est de %d",a,b,a-b);
        break;
    case 'M':
            printf(" \n la multiplication de %d * %d est de %d",a,b,a*b);
        break;
    case 'D':
            printf(" \n la division de %d/%d est de %d",a,b,a/b);
        break;
    default :
        printf("erreur");
        break;
    }


    return 0;
}
