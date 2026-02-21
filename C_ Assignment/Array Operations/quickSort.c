#include<stdio.h>
int partition(int arr[],int low,int high){
	int pivot=arr[high];
	int i=low-1,temp,j;
	for(j=low;j<high;j++){
		if(arr[j]<pivot){
			i++;
			temp=arr[i];
			arr[i]=arr[j];
			arr[j]=temp;
		}
	}
	temp=arr[i+1];
	arr[i+1]=arr[high];
	arr[high]=temp;
	return i+1;
}
int quickSort(int arr[],int low,int high){
	if(low<high){
		int pi=partition(arr,low,high);
		quickSort(arr,low,pi-1);
		quickSort(arr,pi+1,high);
	}
}
int main(){
    int n,i,ind,low,high,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
    	    scanf("%d",&arr[i]);
    }
    quickSort(arr,0,n-1);
    printf("Updated Array:\n");
    for(i=0;i<n;i++){
	    printf("%d ",arr[i]);
    }
    printf("\n");
}


