#include<stdio.h>
int selectionSort(int arr[],int n){
int temp=0,min;
for(int i=0;i<n;i++){
    min=i;
    for(int j=i+1;j<n;j++){
        if(arr[j]<arr[min]){
            min=j;
        }
    }
    if(min!=i){
        temp=arr[i];
        arr[i]=arr[min];
        arr[min]=temp;
    }
}
}
int main(){
int arr[100],n,i,j;
printf("Enter array size:");
scanf("%d",&n);
printf("Enter %d elements:\n",n);
for(i=0;i<n;i++){
    scanf("%d",&arr[i]);
}
selectionSort(arr,n);
printf("After sorting the array:\n");
for(i=0;i<n;i++){
    printf("%d ",arr[i]);
   }
}
