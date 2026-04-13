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
void dupliRem_unsortList(struct Node *head){
	struct Node *curr=head;
	struct Node *runner,*dup;
	while(curr!=NULL && curr->nxt!=NULL){
		runner=curr;
		while(runner->nxt!=NULL){
			if(runner->nxt->data==curr->data){
				dup=runner->nxt;
				runner->nxt=runner->nxt->nxt;
				free(dup);
			}
			else{
				runner=runner->nxt;
			}
		}
		curr=curr->nxt;
	}
}
void displayList(struct Node *head){
	struct Node *temp=head;
	if(head==NULL){
		printf("List is Empty.\n");
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
	printf("Enter no of nodes:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		printf("Enter value of %d node:",i);
		scanf("%d",&data);
		insertAtTail(&head,data);
	}
	printf("Original List:");
	displayList(head);
	dupliRem_unsortList(head);
	printf("After removing duplicates from unsorted List:");
	displayList(head);
}
