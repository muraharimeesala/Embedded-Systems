#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *top=NULL;
void push(struct Node **top,int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory Allocation Failed.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=*top;
	*top=pnew;
}
void reverseStack(struct Node *top){
	if(top==NULL){
		return;
	}
	reverseStack(top->nxt);
	printf("| %d |\n",top->data);
}
void display(struct Node *top){
	if(top==NULL){
		printf("Stack Empty.\n");
		return;
	}
	struct Node *temp=top;
	while(temp!=NULL){
		printf("| %d |\n",temp->data);
		temp=temp->nxt;
	}
}
int main(){
	struct Node *top=NULL;
	int n,i,data;
	printf("Enter stack size:");
	scanf("%d",&n);
	printf("Enter %d values:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		push(&top,data);
	}
	printf("Original Stack:\n");
	display(top);
	printf("Reversed Stack:\n");
	reverseStack(top);
	printf("Updated Stack:\n");
	display(top);
}
