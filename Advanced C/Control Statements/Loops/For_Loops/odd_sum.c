#include<stdio.h>
int main(){
int num,i,sum=0;
printf("Enter a number:");
scanf("%d",&num);
printf("\n The odd numbers are:");
for(i=1;i<=num;i++){
printf("%d\n",2*i-1);
sum+=2*i-1;
}
printf("The sum of odd natural numbers up to %d is:%d\n",num,sum);
}


