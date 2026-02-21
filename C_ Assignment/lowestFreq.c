#include<stdio.h>
int main(){
	int n,arr[100],freq[100],i,j,count,minNum,minFreq=999;
	printf("Enter a arrzy size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		freq[i]=-1;
	}
	for(i=0;i<n;i++){
		count=1;
		for(j=i+1;j<n;j++){
			if(arr[i]==arr[j]){
				count++;
				freq[j]=0;
			}
		}
		if(freq[i]!=0){
			freq[i]=count;
			if(count<minFreq){
				minFreq=count;
				minNum=arr[i];
			}
		}
	}
	printf("Number with highest frequency: %d occurrs %d times.\n",minNum,minFreq);
}
