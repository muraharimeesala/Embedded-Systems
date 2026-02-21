#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
	struct Node *prev;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory Failed\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	pnew->prev=NULL;
	return pnew;
}
void addNodeAtEnd(struct Node **head,int data){
	struct Node *pnew=createNode(data);
	struct Node *temp=*head;
	if(*head==NULL){
		*head=pnew;
		return;
	}
	while(temp->nxt!=NULL){
		temp=temp->nxt;
	}
	temp->nxt=pnew;
	pnew->prev=temp;
	temp=pnew;
}
void deleteNodeAtHead(struct Node **head){
	struct Node *temp=*head;
	if(*head==NULL){
		return;
	}
	else{
		*head=temp->nxt;
		(*head)->prev=NULL;
	}
	free(temp);
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List Empty.\n");
		exit(1);
	}
	while(temp!=NULL){
		printf("%d<->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int n,i,data;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		addNodeAtEnd(&head,data);
	}
	printf("Original List:\n");
	displayList(head);
	deleteNodeAtHead(&head);
	printf("Updated List:\n");
	displayList(head);
}
