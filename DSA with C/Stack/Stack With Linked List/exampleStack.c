#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *top=NULL;
void push(){
	int value;
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	printf("Enter value to push:");
	scanf("%d",&value);
	pnew->data=value;
	pnew->nxt=top;
	top=pnew;
	printf("%d pushed into stack\n", value);
}
void pop(){
	if(top==NULL){
		printf("Stack UnderFlow.\n");
		exit(1);
	}
	struct Node *temp=top;
	printf("%d Popped from stack,\n",temp->data);
	top=top->nxt;
	free(temp);
}
void peek(){
	if(top==NULL){
		printf("Stack Empty.\n");
	}
	else{
		printf("Top element=%d\n",top->data);
	}
}
void display(){
	if(top==NULL){
		printf("Stack Empty.\n");
		exit(1);
	}
	struct Node *temp=top;
	while(temp!=NULL){
		printf("| %d |\n",temp->data);
		temp=temp->nxt;
	}
}
int main(){
	int choice;
	while(1){
		printf("STACK USING LINKED LIST:\n");
		printf("1 Push.\n");
		printf("2 Pop.\n");
		printf("3 Peek.\n");
		printf("4 Display.\n");
		printf("5 exit.\n");
		printf("Enter choice:");
		scanf("%d",&choice);
		switch(choice){
			case 1:
				push();
				break;
			case 2:
				pop();
				break;
			case 3:
				peek();
				break;
			case 4:
				display();
				break;
			case 5:
				printf("Exiting..\n");
			default:
				printf("Invalid Choice.\n");
		}
	}
}

