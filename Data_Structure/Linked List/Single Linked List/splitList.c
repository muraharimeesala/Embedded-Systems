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
	if(*head==NULL){
		*head=pnew;
		return;
	}
	struct Node *temp=*head;
	while(temp->nxt!=NULL)
	temp=temp->nxt;
	temp->nxt=pnew;
}
void splitList(struct Node *head,struct Node **firstHalf,struct Node **secondHalf){
	if(head==NULL || head->nxt==NULL){
		*firstHalf=head;
		*secondHalf=NULL;
		return;
	}
	struct Node *slow=head;
	struct Node *fast=head->nxt;
	while(fast!=NULL && fast->nxt!=NULL){
		slow=slow->nxt;
		fast=fast->nxt->nxt;
	}
	//split two lists
	*firstHalf=head;
	*secondHalf=slow->nxt;
	slow->nxt=NULL;
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
	struct Node *firstHalf=NULL;
	struct Node *secondHalf=NULL;
	int n,i,data;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter valueof %d node:",i);
		scanf("%d",&data);
		insertAtTail(&head,data);
	}
	printf("Original List:");
	displayList(head);
	splitList(head,&firstHalf,&secondHalf);
	printf("FirstHalf List:");
	displayList(firstHalf);
	printf("SecondHalf List:");
	displayList(secondHalf);
}
