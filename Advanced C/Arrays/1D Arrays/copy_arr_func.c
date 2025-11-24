#include<stdio.h>
int copyArr(int arr[],int des[],int n){
int i;
for(i=0;i<n;i++){
 des[i]=arr[i];   
}
}
int main(){
    int n,i,ind,val,arr[100],des[100];
    printf("Enter size of array:");
    scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
   copyArr(arr,des,n);
    printf("After coping the array:\n");
    for(i=0;i<n;i++){
        printf("%d ",des[i]);
    }
}
