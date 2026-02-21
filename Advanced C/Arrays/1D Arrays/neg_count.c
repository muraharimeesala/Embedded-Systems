#include<stdio.h>
#include<limits.h>
int main(){
    int arr[100],n,i,count=0;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements of array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        if(arr[i]<0){
            count++;
        }
    }
    printf("Total no of negative numbers in the array:%d",count);
}
