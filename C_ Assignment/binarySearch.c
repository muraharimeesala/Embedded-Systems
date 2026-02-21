#include<stdio.h>
int main(){
	int arr[100],n,i,key;
	printf("Enter a array size:");
	scanf("%d",&n);
	printf("Enter %d elments:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	prifsntf("Enter value to search:");
	scanf("%d",&key);
	int low=0;
	int high=n-1;
	while(low<=high){
		int mid=(low+high)/2;
		if(arr[mid]==key){
			printf("%d is found at index %d.\n",key,mid);
			return 0;
		}
		else if(arr[mid]<key){
			low=mid+1;
		}
		else{
			high=mid-1;
		}
	}
	printf("%d is not found in the array.\n",key);
}

