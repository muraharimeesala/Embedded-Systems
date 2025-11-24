#include<stdio.h>
int linearSearch(int arr[],int n,int key){
    for(int i=0;i<n;i++){
        if(arr[i]==key){
            return i;     //Found
        }
    }
    return -1;            //Not Found
}
int main(){
    int arr[100],n,i,key,found;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter element to search:");
    scanf("%d",&key);
    int result=linearSearch(arr,n,key);
    if(result){
        printf("%d is found at %d index.",key,result);
    }
    else{
        printf("%d is not found in the array.",key);
    }
}

