#include<stdio.h>
int main(){
int num;
int arr[100];
int *ptr=arr;
printf("Enter no of elements:");
scanf("%d",&num);
for(int i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
for(int i=0;i<num;i++){
printf("%d\n",ptr[i]);
printf("%p\n",&ptr[i]);
}
}
