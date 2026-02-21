#include<stdio.h>
int main(){
int num,sum=0;
printf("The first natural numbers are:");
scanf("%d",&num);
for(num=0;num<=10;num++)
sum+=num;
printf("%d",sum);
}

