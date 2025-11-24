#include<stdio.h>
int main(){
    int a=10;
    int *ptr;
    ptr=&a;
    printf("%d\n",a);
    printf("%p\n",&a);
    printf("%d\n",*ptr);
    printf("%p\n",ptr);
    printf("%d\n",*(&a));
    printf("%p\n",&ptr);
}
