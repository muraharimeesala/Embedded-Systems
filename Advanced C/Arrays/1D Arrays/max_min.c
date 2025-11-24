#include<stdio.h>
int main(){
int num,i,max,min;
printf("Enter array elements:");
scanf("%d",&num);
int arr[100];
for(i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
min=max=arr[0];
for(i=0;i<num;i++){
if(arr[i]>max){
max=arr[i];
}
if(arr[i]<min){
min=arr[i];
}
}
printf("Maximum:%d\n",max);
printf("Minimum:%d\n",min);
}

