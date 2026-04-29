#include<stdio.h>
#include<stdlib.h>
#define SIZE 5
int stack[SIZE];
int top=-1;
void push(int value){
	if(top==SIZE-1){
		printf("Stack OverFlow.\n");
		exit(1);
		}
	else{
		stack[++top]=value;
		printf("%d Pushed\n",value);
	}
}
void pop(int value){
	if(top==-1){
		printf("Stack UnderFlow.\n");
		exit(1);
	}
	else{
		value=stack[top--];
		printf("%d Popped\n",value);
	}
}
void display(){
	int i;
	if(top==-1){
		printf("Stack is empty.\n");
	}
	else{
		printf("Stack Elements:\n");
		for(i=top;i>=0;i--){
			printf("%d ",stack[i]);
		}
	}
	printf("\n");
}

int main(){
	int value,n,i;
	printf("Enter no elements to push(%d):",SIZE);
	scanf("%d",&n);
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&value);
		push(value);
	}
	printf("After push operation:\n");
	display();
	printf("Enter no of elements to pop:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		pop(value);
	}
	printf("After push operation:\n");
        display();
}

