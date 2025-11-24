#include<stdio.h>
int main(){
int num,i;
unsigned long fact=1;
printf("Enter a number:");
scanf("%d",&num);
if(num<0){
printf("We can't find factorials for negative numbers:\n");
}else{
for(i=1;i<=num;i++)
fact*=i;
{
printf("factorials for %d=%lu\n",num,fact);
}
}
}
