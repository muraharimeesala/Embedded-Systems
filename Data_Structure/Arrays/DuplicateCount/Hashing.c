#include<stdio.h>

#define MAX 10
int main(){
    int arr[10]={10,20,10,50,50,30,30,30,10,20};
    int freq[MAX]={0};
    int count=0;
    for(int i=0;i<10;i++){
        if(arr[i]>=0 && arr[i]<MAX){
            freq[arr[i]]++;
        }
    }
    for(int i=0;i<MAX;i++){
        if(freq[i]>1){
            count++;
        }
    }
    printf("The number of duplicates are: ");
    printf("%d",count);
    return 0;
    }
