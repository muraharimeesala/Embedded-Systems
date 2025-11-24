#include<stdio.h>
int main(){
    int arr[100],n,i,pos,val;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter value to insert:");
    scanf("%d",&val);
    printf("Enter position to insert:");
    scanf("%d",&pos);
    for(i=0;i>pos;i++){
        arr[i]=arr[pos];
        n--;
    }
    arr[pos]=val;
    printf("Array after insertion:");
    for(i=0;i<n;i++){
        printf("%d \n",arr[i]);
    }
}s
