#include<stdio.h>
int main(){
int a[]={10,20,30,40,50};
int *ptr;
ptr=a;
printf("Before increment:%p\n Pointing to:%d\n",(void*)ptr,*ptr);
ptr++;
printf("After increment:%p\n Pointing to:%d\n",(void*)ptr,*ptr);
printf("Before increment:%p\n Pointing to:%d\n",(void*)ptr,*ptr);
++ptr;
printf("After increment:%p\n Pointing to:%d\n",(void*)ptr,*ptr);
printf("Before decrement:%p\n Pointing to:%d\n",(void*)ptr,*ptr);
ptr--;
printf("After decrement:%p\n Pointing to:%d\n",(void*)ptr,*ptr);
printf("Before decrement:%p\n Pointing to:%d\n",(void*)ptr,*ptr);
--ptr;
printf("After decrement:%p\n Pointing to:%d\n",(void*)ptr,*ptr);
}
