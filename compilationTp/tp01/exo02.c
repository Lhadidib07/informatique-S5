#include<stdio.h>
void echange(int *a,int  *b){
  int c; 
   c=*a;
  *a=*b; 
  *b=c; 
}
int main(){
    int a,b; 
    printf(" entrez a : "); 
    scanf("%d",&a);
    printf("entre b : ");
    scanf("%d",&b);     
    echange(&a,&b); 
    printf(" a = %d , b = %d ", a,b);  
    return 0;
}