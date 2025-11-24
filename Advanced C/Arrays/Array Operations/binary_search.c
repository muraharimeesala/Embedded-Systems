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
int high=n-1;
int low=0;
while(low<=high){
int mid=(low+high)/2;
if(arr[mid]==key){
   printf("Element %d found at index %d.\n",key,mid);
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
    printf("%d is not found in the array.\n",key);
}
}

