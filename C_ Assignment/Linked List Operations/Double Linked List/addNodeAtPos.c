#include<stdio.h>
#include<stdlib.h>
struct Node{
	int data;
	struct Node *nxt;
	struct Node *prev;
};
struct Node *createNode(int data){
	struct Node *pnew=(struct Node*)malloc(sizeof(struct Node));
	if(pnew==NULL){
		printf("Memory Allocation Failed.\n");
		exit(1);
	}
	pnew->data=data;
	pnew->nxt=NULL;
	pnew->prev=NULL;
	return pnew;
}
void addNodeAtPos(struct Node **head,int data,int pos){
	struct Node *pnew=createNode(data);
	int i;
	if(pos==1){
		if(*head!=NULL){
			(*head)->prev=pnew;
			pnew->nxt=*head;
		}
		*head=pnew;
		return;
	}
	struct Node *temp=*head;
	for(i=1;i<pos-1&&temp!=NULL;i++){
		temp=temp->nxt;
	}
	if(temp==NULL){
		return;
	}
	pnew->nxt=temp->nxt;
	pnew->prev=temp;
	temp->nxt->prev=pnew;
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List Empty.\n");
		exit(1);
	}
	while(temp!=NULL){
		printf("%d<->",temp->data);
		temp=temp->nxt;
	}
	printf("NULL\n");
}
int main(){
	struct Node *head=NULL;
	int n,i,data,newdata,pos;
	printf("Enter no of nodes:");
	scanf("%d",&n);
	printf("Enter %d nodes:\n",n);
	for(i=1;i<=n;i++){
		scanf("%d",&data);
		addNodeAtPos(&head,data,i);
	}
	printf("Original List:\n");
	displayList(head);
	printf("Enter node to insert at position:");
	scanf("%d",&newdata);
	printf("Enter position to insert node:");
	scanf("%d",&pos);
	addNodeAtPos(&head,newdata,pos);
	displayList(head);
}
