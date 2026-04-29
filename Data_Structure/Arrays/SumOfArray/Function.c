#include<stdio.h>
int sum(int arr[],int n){
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main(){
    int arr[5]={10,20,30,40,50};
    printf("Sum of array is : %d ",sum(arr,5));
    return 0;
}
