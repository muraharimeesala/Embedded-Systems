#include<stdio.h>
#include<stdlib.h>
struct Node{
	struct Node *prev;
	int data;
	struct Node *nxt;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory allocation failed.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->prev=NULL;
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
			pnew->prev=temp;
		}
		temp->nxt=pnew;
	}
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List empty.\n");
	}
	else{
		while(temp!=NULL){
			printf("%d->",temp->data);
			temp=temp->nxt;
		}
		printf("NULL\n");
	}
}
int main(){
	struct Node *head=NULL;
	int n,i,data;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	printf("Original List:");
	displayList(head);
}
