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
void dupliRemoveSortList(struct Node *head){
	struct Node *curr=head;
	struct Node *nxt_nxt;
	while(curr->nxt!=NULL){
		if(curr->data==curr->nxt->data){
			nxt_nxt=curr->nxt->nxt;
			free(curr->nxt);
			curr->nxt=nxt_nxt;
		}
		else{
			curr=curr->nxt;
		}
	}
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
	printf("Original List:");
	displayList(head);
	dupliRemoveSortList(head);
	printf("Updated List:");
	displayList(head);
}

