#include<stdio.h>
int main(){
        int n,i,j,arr[100];
        printf("Enter size of array:");
        scanf("%d",&n);
        printf("Enter %d elements array:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
	int sorted=1;   //assume sorted
	for(i=0;i<n;i++){
		if(arr[i]>arr[i+1]){
			sorted=0;
			break;
		}
	}
	if(sorted){
		printf("Array is sorted  form.\n");
	}
	else{
		printf("Array is not sorted form.\n");
	}
}

