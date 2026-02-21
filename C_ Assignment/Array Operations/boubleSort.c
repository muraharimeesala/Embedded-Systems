#include<stdio.h>
int main(){
    int n,i,j,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
	    scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
	    for(j=0;j<n-1;j++){
		    if(arr[j]>arr[j+1]){
			    int temp=arr[j];
			    arr[j]=arr[j+1];
			    arr[j+1]=temp;
		    }
	    }
    }
    printf("Updated Array:");
    for(i=0;i<n;i++){
	    printf("%d",arr[i]);
    }
}
    

