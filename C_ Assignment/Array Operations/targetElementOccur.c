#include<stdio.h>
int main(){
    int n,i,target,count=0,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
	    scanf("%d",&arr[i]);
    }
    printf("Enter target value:");
    scanf("%d",&target);
    for(i=0;i<n;i++){
	    if(arr[i]==target){
		    count++;
	    }
    }
    printf("%d Element occurs %d times.\n",target,count);
}



