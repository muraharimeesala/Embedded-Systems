#include<stdio.h>
int main(){
    int n,i,ind,val,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter index to replace(0 to %d):",n-1);
    scanf("%d",&ind);
    printf("Enter value to replace:");
    scanf("%d",&val);
    printf("After modify the array:\n");
    for(i=0;i<n;i++){
        arr[ind]=val;
        printf("%d ",arr[i]);
    }
}
