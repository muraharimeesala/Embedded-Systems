#include<stdio.h>
int ascend_order(int arr[],int num){
for(int i=0;i<num-1;i++){
for(int j=0;j<num-1-i;j++){
if(arr[j]>arr[j+1]){
int temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
}
}
}
}
int main(){
int num,i;
int arr[100];
printf("Enter no of elements:");
scanf("%d",&num);
for(i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
ascend_order(arr,num);
printf("After sort the elements:");
for(i=0;i<num;i++){
printf("%d\n",arr[i]);
}
}
