#include<stdio.h>
int main(){
int arr[100],n,i,found=0,key;
int low,high;
printf("Enter size of array:");
scanf("%d",&n);
printf("Enter %d elements of array:\n",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
printf("Enter element to search:");
scanf("%d",&key);
low=0;
high=n-1;
while(low<=high){
int mid=(low+high)/2;
if(arr[mid]==key){
printf("Element %d is found at index %d.\n",key,mid);
found=1;
break;
}
else if(arr[mid]<key){
low=mid+1;
}
else{
high=mid-1;
}
}
if(!found){
printf("Element %d is not found in array.\n",key);
}
}
