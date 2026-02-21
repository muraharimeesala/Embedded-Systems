#include<stdio.h>
int main(){
int num[5],i;
printf("\nEnter array elements:");
for(i=0;i<5;i++){
scanf("%d",&num[i]);
}
for(i=5;i>0;i--){
printf("%d",i,num[i]);
}
}

