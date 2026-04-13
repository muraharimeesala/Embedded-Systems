#include<stdio.h>
int checkEven(int num){
printf("Even numbers:\n");
for(int i=2;i<=num;i+=2){
printf("%d\n",i);
}
printf("\n");
}
int checkOdd(int num){
printf("Odd numbers:\n");
for(int i=1;i<=num;i+=2){
printf("%d\n",i);
}
printf("\n");
}
int main(){
int num;
printf("Enter a numbers limit:");
scanf("%d",&num);
checkEven(num);
checkEven(20);
checkOdd(num);
checkOdd(30);
}


