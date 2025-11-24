#include<stdio.h>
int binarysearch(int arr[],int n,int key){
int high=n-1;
int low=0;
while(low<=high){
int mid=(low+high)/2;
if(arr[mid]==key){
    return mid;             //Element found
}
else if(arr[mid]<key){      
    low=mid+1;             //Search right half
}
else{
high=mid-1;               //Search left half
}
}
return -1;               // Not found
}
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
int result=binarysearch(arr,n,key);
if(result){
printf("Element %d found at index %d\n",key,result);
}
else{
printf("Element %d not found in the array\n",key);
}
}
