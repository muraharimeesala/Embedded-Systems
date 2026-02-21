#include<stdio.h>
int main(){
    int n,i,j,min,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
    	    scanf("%d",&arr[i]);
    }
    // Find min value and compare with first element
    for(i=0;i<n-1;i++){
	    min=i;
	    for(j=i+1;j<n;j++){
		    if(arr[j]<arr[min]){
			    min=j;
		    }
	    }
	    int temp=arr[i];
	    arr[i]=arr[min];
	    arr[min]=temp;
    }
    printf("Updated Array:\n");
    for(i=0;i<n;i++){
	    printf("%d ",arr[i]);
    }
    printf("\n");
}

