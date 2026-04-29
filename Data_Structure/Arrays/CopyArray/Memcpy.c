#include<stdio.h>
#include<string.h>

int main(){
    int arr1[5]={10,20,30,40,50};
    int arr2[5];
    memcpy(arr2,arr1,sizeof(arr1));
    printf("The copied array is: ");
    for(int i=0;i<5;i++){
        printf("%d ",arr2[i]);
    }
    return 0;
}
