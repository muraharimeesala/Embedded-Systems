#include<stdio.h>
int main(){
int num,i,j,temp,swapped;
printf("Enter array elements:");
scanf("%d",&num);
int arr[100];
for(i=0;i<num;i++){
printf("Element-%d:",i);
scanf("%d",&arr[i]);
}
for(i=0;i<num-1;i++){
swapped=0;
for(j=0;j<num-1-i;j++){
if(arr[j]>arr[j+1]){
temp=arr[j];
arr[j]=arr[j+1];
arr[j+1]=temp;
swapped=1;
}
}
if(swapped==0)
break;
}
printf("After ascending the elements:\n");
for(i=0;i<num;i++){
printf("%d",arr[i]);
}
printf("\n");
}
