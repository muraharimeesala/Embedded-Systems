#include<stdio.h>
int findEven(int num){
printf("Even numbers:");
for(int i=1;i<num;i++){
if(i%2==0)
printf("%d\n",i);
}
}
int findOdd(int num){
printf("Odd numbers:");
for(int i=1;i<num;i++){
if(i%2!=0)
printf("%d\n",i);
}
}
int main(){
int num;
printf("Enter of elements:");
scanf("%d",&num);
int (*Evenptr)(int num)=findEven;
int (*Oddptr)(int num)=findOdd;
Evenptr(num);
Oddptr(num);
}

