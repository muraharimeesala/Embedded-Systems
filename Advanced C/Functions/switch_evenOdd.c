#include<stdio.h>
int checkEvenOdd(int num){
switch(num%2){
case 0:
printf("%d is Even\n",num);
break;
case 1:
printf("%d is Odd\n",num);
break;
default:
printf("%d invalid input\n",num);
}
}
int main(){
int num=10;
//printf("Enter a number:");
//scanf("%d",&num);
checkEvenOdd(10);
checkEvenOdd(11);
checkEvenOdd(13);
}

