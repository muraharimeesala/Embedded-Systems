#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
struct Node{
	int data;
	struct Node *nxt;
};
struct Node *head=NULL;
struct Node *temp=NULL;
struct Node *pnew;
struct Node *createNodes(int data){
	pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Allocation failed.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	return pnew;
}
int detectLoop(struct Node *head){
	struct Node *slow=head;
	struct Node  *fast=head;
	while(fast!=NULL && fast->nxt!=NULL){
		slow=slow->nxt;
		fast=fast->nxt->nxt;
	}
	if(slow==fast){
		printf("Loop detect\n");
	}
	return 0;

}
int display(struct Node *head){
	temp=head;
	if(head==NULL){
		printf("List empty.\n");
		exit(1);
	}
	while(temp!=NULL){
		printf("%d->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
	int n,i,data;
	printf("Enter list size:");
	scanf("%d",&n);
	printf("Enter %d nodes:\n",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		pnew=createNodes(data);
		temp=head;
		if(head==NULL){
			printf("List empty.\n");
			exit(1);
		}
	       	while(temp->nxt!=NULL){
		       	temp=temp->nxt;
		}
		temp->nxt=pnew;
	}
	display(head);
	detectLoop(head);
}
