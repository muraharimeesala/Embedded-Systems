#include<stdio.h>
int main(){
int arr[100],n,i;
int *ptr;
ptr=arr;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
for(i=0;i<n;i++){
printf("Element:%d Value is:%d Address is:%p\n",i,*(ptr+i),(ptr+i));
}
}
