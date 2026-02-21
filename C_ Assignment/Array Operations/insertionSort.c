#include<stdio.h>
int main(){
    int n,i,j,key,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
    	    scanf("%d",&arr[i]);
    }
    for(i=1;i<n;i++){
	    key=arr[i];
	    for(j=i-1;j>=0 && arr[j]>key;j--){
		    arr[j+1]=arr[j];
	    }
	    arr[j+1]=key;
    }
    printf("Updated Array:\n");
    for(i=0;i<n;i++){
	    printf("%d ",arr[i]);
    }
    printf("\n");
}

