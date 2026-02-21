#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
	struct Node *prev;
};
void createNodes(struct Node **head,int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory Failed.\n");
		return;
	}
	pnew->data=data;
	pnew->nxt=NULL;
	pnew->prev=NULL;
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
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List is empty.\n");
		return;
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
		createNodes(&head,data);
	}
	printf("Linked List:\n");
	displayList(head);
}
