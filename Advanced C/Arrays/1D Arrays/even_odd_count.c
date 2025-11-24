#include<stdio.h>
int main(){
	int arr[100],n,i,evencount=0,oddcount=0;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	for(i=0;i<n;i++){
		if(arr[i]%2==0){
			evencount++;
		}
		else{
			oddcount++;
		}
	}
	printf("Even numbers are:%d\n",evencount);
	printf("Odd numbers are:%d\n",oddcount);
}
			

