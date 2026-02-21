#include<stdio.h>
int main(){
int num,n,cube,d,sum=0;
printf("Armstrong numbers are:");
scanf("%d",&num);
for(num=50;num<=500;num++){
n=num;
sum=0;
while(n>0)
{
d=n%10;
n/=10;
cube=d*d*d;
sum=sum+cube;
}
if(num==sum)
printf("%d\n",num);
}
}
