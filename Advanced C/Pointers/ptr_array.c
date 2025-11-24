#include<stdio.h>
int main(){
int arr[100],n,i;
int *ptr=arr;
int (*q)[n]=&arr;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("Array base address:%p\n",arr);
printf("Pointer to int(ptr):%p\n",ptr);
printf("Pointer to array(q):%p\n",q);
printf("Accessing elements using p(int *):\n");
for(i=0;i<n;i++){
printf("ptr[%d] Value:%d Address:%p\n",i,ptr[i],&ptr[i]);
}printf("Accessing elements using p(*)[%d]:\n",n);
for(i=0;i<n;i++){
printf("(*q)[%d] Value:%d Address:%p\n",i,(*q)[i],&(*q)[i]);
}
printf("Pointer arithmetic difference:\n");
printf("ptr+1=%p(Moved by size of int)\n",(ptr+1));
printf("q+1=%p(Moved by size of entire array of %d ints)\n",(q+1),n);
}



