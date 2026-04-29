#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Failed to allocate memory.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	return pnew;
}
void insertAtTail(struct Node **head,int data){
	struct Node *pnew=createNode(data);
	struct Node *temp=*head;
	if(*head==NULL){
		*head=pnew;
		return;
	}
	while(temp->nxt!=NULL)
		temp=temp->nxt;
	temp->nxt=pnew;
}
void findNthNodeEnd(struct Node *head,int n){
	struct Node *first=head,*second=head;
	int count=0;
	while(count<n){
		if(first==NULL){
			printf("List has fewer of %d nodes.\n",n);
			return;
		}
		first=first->nxt;
		count++;
	}
	while(first!=NULL){
		first=first->nxt;
		second=second->nxt;
	}
	printf("The %dth node from end is :%d\n",n,second->data);
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List is empty.\n");
		return;
	}
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int n,data,i,pos;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtTail(&head,data);
	}
	printf("Linked List:");
	displayList(head);
	printf("Enter position fro end:");
	scanf("%d",&pos);
	findNthNodeEnd(head,pos);
}
