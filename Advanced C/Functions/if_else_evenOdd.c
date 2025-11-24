#include<stdio.h>
int EvenOdd(int num){
if(num%2==0){
printf("%d is Even\n",num);
}
else
printf("%d is Odd\n",num);
}
int main(){
int num;
//printf("Enter a number:");
//scanf("%d",&num);
EvenOdd(10);
EvenOdd(11);
EvenOdd(12);
EvenOdd(13);
}
