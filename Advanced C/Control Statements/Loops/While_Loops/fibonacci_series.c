#include<stdio.h>
int main(){
int num,a=0,b=1,next,i=0;
printf("Enter a fibonacci numbers:");
scanf("%d",&num);
printf("fibonacci series:%d\n",num);
while(i<num){
printf(" %d",a);
next=a+b;
a=b;
b=next;
i++;
}
printf("\n");
}
