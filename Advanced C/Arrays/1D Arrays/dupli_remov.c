#include<stdio.h>
int main(){
int arr[100],n,i,k,j;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements of array:",n);
for(i=0;i<n;i++){
scanf("%d",&arr[i]);
}
for(i=0;i<n;i++){
for(j=i+1;j<n;j++){
if(arr[i]==arr[j]){
for(k=j;k<n-1;k++){           // Shift the elements 
arr[k]=arr[k+1];
}
n--;                        // Decreasing the array size
j--;                       // Stay at same index to re-check
}
}
}
printf("After removing duplicates:");
for(i=0;i<n;i++){
printf("%d ",arr[i]);
}
}
