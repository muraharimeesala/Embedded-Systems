#include<stdio.h>
int main(){
	int arr[100],n,i,value,pos;
	printf("Enter no of elements:");
	scanf("%d",&n);
	printf("Enter %d elenents:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	printf("Enter value to insert at position:");
	scanf("%d",&value);
	printf("Enter position to insert value(0 to %d):",n+1);
	scanf("%d",&pos);
	if(pos<0 || pos>n+1){
		printf("Invalid position.\n");
	}
	for(i=n-1;i>=pos-1;i--){
		arr[i+1]=arr[i];
	}
	arr[pos-1]=value;
	n++;
	printf("After inserting the element at position:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
	printf("\n");
}
