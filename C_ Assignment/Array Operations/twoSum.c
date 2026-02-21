#include<stdio.h>
int main(){
	int n,i,j,arr[100];
	int sum=0;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d", &arr[i]);
	}
	int target;
	printf("Enter Target:");
	scanf("%d",&target);
	i=0;
	j=n-1;
	while(i<=j){
		sum=arr[i]+arr[j];
		if(sum==target){
			printf("Pair=%d+%d=%d\n",arr[i],arr[j],sum);
			break;
		}
		else if(sum>target){
			j--;
		}
		else{
			i++;
		}
	
	}
	printf("Target sum not valid.\n");
}


