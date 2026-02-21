#include<stdio.h>
int main(){
int num;
printf("Enter a number:");
scanf("%d",&num);
if(num>0)
printf("%d is Positive\n");
else if(num<0)
printf("%d is Negative\n");
else
printf("%d is Zero\n");
}
