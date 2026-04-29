#include<stdio.h>

int main()
{
    int arr[10]={10,10,20,30,10,50,30,30,40,50};
    int count=0;
    int i=0,j=1;
    for(i=0;i<9;i++){
        for(j=i+1;j<10;j++){
            if(arr[i]>arr[j]){
                int temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<10;i++)
    {
        if(arr[i]==arr[i+1])
        {
            count++;
        }
    }
    printf("The number of duplicate elements are: ");
    printf("%d",count);
    return 0;
}
