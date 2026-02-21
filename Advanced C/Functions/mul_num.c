#include<stdio.h>
int mul(int *a,int *b);
int main(){
int a,b;
printf("Enter a and b values:");
scanf("%d%d",&a,&b);
mul(&a,&b);
mul(&a,&b);
mul(&a,&b);
}
int mul(int *a,int *b){
int mul=0;
mul=*a * *b;
printf("Result is:%d\n",mul);
}

