#include<stdio.h>
int main(){
    int n,i,j,arr[100];
    int swapped,temp;
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
    	    scanf("%d",&arr[i]);
    }
    for(i=0;i<n-1;i++){
	    swapped=0;
	    for(j=0;j<n-1-i;j++){
		    if(arr[j]<arr[j+1]){
			    temp=arr[j];
			    arr[j]=arr[j+1];
			    arr[j+1]=temp;
			    swapped=1;
		    }
	    }
	    if(swapped==0){
		    break;
	    }
    }
    printf("Updated Array:\n");
    for(i=0;i<n;i++){
	    printf("%d",arr[i]);
    }
    printf("\n");
}
