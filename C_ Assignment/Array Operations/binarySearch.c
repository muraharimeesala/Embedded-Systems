#include<stdio.h>
int main(){
        int arr[100],n,i,key,found=0;
        printf("Enter no elements:");
        scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
	printf("Enter value to search:");
	scanf("%d",&key);
	int low=0,high=n-1;
	int mid;
	while(low<=high){
		mid=(low+high)/2;
		if(arr[mid]==key){
			found=1;
			break;
		}
		else if(arr[mid]<key){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	if(found==1){
		printf("%d Element found at index %d.\n",key,mid);
	}
	else{
		printf("%d Element not found in the array.\n",key);
	}
}

