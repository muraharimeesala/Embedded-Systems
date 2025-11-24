#include<stdio.h>
int main(){
int num;
printf("Enter a number:");
scanf("%d",&num);
//if(num%2==0)
if(num%2!=0)
//printf("%d is Even\n",num);
printf("%d is Odd\n",num);
else
//printf("%d is Not Even\n",num);
printf("%d is Not Odd\n",num);
}
