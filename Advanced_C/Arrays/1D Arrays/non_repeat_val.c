#include<stdio.h>
int main(){
	int arr[100],n,i,j,count=0;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Non repeated elements:\n");
	for(i=0;i<n;i++){
		count=0;
		for(j=0;j<n;j++){
			if(arr[i]==arr[j]&&i!=j){
				count++;
				break;
			}
		}
		if(count==0){
			printf("%d\n",arr[i]);
		}
	}
}
