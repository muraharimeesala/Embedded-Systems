#include<stdio.h>

int main() {
    int arr[10]={1,1,2,2,2,3,4,4,5,6};
    int freq[10]={0};
    int i;
    int n=10;
    for(i=0;i<n;i++){
        freq[arr[i]]++;
    }
    printf("Unique values are: ");
    for(i=0;i<n;i++){
        if(freq[i]==1){
            printf("%d ",i);
        }
    }
    return 0;
}
