#include<stdio.h>

int sum(int arr[],int n){
    if(n==0){
        return 0;
    }
    return arr[n-1]+sum(arr,n-1);
}

int main(){
    int arr[5]={10,20,30,40,50};
    printf("Sum of array is: ");
    printf("%d ",sum(arr,5));
}
