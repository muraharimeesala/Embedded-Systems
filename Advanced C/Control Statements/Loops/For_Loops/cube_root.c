#include<stdio.h>
int main(){
int i,num,cube;
printf("Enter the number:");
scanf("%d",&num);
for(i=1;i<=num;i++){
cube=i*i*i;
printf("Cube root of %d is:%d\n",i,cube);
}
}
