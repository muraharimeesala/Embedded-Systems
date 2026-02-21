#include<stdio.h>
int main(){
int num,revrse=0;
printf("Enter a number:");
scanf("%d",&num);
int original=num;
while(num!=0){
int digit=num%10;
revrse=revrse*10+digit;
num/=10;
}
printf("The reverse %d of %d\n is",original,revrse);
}

