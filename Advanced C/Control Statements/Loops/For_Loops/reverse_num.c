#include<stdio.h>
int main(){
int num,rev=0;
printf("Enter a number:");
scanf("%d",&num);
for(; num!=0;num/=10){
rev=rev*10+num%10;
}
printf("Reverse number is:%d\n",rev);
}
