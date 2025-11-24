#include<stdio.h>
int main(){
    int n,half,i,temp,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        printf("Element-%d:",i);
        scanf("%d",&arr[i]);
    }
    half=n/2;
        for(i=0;i<half/2;i++){
            temp=arr[i];
            arr[i]=arr[half-1-i];
            arr[half-1-i]=temp;
        }
    printf("Second half array:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
