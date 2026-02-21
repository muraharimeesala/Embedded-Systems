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
void dupliRemoveUnSortList(struct Node *head){
	struct Node *curr=head;
	struct Node *runner,*dupli;
	while(curr->nxt!=NULL){
		runner=curr;
		while(runner->nxt!=NULL){
			if(runner->nxt->data==curr->data){
				dupli=runner->nxt;
				runner->nxt=runner->nxt->nxt;
				free(dupli);
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
	dupliRemoveUnSortList(head);
	printf("Updated List:");
	displayList(head);
}

