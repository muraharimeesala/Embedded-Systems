#include<stdio.h>
int adjacentSum(int arr[],int n){
int i,max_sum,present_sum;
max_sum=arr[0]+arr[1];       // Initialize with the sum of first adjacent pair
for(i=0;i<n-1;i++){
present_sum=arr[i]+arr[i+1];
if(present_sum>max_sum){
    max_sum=present_sum;
}
}
return max_sum;
}
int main(){
int arr[100],n,i,max_sum;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
max_sum=adjacentSum(arr,n);
printf("Sum of adjacent elements:%d\n",max_sum);
}
