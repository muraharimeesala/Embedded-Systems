
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
int minValue(struct Node *head){
	int min;
	if(head==NULL){
		printf("List is empty.\n");
		return -1;
	}
	min=head->data;
	head=head->nxt;
	while(head!=NULL){
		if(head->data<min){
			min=head->data;
		} 
		head=head->nxt;
	}
	return min;
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
	displayList(head);
	printf("Max value of the Linked List:");
	int Min=minValue(head);
	printf("%d",Min);
}
