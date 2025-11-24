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
void dupliRem_sortList(struct Node *head){
	struct Node *curr=head;
	struct Node *nxt_nxt;
	if(curr==NULL){
		return;
	}
	else{
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
	int n,data,i;
	printf("ENter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtTail(&head,data);
	}
	printf("Original List:");
	displayList(head);
	dupliRem_sortList(head);
	printf("After removing the duplicates:");
	displayList(head);
}

