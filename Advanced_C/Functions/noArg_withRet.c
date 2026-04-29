#include<stdio.h>
int sum(void);
int main(){
int s;
s=sum();
printf("Sum=%d\n",s);
}
int sum(){
int a=5,b=7,sum=0;
sum=a+b;
return sum;
}

