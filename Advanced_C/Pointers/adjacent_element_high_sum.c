#include<stdio.h>
int main(){
int arr[]={10,20,30,40,50};
int n=arr[]/sizeof(arr[0]);
if(arr<2){
printf("Array must have two elements\n");
return 0;
}
max_sum=arr[0]+arr[i+1];
for(int i=0;i<n-1;i++){
present_sum=arr[i]+arr[i+1];
if(present_sum>max_sum){
max_sum=present_sum;
}
}
printf("Sum=%d",max_sum);
}


