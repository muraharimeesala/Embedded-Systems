
#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory allaction failed.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	return pnew;
}
void insertAtEnd(struct Node **head,int data){
	struct Node *temp=*head;
	struct Node *pnew=createNode(data);
	if(*head==NULL){
	*head=pnew;
	return;
	}
	else{
		while(temp->nxt!=NULL){
			temp=temp->nxt;
		}
		temp->nxt=pnew;
	}
}
struct Node *reverseSecondHalf(struct Node *head){
	if(head==NULL){
		return NULL;
	}
	struct Node *fast=head,*slow=head,*prev=NULL;
	int count=0,i;
	while(fast!=NULL && fast->nxt!=NULL){
		prev=slow;
		slow=slow->nxt;
		fast=fast->nxt->nxt;
	}
	struct Node *curr=slow,*nxt=NULL,*rev=NULL;
	while(curr!=NULL){
		nxt=curr->nxt;
		curr->nxt=rev;
		rev=curr;
		curr=nxt;
	}
	prev->nxt=rev;
	return head;
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List is empty.\n");
	}
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int n,data,i;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	printf("Original list:");
	displayList(head);
	printf("After reversed the first half of list Linked List:");
	head=reverseSecondHalf(head);
	displayList(head);
}
