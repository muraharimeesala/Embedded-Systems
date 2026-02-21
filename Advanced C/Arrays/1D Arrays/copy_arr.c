#include<stdio.h>
#include<limits.h>
int main(){
    int src[100],des[100],n,i,count=0;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements of array:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&src[i]);
    }
    for(i=0;i<n;i++){
        des[i]=src[i];
    }
    printf("After coping the array:");
    for(i=0;i<n;i++){
        printf("%d ",des[i]);
    }
}
