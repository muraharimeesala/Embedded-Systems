#include<stdio.h>
int main(){
int a=10;
int *ptr=&a;
float b=2.2;
float *ptr1=&b;
char c='M';
char *ptr2=&c;
printf("integer: %d\nfloat value: %f\ncharacter: %c\n",*ptr,*ptr1,*ptr2);
}
