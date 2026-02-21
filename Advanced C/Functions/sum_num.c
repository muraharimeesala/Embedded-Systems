#include<stdio.h>
int sum(int *a,int *b);
int main(){
int a,b;
printf("Enter a and b values:");
scanf("%d%d",&a,&b);
sum(&a,&b);
}
int sum(int *a,int *b){
int sum=0;
sum=*a + *b;
printf("Result is:%d\n",sum);
}

