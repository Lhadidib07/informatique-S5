#include<stdio.h>

int main(){
    int t[10]={10,5,9,5,4,7,8,2,6,12};
    int max=0; 
    for(int i=0;i<10;i++){
     if(max < t[i]){
        max=t[i]; 
     } 
    }
      printf("le max est de %d",max); 

    return 0;
}