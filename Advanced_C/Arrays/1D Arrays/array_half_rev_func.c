#include<stdio.h>
int hlafRev(int arr[],int n){
int half,temp,i;
half=n/2;
        for(i=0;i<half/2;i++){
            temp=arr[i];
            arr[i]=arr[half-1-i];
            arr[half-1-i]=temp;
        }
}
int main(){
    int n,half,i,temp,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    hlafRev(arr,n);
    printf("Second half array:\n");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
}
