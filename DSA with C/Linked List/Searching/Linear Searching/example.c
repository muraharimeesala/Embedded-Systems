#include<stdio.h>
int main(){
    int arr[100],i,n,key,found=0;
    printf("Enter size of array:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
    printf("Element-%d:",i);
    scanf("%d",&arr[i]);
    }
    printf("Enter element you want to search:");
    scanf("%d",&key);
    for(i=0;i<n;i++){
        if(arr[i]==key){
            printf("Element %d is found at position %d(index %d).\n",key,i+1,i);
            found=1;
            break;
        }
    }
    if(!found){
        printf("Element %d is found in array.\n",key);
    }
}
