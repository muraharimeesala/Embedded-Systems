#include<stdio.h>
int main(){
    int arr[100],n,temp=0,i,j;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements of array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n-1-i;j++){
            if(arr[j]>arr[j+1]){
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    }
printf("After Bouble sort:");
for(i=0;i<n;i++){
    printf("%d ",arr[i]);
    }
} 
