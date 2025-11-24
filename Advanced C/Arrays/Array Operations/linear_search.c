#include<stdio.h>
int main(){
int arr[100],n,i,key,found=0;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("Enter element to search:");
scanf("%d",&key);
for(i=0;i<n-1;i++){
if(arr[i]==key){
printf("%d is found at index %d.",key,i);
found=1;
break;
}
}
if(found==0){
printf("%d is not found in the array.",key);
}
}
