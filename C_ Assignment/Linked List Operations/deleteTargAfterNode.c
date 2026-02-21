#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
};
void createNodes(struct Node **head,int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory Error.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	struct Node *temp=*head;
	if(*head==NULL){
		*head=pnew;
		return;
	}
	while(temp->nxt!=NULL){
		temp=temp->nxt;
	}
	temp->nxt=pnew;
}
void deleteTargAfterNode(struct Node **head,int newNode){
	struct Node *temp=*head;
	while(temp!=NULL && temp->data!=newNode){
		temp=temp->nxt;
	}
	if(temp==NULL || temp->nxt==NULL){
		printf("No nodes are exit in the list.\n");
	}
	struct Node *del=temp->nxt;
	temp->nxt=del->nxt;
	printf("Deleted %d after Node %d\n",del->data,newNode);
	free(del);
}
void displayList(struct Node *head){
	struct Node *temp=head;
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
	struct Node *head=NULL;
	int n,i,data,newNode;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		createNodes(&head,data);
	}
	printf("Enter target node:");
	scanf("%d",&newNode);
	printf("Original List:");
	displayList(head);
	deleteTargAfterNode(&head,newNode);
	printf("Updated List:");
	displayList(head);
}
