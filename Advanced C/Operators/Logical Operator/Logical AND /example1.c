#include<stdio.h>
int main(){
int a,b,x;
printf("Enter two numbers:");
scanf("%d%d",&a,&b);
//x=(a>b)&&(b>=a);
//x=(a==b)&&(b<=a);
x=a&&b;
printf("%d",x);
}

