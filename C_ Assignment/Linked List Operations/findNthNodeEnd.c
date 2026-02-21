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
void findNthNodeEnd(struct Node **head,int n){
	struct Node *first=*head,*second=*head;
	int count=0;
	while(count<n){
		if(first==NULL){
			printf("In List fewer %d nodes.\n",n);
			first=first->nxt;
			return;
		}
		first=first->nxt;
		count++;
	}
	while(first!=NULL){
		first=first->nxt;
		second=second->nxt;
	}
	printf("The %dth node from end is:%d",n,second->data);
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
	int n,i,data;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:",n);
	for(i=0;i<n;i++){
		scanf("%d",&data);
		createNodes(&head,data);
	}
	printf("Enter position to find node:");
	scanf("%d",&n);
	printf("Original List:");
	displayList(head);
	findNthNodeEnd(&head,n);
}

