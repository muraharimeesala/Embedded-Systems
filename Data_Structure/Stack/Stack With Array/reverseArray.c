#include<stdio.h>
int stack[1024];
int top=-1;
void push(int x){
	stack[++top]=x;
}
int pop(){
	return stack[top--];
}
int main(){
	int n,arr[100],i;
	printf("Enter size of array:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		push(arr[i]);
	}
	for(i=0;i<n;i++){
		arr[i]=pop();      // Returns the top of the value to array
	}
	printf("Reversed Array:\n");
	for(i=0;i<n;i++){
		printf("%d ",arr[i]);
	}
}
