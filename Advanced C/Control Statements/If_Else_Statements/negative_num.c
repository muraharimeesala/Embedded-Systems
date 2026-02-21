#include<stdio.h>
int main(){
int num;
printf("Enter a number:");
scanf("%d",&num);
if(num<0){
printf("%d is Negative number.\n");
num=-num;
}
printf("The value of num is:%d\n",num);
}
