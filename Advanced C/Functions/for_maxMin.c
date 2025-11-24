#include<stdio.h>
int checkMaxMin(int arr[],int num){
int max=arr[0];
for(int i=1;i<num;i++){
if(arr[i]>max){
max=arr[i];
}
return max;
}
int checkMaxMin(int arr[],int num){
int min=arr[0];
for(int i=0;i<num;i++){
if(arr[i]<min){
min=arr[i];
}
return min;
}
}
int main(){
int arr[num],num;
printf("Enter a elements of array:");
scanf("%d",&num);
printf("Enter %d elements:\n",num);
for(int i=0;i<num;i++){
printf("Elements-%d: ",i+1);
scanf("%d",&arr[i]);
}
int max=checkMaxMin(arr,num);
int min=checkMaxMin(arr,num);
printf("Maximum:%d\n",max);
printf("Minimum:%d\n",min);
}
}
