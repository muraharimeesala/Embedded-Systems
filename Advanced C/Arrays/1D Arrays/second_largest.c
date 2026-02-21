#include<stdio.h>
#include<limits.h>
int main(){
    int arr[100],n,i,first,second;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements of array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    first=second=INT_MIN;
    for(i=0;i<n;i++){
    if(arr[i]>first){
        second=first;
        first=arr[i];
    }
    else if(arr[i]>second&&arr[i]!=first){
        second=arr[i];
    }
    }
    if(second!=INT_MIN){
        printf("%d is the second largest element.\n",second);
    }
    else{
        printf("There is no second largest element.\n");
    }
}
