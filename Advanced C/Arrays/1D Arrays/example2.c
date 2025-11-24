#include<stdio.h>
int main(){
int num[5],i;
printf("Enter elements of the array:");
for(i=0;i<5;i++){
scanf("%d",&num[i]);
}
for(i=0;i<5;i++){
printf("array elements at index %d is:%d\n",i,&num[i]);
}
}
