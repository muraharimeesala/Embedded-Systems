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
	pnew->nxt=NULL;
	struct Node *tail=*head;
	if(*head==NULL){
		*head=pnew;
		return;
	}
	while(tail->nxt!=NULL){
		tail=tail->nxt;
	}
	tail->nxt=pnew;
	pnew->prev=tail;
	tail=pnew;
}
void displayList(struct Node *head){
	struct Node *tail=head;
	if(head==NULL){
		printf("List Empty.\n");
		return;
	}
	while(tail!=NULL){
		printf("%d<->",tail->data);
		tail=tail->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL,*tail;
	int n,i,data,newdata;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		createNodes(&head,data);
	}
	printf("Original List:\n");
	displayList(head);
	printf("Enter node to insert at end:");
	scanf("%d",&newdata);
	createNodes(&head,newdata);
	printf("Updated List:\n");
	displayList(head);
}
