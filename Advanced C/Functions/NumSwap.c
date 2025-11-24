#include<stdio.h>
int Swap(int *a,int *b);
int main(){
int a=10,b=12;
Swap(&a,&b);
printf("After Swapping:a=%d\n b=%d\n",a,b);
}
int Swap(int *a,int *b){
int temp;
temp=*a;
*a=*b;
*b=temp;
}

