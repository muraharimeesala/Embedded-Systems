#include<stdio.h>
int main(){
        int arr[100],n,i,key,found=1;
        printf("Enter no elements:");
        scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
	printf("Enter value to search:");
	scanf("%d",&key);
	for(i=0;i<n;i++){
		if(arr[i]==key){
			found=0;
			break;
		}
	}
	if(found==0){
		printf("%d Element found at index %d\n",key,i);
	}
	else{
		printf("%d Element no found in the array.\n",key);
	}
}

