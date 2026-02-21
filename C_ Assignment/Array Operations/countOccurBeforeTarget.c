#include<stdio.h>
#include<stdlib.h>
int main(){
    int n,i,pos=-1,val,beforeCount=0,target,arr[100];
    printf("Enter size of array:");
    scanf("%d",&n);
    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++){
    	    scanf("%d",&arr[i]);
    }
    printf("Enter target value:");
    scanf("%d",&target);
    printf("Enter value to find:");
    scanf("%d",&val);
    for(i=0;i<n;i++){
	    if(arr[i]==target){
		    pos=i;
		    break;
	    }
    }
    if(pos==-1){
	    printf("Targeted value not found.\n");
	    exit(1);
    }
    for(i=0;i<pos;i++){
	    if(arr[i]==val){
		    beforeCount++;
	    }
    }
    printf("Count of %d before target value %d: %d\n",val,target,beforeCount);
}



