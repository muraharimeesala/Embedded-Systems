#include<stdio.h>
#include<stdlib.h>
#define SIZE 100
int stack[SIZE];
int top=-1;
void push(int value){
	if(top==SIZE-1){
		printf("Stack OverFLow.\n");
	}
	else{
		printf("Enter value to push:");
		scanf("%d",&value);
		stack[++top]=value;
		printf("%d Pushed\n",value);
		display();
	}
}
void pop(int value){
	if(top==-1){
		printf("Stack UnderFLow.\n");
	}
	else{
		value=stack[top--];
		printf("%d Popped\n",value);
		display();
	}
}
void display(){
	if(top==-1){
		printf("Stack Is Empty.\n");
	}
	else{
		printf("Stack Elements:\n");
		for(int i=top;i>=0;i--){
			printf("%d ",stack[i]);
		}
	}
	printf("\n");
}
int main(){
	int choice,value;
	while(1){
		printf("STACK OPERATIONS:\n");
		printf("1 Push\n");
		printf("2 Pop\n");
		printf("3 Display\n");
		printf("4 Exit\n");
		printf("Enter ur choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push(value);
				break;
			case 2:
				pop(value);
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exiting..");
			default:
				printf("Invalid Choice.\n");
		}
	}
}


