#include<stdio.h>

int main(){
    int arr[10]={10,10,20,30,30,40,50,50,50,60};
    int count=0;
    for(int i=0;i<10;i++){
        for(int j=i+1;j<10;j++){
            if(arr[i]==arr[j]){
                count++;
            }
        }
    }
    printf("The number of duplicate elements are: ");
    printf("%d",count);
    return 0;
}
