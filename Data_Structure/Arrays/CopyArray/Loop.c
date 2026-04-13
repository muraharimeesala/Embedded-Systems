#include<stdio.h>

int main(){
    int arr1[5]={10,20,30,40,50};
    int arr2[5];
    int i;
    for(i=0;i<5;i++){
        arr2[i]=arr1[i];
    }
    printf("The copied array is: ");
    for(i=0;i<5;i++){
        printf("%d ",arr2[i]);
    }
    return 0;
}
