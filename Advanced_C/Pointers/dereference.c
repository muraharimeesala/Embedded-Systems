#include<stdio.h>
int main(){
int a=12;
int *ptr;
ptr=&a;
printf("Value of a:%d\n",a);
printf("Address of a:%p\n",&a);
printf("Address of pointer:%p\n",ptr);
printf("Value pointing by ptr(*ptr):%d\n",*ptr);
*ptr=100;
printf("New value of a:%d\n",*ptr);
printf("Address of pointer:%d\n",*ptr);
printf("Value pointing by ptr(*ptr):%p\n",ptr);
}

