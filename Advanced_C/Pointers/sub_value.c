#include<stdio.h>
int main(){
int arr[100],n,i;
int *p;
p=&arr[2];
printf("Enter size of array:");
scanf("%d",&n);
printf("Enter %d Elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("Before Subtraction:\n");
printf("Value is:%d\n",*p);
printf("Address of value:%p\n",p);
p=p-1;
printf("After Subtraction:\n");
printf("Value is:%d\n",*p);
printf("Address of value:%p\n",p);
}
