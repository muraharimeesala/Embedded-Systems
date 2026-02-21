#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
void push(struct Node **top,int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory Allocation Failed.\n");
		return;
	}
	pnew->data=data;
	pnew->nxt=*top;
	*top=pnew;
}
void pop(struct Node **top){
	if(*top==NULL){
		printf("Stack Empty.\n");
		return;
	}
	struct Node *temp=*top;
	printf("%d Popped from stack.\n",temp->data);
	*top=temp->nxt;
	free(temp);
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
	printf("Enter size of stack:");
	scanf("%d",&n);
	printf("Enter %d values:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		push(&top,data);
	}
	printf("Original Stack:\n");
	display(top);
	pop(&top);
	printf("Updated Stack:\n");
	display(top);
}

