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
	pnew->prev=temp;
	temp->nxt=pnew;
	temp=pnew;
}
void addNodeAtHead(struct Node **head,int newdata){
	struct Node *pnew=createNode(newdata);
	if(*head!=NULL){
		(*head)->prev=pnew;
		pnew->nxt=*head;
	}
	*head=pnew;
}
void displayList(struct Node *head){
	if(head==NULL){
		printf("List Empty.\n");
		exit(1);
	}
	while(head!=NULL){
		printf("%d<->",head->data);
		head=head->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int n,i,data,newdata;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		addNodeAtEnd(&head,data);
	}
	printf("Original List:\n");
	displayList(head);
	printf("Enter node to insert at head:");
	scanf("%d",&newdata);
	addNodeAtHead(&head,newdata);
	printf("Updated List:\n");
	displayList(head);
}
		
