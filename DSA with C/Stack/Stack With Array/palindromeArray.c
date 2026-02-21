#include<stdio.h>
int stack[100];
int top=-1;
void push(int x){
	stack[++top]=x;
}
int pop(){
	return stack[top--];
}
int main(){
	int arr[100],n,i;
	printf("Enter array size:");
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
		push(arr[i]);
	}
	for(i=0;i<n;i++){
		if(arr[i]!=pop()){
			printf("Its not palidrome.\n");
			return 0;
		}
	}
	printf("Its a palindrome.\n");
}
