#include<stdio.h>
int main(){
int a=10;
int *ptr;
ptr=&a;
printf("Value at that address:%d\n",*ptr);
printf("Before addition:%p\n",ptr);
ptr+=1;
printf("After addition of 1:%p\n",ptr);
printf("Before subtraction:%p\n",ptr);
ptr-=1;
printf("After subtraction of 1:%p\n",ptr);
}
