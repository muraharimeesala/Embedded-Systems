#include<stdio.h>

int main(){
    int arr[5]={10,20,30,40,50};
    int i,n=5;
    int start=0,end=n-1;
    
    for(i=0;i<n/2;i++){
        arr[start]=arr[start]+arr[end];
        arr[end]=arr[start]-arr[end];
        arr[start]=arr[start]-arr[end];
        start++;
        end--;
    }
    printf("Array Elements: ");
    for(i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
