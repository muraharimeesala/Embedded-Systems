#include<stdio.h>
int main(){
int arr[n],i={10,20,30,40,50};
int n=sizeof(arr)/sizeof(arr[0]);
if(n<2){
printf("Array must have two elements\n");
return 0;
}
int max_sum=arr[0]+arr[i+1];
for(int i=0;i<n-1;i++){
int present_sum=arr[i]+arr[i+1];
if(present_sum>max_sum){
max_sum=present_sum;
}
}
printf("adjacent elements highest sum is=%d",max_sum);
}


