#include<stdio.h>
#include<limits.h>
int main(){
    int arr[100],n,i,first,second;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements of array:\n",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    first=second=INT_MIN;
    for(i=0;i<n;i++){
	    if(arr[i]>first){
		    second=first;
		    first=arr[i];
	    }
	    else if(arr[i]>second && arr[i]!=first){
		    second=arr[i];
	    }
    }
    printf("The second largest element:%d\n",second);
}

