#include<stdio.h>

int main(){
    int arr1[5] = {10,20,30,40,50};
    int arr2[5];

    int *p1 = arr1;
    int *p2 = arr2;

    for(int i=0; i<5; i++){
        *(p2+i) = *(p1+i);
    }
    printf("The copied array is: ");
    for(int i=0; i<5; i++){
        printf("%d ",*(p2+i));
    }
    return 0;
}
