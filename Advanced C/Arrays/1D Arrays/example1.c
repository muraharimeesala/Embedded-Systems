#include<stdio.h>
int main(){
int num[10],i;
printf("Enter array Elements:");
for(i=0;i<10;i++){
scanf("%d",&num[i]);
}
//for(i=0;i<10;i++){
for(i=9;i>=0;i--){
printf("The array elements at index %d is:%d\n",i,num[i]);
}
}
