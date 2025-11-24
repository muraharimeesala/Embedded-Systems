
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
struct Node *rotateRightKth(struct Node *head,int k){
        if(!head || k==0){
	return head;
	}
	struct Node *temp=head;
	int len=1;
	while(temp->nxt!=NULL){
		temp=temp->nxt;
		len++;
	}
	temp->nxt=head;
	k=k%len;
	int steps=len-k;
	while(steps--)
		temp=temp->nxt;
	head=temp->nxt;
	temp->nxt=NULL;
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
	int n,data,i,k;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtEnd(&head,data);
	}
	printf("Enter positions to rotate:");
	scanf("%d",&k);
	printf("Original list:");
	displayList(head);
	printf("After right rotation of list Linked List:");
	head=rotateRightKth(head,k);
	displayList(head);
}
