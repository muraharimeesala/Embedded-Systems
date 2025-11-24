#include<stdio.h>
int insertionSort(int arr[],int n){
int i,j,key;
for(i=0;i<n;i++){
    key=arr[i];
    j=i-1;
    while(j>=0&&arr[j]>key){
        arr[j+1]=arr[j];
        j--;
    }
    arr[j+1]=key;
}
}
int main(){
int arr[100],n,i,j,key;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
insertionSort(arr,n);
printf("After sorting the array:\n");
for(i=0;i<n;i++){
    printf("%d ",arr[i]);
   }
}
