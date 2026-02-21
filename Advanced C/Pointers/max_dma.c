#include<stdio.h>
#include<stdlib.h>
int main(){
	int n,i;
	int *arr;
	int max;
	printf("Enter array size:");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	if(arr==NULL){
		printf("Failed to allocate memory.\n");
		return 1;
	}
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	max=*arr;
	for(i=0;i<n;i++){
		if(*(arr+i)>max){
			max=*(arr+i);
		}
	}
	printf("Largest value:%d\n",max);
	free(arr);

}

