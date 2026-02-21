#include<stdio.h>
int main(){
int year;
printf("Enter year:");
scanf("%d",&year);
if(year%100!=0)
{
if(year%4==0)
printf("Its leap year\n");
else
printf("Its not leap year\n");
}
else
{
if(year%400==0)
printf("Its leap year\n");
else
printf("Its not leap year\n");
}
}
