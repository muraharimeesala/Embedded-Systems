#include<stdio.h>

int main(){
    int arr[10] = {1,1,2,6,5,5,6,7,7,7};
    int n = 10;
    int i,j,count;

    printf("Unique values are: ");
    for(i=0;i<n;i++){
        count=0;
        for(j=i+1;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
        if(count==1){
            printf("%d ",arr[i]);
        }
    }
    return 0;
}
