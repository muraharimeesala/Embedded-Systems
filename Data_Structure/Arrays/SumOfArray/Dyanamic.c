#include<stdio.h>
#include<stdlib.h>

int main()
{
    int arr[5]={10,20,30,40,50};
    int n=5,i,sum=0;
    int *ptr=arr;
    ptr=(int*)malloc(n*sizeof(int));
    for(i=0;i<n;i++)
    {
        sum=sum+arr[i];
    }
    printf("Sum of array is: ");
    printf("%d ",sum);
    return 0;
}
