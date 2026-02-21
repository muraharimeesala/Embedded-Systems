#include<stdio.h>
int main(){
        int arr[100],n,i,pos;
        printf("Enter no elements:");
        scanf("%d",&n);
        printf("Enter %d elements:\n",n);
        for(i=0;i<n;i++){
                scanf("%d",&arr[i]);
        }
	printf("Enter position to delete(1 to %d):",n);
	scanf("%d",&pos);
	if(pos<1 || pos>n-1){
		printf("Invalid position.\n");
	}
	for(i=pos;i<n-1;i++){
		arr[i]=arr[i+1];
	}
	n--;
	printf("Updated Array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
	
