#include<stdio.h>
int main(){
int i,num,fact=1;
printf("Enter a number:");
scanf("%d",&num);
if(num<0){
printf("We can't find factorials for negative numbers:\n");
}
else{
int i=1;
while(i<=num)
fact*=i;
i++;
printf("factorial for %d=%d",num,fact);
}
}
