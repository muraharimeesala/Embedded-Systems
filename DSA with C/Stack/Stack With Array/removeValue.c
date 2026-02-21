#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void display();
void push(int value){
	if(top==SIZE-1){
		printf("Stack OverFlow.\n");
	}
	else{
		stack[++top]=value;
		printf("%d Pushed.\n",value);
	}
}
void popParticular(int value){
	int temp[SIZE];
	int tempTop=-1;
	int found=0;
	if(top==-1){
		printf("Stack UnderFlow.\n");
	}
	// Search For Value
	while(top!=-1){
		if(stack[top]==value){
			top--;               // Remove Value
			found=1;
			break;
		}
		else{
			temp[++tempTop]=stack[top--];
		}
	}
	// Restore Remaining Values
	while(tempTop!=-1){
		stack[++top]=temp[tempTop--];
	}
	if(found){
		printf("%d Value is popped from the stack.\n",value);
	}
	else{
		printf("%d vaule is not found in the stack",value);
	}
}
void display(){
	int i;
	if(top==-1){
		printf("Stack Is Empty.\n");
	}
	else{
		for(i=top;i>=0;i--){
			printf("%d ",stack[i]);
		}
	}
	printf("\n");
}
int main(){
	int n,i,value;
	printf("Enter no of values to push(max %d):",SIZE);
	scanf("%d",&n);
	printf("Enter %d values:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&value);
		push(value);
	}
	printf("Initial Stack:\n");
	display();
	printf("Enter value to pop:");
	scanf("%d",&value);
	popParticular(value);
	printf("Updated Stack:\n");
	display();
}
